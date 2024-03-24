#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"

void JcIndexUp(int data_len,
               float* pfOUT,
               float* pfINa,  // close
               JCJArray* out_ddhdisspear,
               JCJArray* out_bg10_disspear,
               JCJArray* out_bg7_disspear,
               JCJArray* out_b,
               JCJArray* out_bg7_draw,
               JCJArray* out_bg10_draw) {
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

  // MN1:=REF(M1,N1)+N1;{最近一次死叉之前的金叉}
  JCJArray mn1 = JCJRef(m1, n1) + n1;

  // CL1:=LLV(C,N1+1);{最近一次死叉后，最低收盘价}
  JCJArray cl1 = JCJLLV(close, n1 + 1);

  // CL2:=REF(CL1,MN1);{前二低点（左谷）股价}
  JCJArray cl2 = JCJRef(cl1, mn1);
  // CL3:=REF(CL1,REF(MN1,MN1)+MN1);{前三低点（左隔谷）收盘价}
  JCJArray cl3 = JCJRef(cl1, JCJRef(mn1, mn1) + mn1);
  // DL1:=LLV(DIF,N1+1); {最近一次死叉后，最低DIF值}
  JCJArray dl1 = JCJLLV(dif, n1 + 1);

  // DL2:=REF(DL1,MN1);{前二低点（左谷）DIF值}
  JCJArray dl2 = JCJRef(dl1, mn1);
  // DL3:=REF(DL1,REF(MN1,MN1)+MN1);{前三低点（左隔谷）DIF值}
  JCJArray dl3 = JCJRef(dl1, JCJRef(mn1, mn1) + mn1);
  // 隔峰底:=(CL3>CL1 AND CL2>CL1 AND DL3<DL1 AND DL3<DL2);
  JCJArray ge_feng_di = cl3 > cl1 && cl2 > cl1 && dl3 < dl1 && dl3 < dl2;

  // 临峰底:=CL2>CL1 AND DL2<DL1 AND NOT(隔峰底);
  JCJArray lin_feng_di = cl2 > cl1 && dl2 < dl1 && JCJNot(ge_feng_di);
  // 直接底钝化:=临峰底 AND (MACD<0 AND REF(MACD,1)<0) AND DIF<=REF(DIF,1);
  JCJArray zjddh =
      lin_feng_di && (macd < 0 && JCJRef(macd, 1) < 0) && dif <= JCJRef(dif, 1);
  // 隔峰底钝化:=隔峰底 AND (MACD<0 AND REF(MACD,1)<0) AND DIF<=REF(DIF,1);
  JCJArray gfddh =
      ge_feng_di && (macd < 0 && JCJRef(macd, 1) < 0) && dif <= JCJRef(dif, 1);
  // B:=直接底钝化 OR 隔峰底钝化;
  JCJArray b = zjddh || gfddh;

  // BT:=BARSLAST(B)+1;
  JCJArray bt = JCJBarsLast(b) + 1;
  // BG71:=DIF>REF(DIF,1) AND DIF<DEA AND REF(B,1);
  JCJArray bg71 = dif > JCJRef(dif, 1) && dif < dea && JCJRef(b, 1);
  // BG7:=BG71 AND COUNT(BG71,BARSLAST(CL1<>REF(CL1,1)))=1;
  JCJArray bg7 =
      bg71 && JCJCount(bg71, JCJBarsLast(cl1 != JCJRef(cl1, 1))) == 1;
  // BG10:=CROSS(DIF,DEA) AND MACD>=0 AND (临峰底 OR 隔峰底) AND
  // COUNT(CROSS(DIF,DEA),BT)=1;
  JCJArray bg10 = JCJCross(dif, dea) && macd >= 0 &&
                  (lin_feng_di || ge_feng_di) &&
                  JCJCount(JCJCross(dif, dea), bt) == 1;
  // BG:=BG7 OR BG10;{这里没有用}
  // BG10T:=BARSLAST(BG10)+1;
  JCJArray bg10t = JCJBarsLast(bg10) + 1;
  // RCL1:=REF(CL1,BG10T);
  JCJArray rcl1 = JCJRef(cl1, bg10t);
  // BG10消失:=CROSS(RCL1,C) AND COUNT(CROSS(RCL1,C),BG10T)=1;{当B=1 且
  // (BG10消失或BG7消失) 只画B=1的信号}
  JCJArray bg10_disspear =
      JCJCross(rcl1, close) && JCJCount(JCJCross(rcl1, close), bg10t) == 1;
  // BG7T:=BARSLAST(BG7);

  JCJArray bg7t = JCJBarsLast(bg7);
  // BG7消失:=BG7T>0 AND DIF<REF(DIF,1) AND COUNT(DIF<REF(DIF,1),BG7T)=1 AND
  // COUNT(CROSS(DIF,DEA),BG7T)=0;
  JCJArray bg7_disspear = bg7t > 0 && dif < JCJRef(dif, 1) &&
                          JCJCount(dif < JCJRef(dif, 1), bg7t) == 1 &&
                          JCJCount(JCJCross(dif, dea), bg7t) == 0;
  // BG7画图:=BG7 AND COUNT(BG7消失,N1+1)=0;
  JCJArray bg7_draw = bg7 && JCJCount(bg7_disspear, n1 + 1) == 0;
  // BG101:=BG10 AND COUNT(BG7,N1+1)=0 AND COUNT(BG10,N1+1)=1;
  JCJArray bg101 =
      bg10 && JCJCount(bg7, n1 + 1) == 0 && JCJCount(bg10, n1 + 1) == 1;
  // BG102:=BG10 AND COUNT(BG7消失,N1+1)=1 AND COUNT(BG10,N1+1)=1;
  JCJArray bg102 = bg10 && JCJCount(bg7_disspear, n1 + 1) == 1 &&
                   JCJCount(bg10, n1 + 1) == 1;

  // BG10画图:=BG101 OR BG102;
  JCJArray bg10_draw = bg101 || bg102;
  // 隔底钝化消失:=REF(隔峰底钝化,1) AND DL1<=DL3;
  JCJArray gddh_disspear = JCJRef(gfddh, 1) && dl1 <= dl3;
  // 直底钝化消失:=REF(直接底钝化,1) AND DL1<=DL2;
  JCJArray zddh_disspear = JCJRef(zjddh, 1) && dl1 <= dl2;
  // 底钝化消失:=隔底钝化消失 OR 直底钝化消失;
  JCJArray ddh_disspear = gddh_disspear || zddh_disspear;

  ddh_disspear.MemCopyTo(out_ddhdisspear->multable_data());
  bg10_disspear.MemCopyTo(out_bg10_disspear->multable_data());
  bg7_disspear.MemCopyTo(out_bg7_disspear->multable_data());
  b.MemCopyTo(out_b->multable_data());
  bg7_draw.MemCopyTo(out_bg7_draw->multable_data());
  bg10_draw.MemCopyTo(out_bg10_draw->multable_data());
}

