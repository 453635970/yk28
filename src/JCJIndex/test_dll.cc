#include "test_dll.h"
#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"
#include "jdxj_down.h"

void TestAbs(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*) {
  JCJArray open(data_len, pfInOpen);
  JCJArray high(data_len, pfInHigh);
  JCJArray low(data_len, pfInLow);
  JCJArray close(data_len, pfInClose);
  // XIAO1:=REF((LOW+OPEN+CLOSE+HIGH)/4,1);
  JCJArray xiao1 = JCJRef((low + open + close + high) / 4, 1);
  // XIAO2:=SMA(ABS(LOW-XIAO1),11,1)/SMA(MAX(LOW-XIAO1,0),10,1);
  JCJArray xiao2 = JCJAbs(low - xiao1);

  xiao2.MemCopyTo(pfOUT);
}

void TestSMA(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*) {
  JCJArray open(data_len, pfInOpen);
  JCJArray high(data_len, pfInHigh);
  JCJArray low(data_len, pfInLow);
  JCJArray close(data_len, pfInClose);
  // XIAO1:=REF((LOW+OPEN+CLOSE+HIGH)/4,1);
  JCJArray xiao1 = JCJRef((low + open + close + high) / 4, 1);
  // XIAO2:=SMA(ABS(LOW-XIAO1),11,1)/SMA(MAX(LOW-XIAO1,0),10,1);
  JCJArray xiao2 = JCJSMA(JCJMax(low - xiao1, 0), 10, 1);
  // JCJArray xiao2 = JCJSMA(JCJAbs(low-xiao1), 11, 1);

  xiao2.MemCopyTo(pfOUT);
}

void TestMAX(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*) {
  JCJArray open(data_len, pfInOpen);
  JCJArray high(data_len, pfInHigh);
  JCJArray low(data_len, pfInLow);
  JCJArray close(data_len, pfInClose);
  // XIAO1:=REF((LOW+OPEN+CLOSE+HIGH)/4,1);
  JCJArray xiao1 = JCJRef((low + open + close + high) / 4, 1);
  // XIAO2:=SMA(ABS(LOW-XIAO1),11,1)/SMA(MAX(LOW-XIAO1,0),10,1);
  JCJArray xiao2 = JCJMax(low - xiao1, 0);

  xiao2.MemCopyTo(pfOUT);
}

void TestXiao2(int data_len,
               float* pfOUT,
               float* pfInOpen,
               float* pfInHigh,
               float* pfInLow,
               float* pfInClose,
               float*) {
  JCJArray open(data_len, pfInOpen);
  JCJArray high(data_len, pfInHigh);
  JCJArray low(data_len, pfInLow);
  JCJArray close(data_len, pfInClose);
  // XIAO1:=REF((LOW+OPEN+CLOSE+HIGH)/4,1);
  JCJArray xiao1 = JCJRef((low + open + close + high) / 4, 1);
  // XIAO2:=SMA(ABS(LOW-XIAO1),11,1)/SMA(MAX(LOW-XIAO1,0),10,1);
  JCJArray xiao2 = JCJSMA(JCJAbs(low - xiao1), 11, 1) /
                   JCJSMA(JCJMax(low - xiao1, 0), 10, 1);
  xiao2.MemCopyTo(pfOUT);
}

void TestIf(int data_len,
            float* pfOUT,
            float* pfInOpen,
            float* pfInHigh,
            float* pfInLow,
            float* pfInClose,
            float*) {
  JCJArray open(data_len, pfInOpen);
  JCJArray high(data_len, pfInHigh);
  JCJArray low(data_len, pfInLow);
  JCJArray close(data_len, pfInClose);
  // XIAO1:=REF((LOW+OPEN+CLOSE+HIGH)/4,1);
  JCJArray xiao1 = JCJRef((low + open + close + high) / 4, 1);
  // XIAO2:=SMA(ABS(LOW-XIAO1),11,1)/SMA(MAX(LOW-XIAO1,0),10,1);
  JCJArray xiao2 = JCJSMA(JCJAbs(low - xiao1), 11, 1) /
                   JCJSMA(JCJMax(low - xiao1, 0), 10, 1);
  // XIAO3:=EMA(XIAO2,20);
  JCJArray xiao3 = JCJEMA(xiao2, 20);
  // XIAO4:=LLV(LOW,120);
  JCJArray xiao4 = JCJLLV(low, 120);
  // XIAO5:=EMA(IF(LOW<=XIAO4,XIAO3,0),3);
  JCJArray out = JCJIf(low <= xiao4, xiao3, 0);

  out.MemCopyTo(pfOUT);
}

void TestDDHDisspear(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray ddh_disspear(data_len);
  JCJArray tg10_disspear(data_len);
  JCJArray tg7_disspear(data_len);
  JCJArray t(data_len);
  JCJArray tg7_draw(data_len);
  JCJArray tg10_draw(data_len);
  JcIndexDown(data_len, pfOUT, pfINa, &ddh_disspear, &tg10_disspear,
              &tg7_disspear, &t, &tg7_draw, &tg10_draw);
  ddh_disspear.MemCopyTo(pfOUT);
}

