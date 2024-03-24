#include "jdxj_down.h"
#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"

void JcIndexDown(int data_len,
                 float* pfOUT,
                 float* pfINa,  // close
                 JCJArray* out_ddhdisspear,
                 JCJArray* out_tg10_disspear,
                 JCJArray* out_tg7_disspear,
                 JCJArray* out_t,
                 JCJArray* out_tg7_draw,
                 JCJArray* out_tg10_draw) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;

  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;

  // DEA:=EMA(DIF,9);
  JCJArray dea = JCJEMA(dif, 9);

  // MACD:=(DIF-DEA)*2,COLORSTICK;
  JCJArray macd = (dif - dea) * 2;

  // 死叉:=CROSS(DEA,DIF) AND REF(MACD,1)>0 AND REF(MACD,2)>0;
  JCJArray dead_cross =
      JCJCross(dea, dif) && JCJRef(macd, 1) > 0 && JCJRef(macd, 2) > 0;

  // N1:=BARSLAST(死叉);{最近一次死叉的位置}
  JCJArray n1 = JCJBarsLast(dead_cross);

  // 金叉:=CROSS(DIF,DEA) AND REF(MACD,1)<0 AND REF(MACD,2)<0;
  JCJArray gold_cross =
      JCJCross(dif, dea) && JCJRef(macd, 1) < 0 && JCJRef(macd, 2) < 0;

  // M1:=BARSLAST(金叉);{最近一次金叉的位置}
  JCJArray m1 = JCJBarsLast(gold_cross);

  // 下半部分正式开始

  // M2:=REF(BARSLAST(金叉),M1+1);{倒数第二次金叉与倒数第一次金叉的区间}
  JCJArray m2 = JCJRef(JCJBarsLast(gold_cross), m1 + 1);

  // M3:=REF(BARSLAST(金叉),M2+M1+2);{倒数第三次金叉与倒数第二次金叉的区间}
  JCJArray m3 = JCJRef(JCJBarsLast(gold_cross), m2 + m1 + 2);

  // 最近死叉位置的，最后一次金叉以来的最高值
  JCJArray nm1 = JCJRef(n1, m1) + m1;

  // CH1:=HHV(C,M1+1);{最近一次金叉后，最高收盘价}
  JCJArray ch1 = JCJHHV(close, m1 + 1);

  // CH2:=REF(CH1,NM1);{前二高点（左峰）股价}
  JCJArray ch2 = JCJRef(ch1, nm1);

  // CH3:=REF(CH1,REF(NM1,NM1)+NM1);{前三高点（左隔峰）收盘价}
  JCJArray ch3 = JCJRef(ch1, JCJRef(nm1, nm1) + nm1);

  // DH1:=HHV(DIF,M1+1); {最近一次金叉后，最高DIF值}
  JCJArray dh1 = JCJHHV(dif, m1 + 1);

  // DH2:=REF(DH1,NM1);{前二高点（左峰）DIF值}
  JCJArray dh2 = JCJRef(dh1, nm1);

  // DH3:=REF(DH1,REF(NM1,NM1)+NM1);{前三高点（左隔峰）DIF值}
  JCJArray dh3 = JCJRef(dh1, JCJRef(nm1, nm1) + nm1);

  // 隔峰顶:=(CH3<CH1 AND CH2<CH1 AND DH3>DH1 AND DH3>DH2);
  JCJArray ge_feng_ding = ch3 < ch1 && ch2 < ch1 && dh3 > dh1 && dh3 > dh2;

  // 临峰顶:=CH2<CH1 AND DH2>DH1 AND NOT(隔峰顶);
  JCJArray lin_feng_ding = ch2 < ch1 && dh2 > dh1 && !ge_feng_ding;

  // 直接顶钝化:=临峰顶 AND (MACD>0 AND REF(MACD,1)>0) AND DIF>=REF(DIF,1);
  JCJArray zjddh = lin_feng_ding && (macd > 0 && JCJRef(macd, 1) > 0) &&
                   dif >= JCJRef(dif, 1);

  // 隔峰顶钝化:=隔峰顶 AND (MACD>0 AND REF(MACD,1)>0) AND DIF>=REF(DIF,1);
  JCJArray gfddh = ge_feng_ding && (macd > 0 && JCJRef(macd, 1) > 0) &&
                   dif >= JCJRef(dif, 1);

  // T:=直接顶钝化 OR 隔峰顶钝化;
  JCJArray t = zjddh || gfddh;

  // TT:=BARSLAST(T)+1;
  JCJArray tt = JCJBarsLast(t) + 1;

  // TG71:=DIF<REF(DIF,1) AND DIF>DEA AND REF(T,1);
  JCJArray tg71 = dif < JCJRef(dif, 1) && dif > dea && JCJRef(t, 1);

  // TG7:=TG71 AND COUNT(TG71,BARSLAST(CH1<>REF(CH1,1)))=1;
  JCJArray tg7 =
      tg71 && JCJCount(tg71, JCJBarsLast(ch1 != JCJRef(ch1, 1))) == 1;

  // TG10:=CROSS(DEA,DIF) AND (临峰顶 OR 隔峰顶) AND COUNT(CROSS(DEA,DIF),TT)=1;
  JCJArray tg10 = JCJCross(dea, dif) && (lin_feng_ding || ge_feng_ding) &&
                  JCJCount(JCJCross(dea, dif), tt) == 1;

  // TG10T:=BARSLAST(TG10)+1;
  JCJArray tg10t = JCJBarsLast(tg10) + 1;

  // RCH1:=REF(CH1,TG10T);
  JCJArray rch1 = JCJRef(ch1, tg10t);

  // TG10消失:=CROSS(C,RCH1) AND COUNT(CROSS(C,RCH1),TG10T)=1;{当T=1 且
  // (TG10消失或TG7消失) 只画T=1的信号}
  JCJArray tg10_disappear =
      JCJCross(close, rch1) && JCJCount(JCJCross(close, rch1), tg10t) == 1;

  // TG7T:=BARSLAST(TG7);
  JCJArray tg7t = JCJBarsLast(tg7);

  // TG7消失:=TG7T>0 AND DIF>REF(DIF,1) AND COUNT(DIF>REF(DIF,1),TG7T)=1 AND
  // COUNT(CROSS(DEA,DIF),TG7T)=0;
  JCJArray tg7_disappear = tg7t > 0 && dif > JCJRef(dif, 1) &&
                           JCJCount(dif > JCJRef(dif, 1), tg7t) == 1 &&
                           JCJCount(JCJCross(dea, dif), tg7t) == 0;

  // TG7画图:=TG7 AND  COUNT(TG7消失,M1+1)=0;
  JCJArray tg7_draw = tg7 && JCJCount(tg7_disappear, m1 + 1) == 0;

  // TG101:=TG10 AND COUNT(TG7,M1+1)=0 AND COUNT(TG10,M1+1)=1;
  JCJArray tg101 =
      tg10 && JCJCount(tg7, m1 + 1) == 0 && JCJCount(tg10, m1 + 1) == 1;

  // TG102:=TG10 AND COUNT(TG7消失,M1+1)=1 AND COUNT(TG10,M1+1)=1;
  JCJArray tg102 = tg10 && JCJCount(tg7_disappear, m1 + 1) == 1 &&
                   JCJCount(tg10, m1 + 1) == 1;

  // TG10画图:=TG101 OR TG102;
  JCJArray tg10_draw = tg101 || tg102;

  // 隔顶钝化消失:=REF(隔峰顶钝化,1) AND DH1>=DH3;
  JCJArray gddh_disappear = JCJRef(gfddh, 1) && dh1 >= dh3;

  // 直顶钝化消失:=REF(直接顶钝化,1) AND DH1>=DH2;
  JCJArray zddh_disappear = JCJRef(zjddh, 1) && dh1 >= dh2;

  // 顶钝化消失:=隔顶钝化消失 OR 直顶钝化消失;
  JCJArray ddh_disappear = gddh_disappear || zddh_disappear;

  ddh_disappear.MemCopyTo(out_ddhdisspear->multable_data());
  tg10_disappear.MemCopyTo(out_tg10_disspear->multable_data());
  tg7_disappear.MemCopyTo(out_tg7_disspear->multable_data());
  t.MemCopyTo(out_t->multable_data());
  tg7_draw.MemCopyTo(out_tg7_draw->multable_data());
  tg10_draw.MemCopyTo(out_tg10_draw->multable_data());
}

