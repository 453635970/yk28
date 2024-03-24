#include "zdld.h"
#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"

void CalcXiao5(int data_len,
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
  JCJArray xiao5 = JCJEMA(JCJIf(low <= xiao4, xiao3, 0), 3);

  xiao5.MemCopyTo(pfOUT);
}