void TestT(int data_len,
           float* pfOUT,
           float* pfINa,
           float*,
           float*,
           float*,
           float*) {
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

void TestGFDDH(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*) {
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

  gfddh.MemCopyTo(pfOUT);
}

void TestDH1_GEQ_DH3(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*) {
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
                           JCJCount(dif < JCJRef(dif, 1), tg7t) == 1 &&
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
  JCJArray result = dh1 >= dh3;
  result.MemCopyTo(pfOUT);
}

void TestRefGFDDH(int data_len,
                  float* pfOUT,
                  float* pfINa,
                  float*,
                  float*,
                  float*,
                  float*) {
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
                           JCJCount(dif < JCJRef(dif, 1), tg7t) == 1 &&
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

  // 隔顶钝化消失:=REF(隔峰顶钝化,1)
  JCJArray result = JCJRef(gfddh, 1);
  result.MemCopyTo(pfOUT);
}

void TestD9(int data_len,
            float* pfOUT,
            float* pfInClose,
            float* pfInN,
            float*,
            float*,
            float*) {
  JCJArray close(data_len, pfInClose);
  JCJArray n(data_len, pfInN);

  JCJArray isLastBar(data_len, 0.0);
  isLastBar.multable_data()[data_len - 1] = 1.0;

  // TJ:=C>REF(C,4);
  JCJArray tj = close > JCJRef(close, 4);

  // CL:=C<REF(C,4);
  JCJArray cl = close < JCJRef(close, 4);

  // JL:=BARSLAST(TJ);
  JCJArray jl = JCJBarsLast(tj);

  // D1:=JL=1 AND CL;
  JCJArray d1 = jl == 1 && cl;

  // D2:=JL=2 AND CL AND REF(D1,1);
  JCJArray d2 = jl == 2 && cl && JCJRef(d1, 1);

  // D3:=JL=3 AND CL AND REF(D2,1);
  JCJArray d3 = jl == 3 && cl && JCJRef(d2, 1);

  // D4:=JL=4 AND CL AND REF(D3,1);
  JCJArray d4 = jl == 4 && cl && JCJRef(d3, 1);

  // D5:=JL=5 AND CL AND REF(D4,1);
  JCJArray d5 = jl == 5 && cl && JCJRef(d4, 1);

  // D6:=JL=6 AND CL AND REF(D5,1);
  JCJArray d6 = jl == 6 && cl && JCJRef(d5, 1);

  // D7:=JL=7 AND CL AND REF(D6,1);
  JCJArray d7 = jl == 7 && cl && JCJRef(d6, 1);

  // D8:=JL=8 AND CL AND REF(D7,1);
  JCJArray d8 = jl == 8 && cl && JCJRef(d7, 1);

  // D9:=JL=9 AND CL AND REF(D8,1);
  JCJArray d9 = jl == 9 && cl && JCJRef(d8, 1);

  d9.MemCopyTo(pfOUT);
}

void TestCG(int data_len,
            float* pfOUT,
            float* pfInClose,
            float* pfInN,
            float*,
            float*,
            float*) {
  JCJArray close(data_len, pfInClose);
  JCJArray n(data_len, pfInN);

  JCJArray isLastBar(data_len, 0.0);
  isLastBar.multable_data()[data_len - 1] = 1.0;

  // TJ:=C>REF(C,4);
  JCJArray tj = close > JCJRef(close, 4);

  // CL:=C<REF(C,4);
  JCJArray cl = close < JCJRef(close, 4);

  // JL:=BARSLAST(TJ);
  JCJArray jl = JCJBarsLast(tj);

  // D1:=JL=1 AND CL;
  JCJArray d1 = jl == 1 && cl;

  // D2:=JL=2 AND CL AND REF(D1,1);
  JCJArray d2 = jl == 2 && cl && JCJRef(d1, 1);

  // D3:=JL=3 AND CL AND REF(D2,1);
  JCJArray d3 = jl == 3 && cl && JCJRef(d2, 1);

  // D4:=JL=4 AND CL AND REF(D3,1);
  JCJArray d4 = jl == 4 && cl && JCJRef(d3, 1);

  // D5:=JL=5 AND CL AND REF(D4,1);
  JCJArray d5 = jl == 5 && cl && JCJRef(d4, 1);

  // D6:=JL=6 AND CL AND REF(D5,1);
  JCJArray d6 = jl == 6 && cl && JCJRef(d5, 1);

  // D7:=JL=7 AND CL AND REF(D6,1);
  JCJArray d7 = jl == 7 && cl && JCJRef(d6, 1);

  // D8:=JL=8 AND CL AND REF(D7,1);
  JCJArray d8 = jl == 8 && cl && JCJRef(d7, 1);

  // D9:=JL=9 AND CL AND REF(D8,1);
  JCJArray d9 = jl == 9 && cl && JCJRef(d8, 1);

  // CG:=(ISLASTBAR=1 AND D1) OR BACKSET(ISLASTBAR=1 AND D2,2) OR
  //    BACKSET(ISLASTBAR=1 AND D3,3) OR BACKSET(ISLASTBAR=1 AND D4,4) OR
  //    BACKSET(ISLASTBAR=1 AND D5,5) OR BACKSET(ISLASTBAR=1 AND D6,6) OR
  //    BACKSET(ISLASTBAR=1 AND D7,7) OR BACKSET(ISLASTBAR=1 AND D8,8) OR
  //    BACKSET(D9,9);
  JCJArray cg = (isLastBar == 1 && d1) || JCJBackSet(isLastBar == 1 && d2, 2) ||
                JCJBackSet(isLastBar == 1 && d3, 3) ||
                JCJBackSet(isLastBar == 1 && d4, 4) ||
                JCJBackSet(isLastBar == 1 && d5, 5) ||
                JCJBackSet(isLastBar == 1 && d6, 6) ||
                JCJBackSet(isLastBar == 1 && d7, 7) ||
                JCJBackSet(isLastBar == 1 && d8, 8) || JCJBackSet(d9, 9);

  cg.MemCopyTo(pfOUT);
}

void TestJCJ(int data_len,
             float* pfOUT,
             float* pfINa,
             float* pfINb,
             float* pfINc) {
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
  macd.MemCopyTo(pfOUT);
  return;

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
}

void TestMul(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray mul = close * 2;
  mul.MemCopyTo(pfOUT);
}

void TestGoldCross(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*) {
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

  gold_cross.MemCopyTo(pfOUT);
}

void TestBarsLast(int data_len,
                  float* pfOUT,
                  float* pfINa,
                  float*,
                  float*,
                  float*,
                  float*) {
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

  m1.MemCopyTo(pfOUT);
}

void TestEMA(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray ema = JCJEMA(close, 26);
  ema.MemCopyTo(pfOUT);
}

void TestSub(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  JCJArray result = (JCJEMA(close, 12) - JCJEMA(close, 26));
  result.MemCopyTo(pfOUT);
}

void TestGreate(int data_len,
                float* pfOUT,
                float* pfINa,
                float*,
                float*,
                float*,
                float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;

  // DEA:=EMA(DIF,9);
  JCJArray dea = JCJEMA(dif, 9);

  // MACD:=(DIF-DEA)*2,COLORSTICK;
  JCJArray macd = (dif - dea) * 2;

  // 死叉:=CROSS(DEA,DIF) AND REF(MACD,1)>0 AND REF(MACD,2)>0;
  JCJArray greate = JCJRef(macd, 1) > 0;
  greate.MemCopyTo(pfOUT);
}

void TestDIF(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;
  dif.MemCopyTo(pfOUT);
}

void TestMACD(int data_len,
              float* pfOUT,
              float* pfINa,
              float*,
              float*,
              float*,
              float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;

  // DEA:=EMA(DIF,9);
  JCJArray dea = JCJEMA(dif, 9);

  // MACD:=(DIF-DEA)*2,COLORSTICK;
  JCJArray macd = (dif - dea) * 2;
  macd.MemCopyTo(pfOUT);
}

void TestCross(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;

  // DEA:=EMA(DIF,9);
  JCJArray dea = JCJEMA(dif, 9);

  // 死叉:=CROSS(DEA,DIF) AND REF(MACD,1)>0 AND REF(MACD,2)>0;
  JCJArray cross = JCJCross(dea, dif);

  cross.MemCopyTo(pfOUT);
}

void TestRef(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  // DIF:=(EMA(CLOSE,12)-EMA(CLOSE,26))/5;
  JCJArray dif = (JCJEMA(close, 12) - JCJEMA(close, 26)) / 5;

  // DEA:=EMA(DIF,9);
  JCJArray dea = JCJEMA(dif, 9);

  // MACD:=(DIF-DEA)*2,COLORSTICK;
  JCJArray macd = (dif - dea) * 2;

  // 死叉:=CROSS(DEA,DIF) AND REF(MACD,1)>0 AND REF(MACD,2)>0;
  JCJArray ref = JCJRef(macd, 2);

  ref.MemCopyTo(pfOUT);
}

void TestDeadCross(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*) {
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

  dead_cross.MemCopyTo(pfOUT);
}

void TestMN1(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
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

  mn1.MemCopyTo(pfOUT);
}

void TestDHDXS(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*) {
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
  ddh_disspear.MemCopyTo(pfOUT);
}

void TestBG10Disspear(int data_len,
                      float* pfOUT,
                      float* pfINa,
                      float*,
                      float*,
                      float*,
                      float*) {
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

  bg10_disspear.MemCopyTo(pfOUT);
}

void TestLLV(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
  JCJArray close(data_len, pfINa);
  JCJArray cl1 = JCJLLV(close, 1);

  cl1.MemCopyTo(pfOUT);
}

void TestBG7(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*) {
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
  bg7.MemCopyTo(pfOUT);
}