void DrawXJT(int data_len, float* pfOUT, float* pfINa) {
  JCJArray ddh_disspear(data_len);
  JCJArray bg10_disspear(data_len);
  JCJArray bg7_disspear(data_len);
  JCJArray b(data_len);
  JCJArray bg7_draw(data_len);
  JCJArray bg10_draw(data_len);

  JcIndexUp(data_len, pfOUT, pfINa, &ddh_disspear, &bg10_disspear,
            &bg7_disspear, &b, &bg7_draw, &bg10_draw);

  // 底钝化消失 OR ((BG10消失 OR BG7消失) AND NOT(B))
  JCJArray result =
      ddh_disspear || ((bg10_disspear || bg7_disspear) && JCJNot(b));
  result.MemCopyTo(pfOUT);
}

void DrawF1(int data_len, float* pfOUT, float* pfINa) {
  // DRAWBMP(B,(LLV(LOW,10) * 0.98),'F1'),COLORYELLOW;
  JCJArray dhddisspear(data_len);
  JCJArray bg10_disspear(data_len);
  JCJArray bg7_disspear(data_len);
  JCJArray b(data_len);
  JCJArray bg7_draw(data_len);
  JCJArray bg10_draw(data_len);

  JcIndexUp(data_len, pfOUT, pfINa, &dhddisspear, &bg10_disspear, &bg7_disspear,
            &b, &bg7_draw, &bg10_draw);
  b.MemCopyTo(pfOUT);
}

void DrawSJT(int data_len, float* pfOUT, float* pfINa) {
  // DRAWBMP(BG7画图 OR BG10画图,(LLV(LOW,10) * 0.98),'SJT');
  JCJArray dhddisspear(data_len);
  JCJArray bg10_disspear(data_len);
  JCJArray bg7_disspear(data_len);
  JCJArray b(data_len);
  JCJArray bg7_draw(data_len);
  JCJArray bg10_draw(data_len);

  JcIndexUp(data_len, pfOUT, pfINa, &dhddisspear, &bg10_disspear, &bg7_disspear,
            &b, &bg7_draw, &bg10_draw);
  JCJArray result = bg7_draw || bg10_draw;
  result.MemCopyTo(pfOUT);
}
