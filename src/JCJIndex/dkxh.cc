#include "dkxh.h"
#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"

void DuoKongXinHaoLow(int data_len,
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

  JCJArray out = cg && jl == n;
  out.MemCopyTo(pfOUT);
}

void DuoKongXinHaoHigh(int data_len,
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

  // GQT:=C<REF(C,4);
  JCJArray gqt = close < JCJRef(close, 4);

  // GCL:=C>REF(C,4);
  JCJArray gcl = close > JCJRef(close, 4);

  // GJL:=BARSLAST(GQT);
  JCJArray gjl = JCJBarsLast(gqt);

  // GD1:=GJL=1 AND GCL;
  JCJArray gd1 = gjl == 1 && gcl;

  // GD2:=GJL=2 AND GCL AND REF(GD1,1);
  JCJArray gd2 = gjl == 2 && gcl && JCJRef(gd1, 1);

  // GD3:=GJL=3 AND GCL AND REF(GD2,1);
  JCJArray gd3 = gjl == 3 && gcl && JCJRef(gd2, 1);

  // GD4:=GJL=4 AND GCL AND REF(GD3,1);
  JCJArray gd4 = gjl == 4 && gcl && JCJRef(gd3, 1);

  // GD5:=GJL=5 AND GCL AND REF(GD4,1);
  JCJArray gd5 = gjl == 5 && gcl && JCJRef(gd4, 1);

  // GD6:=GJL=6 AND GCL AND REF(GD5,1);
  JCJArray gd6 = gjl == 6 && gcl && JCJRef(gd5, 1);

  // GD7:=GJL=7 AND GCL AND REF(GD6,1);
  JCJArray gd7 = gjl == 7 && gcl && JCJRef(gd6, 1);

  // GD8:=GJL=8 AND GCL AND REF(GD7,1);
  JCJArray gd8 = gjl == 8 && gcl && JCJRef(gd7, 1);

  // GD9:=GJL=9 AND GCL AND REF(GD8,1);
  JCJArray gd9 = gjl == 9 && gcl && JCJRef(gd8, 1);

  // GCG:=BACKSET(ISLASTBAR=1 AND GD5,5) OR BACKSET(ISLASTBAR=1 AND GD6,6) OR
  // BACKSET(ISLASTBAR=1 AND GD7,7)
  //     OR BACKSET(ISLASTBAR=1 AND GD8,8) OR BACKSET( GD9,9);
  JCJArray gcg = JCJBackSet(isLastBar == 1 && gd5, 5) ||
                 JCJBackSet(isLastBar == 1 && gd6, 6) ||
                 JCJBackSet(isLastBar == 1 && gd7, 7) ||
                 JCJBackSet(isLastBar == 1 && gd8, 8) || JCJBackSet(gd9, 9);

  JCJArray out = gcg && gjl == n;
  out.MemCopyTo(pfOUT);
}