void DDXJDownDrawSJT(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*) {
  // DRAWBMP(顶钝化消失 OR ((TG10消失 OR TG7消失) AND NOT(T)),(HIGH
  // * 1.03),'SJT');
  JCJArray ddh_disspear(data_len);
  JCJArray tg10_disspear(data_len);
  JCJArray tg7_disspear(data_len);
  JCJArray t(data_len);
  JCJArray tg7_draw(data_len);
  JCJArray tg10_draw(data_len);
  JcIndexDown(data_len, pfOUT, pfINa, &ddh_disspear, &tg10_disspear,
              &tg7_disspear, &t, &tg7_draw, &tg10_draw);

  JCJArray result = ddh_disspear || ((tg10_disspear || tg7_disspear) && !t);
  result.MemCopyTo(pfOUT);
}

void DDXJDownDrawY(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*) {
  // DRAWBMP(T,(HHV(HIGH,10) * 1.03),'Y'),COLORYELLOW;
  JCJArray ddh_disspear(data_len);
  JCJArray tg10_disspear(data_len);
  JCJArray tg7_disspear(data_len);
  JCJArray t(data_len);
  JCJArray tg7_draw(data_len);
  JCJArray tg10_draw(data_len);
  JcIndexDown(data_len, pfOUT, pfINa, &ddh_disspear, &tg10_disspear,
              &tg7_disspear, &t, &tg7_draw, &tg10_draw);
  t.MemCopyTo(pfOUT);
}

void DDXJDownDrawXJT(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*) {
  // DRAWBMP(TG7画图 OR TG10画图,(HHV(HIGH,10) * 1.03),'XJT');
  JCJArray ddh_disspear(data_len);
  JCJArray tg10_disspear(data_len);
  JCJArray tg7_disspear(data_len);
  JCJArray t(data_len);
  JCJArray tg7_draw(data_len);
  JCJArray tg10_draw(data_len);
  JcIndexDown(data_len, pfOUT, pfINa, &ddh_disspear, &tg10_disspear,
              &tg7_disspear, &t, &tg7_draw, &tg10_draw);

  JCJArray result = tg7_draw || tg10_draw;
  result.MemCopyTo(pfOUT);
}

