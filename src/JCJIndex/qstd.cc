#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"
#include "qstd.h"
void QuShiTongDaoGTY1(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY1:MA(EMA(CLOSE,12),10);
  JCJArray gty1 = JCJMA(JCJEMA(close, 12), 10);

  gty1.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY2(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY2:MA(EMA(CLOSE,12),30);
  JCJArray gty2 = JCJMA(JCJEMA(close, 12), 30);

  gty2.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY3(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY3:MA(EMA(CLOSE,12),50);
  JCJArray gty3 = JCJMA(JCJEMA(close, 12), 50);

  gty3.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY4(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY4:MA(EMA(CLOSE,12),70);
  JCJArray gty4 = JCJMA(JCJEMA(close, 12), 70);

  gty4.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY5(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY5:MA(EMA(CLOSE,12),90);
  JCJArray gty5 = JCJMA(JCJEMA(close, 12), 90);

  gty5.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY6(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY6:MA(EMA(CLOSE,12),120);
  JCJArray gty6 = JCJMA(JCJEMA(close, 12), 120);

  gty6.MemCopyTo(pfOUT);
}

void QuShiTongDaoGTY7(int data_len,
                      float* pfOUT,
                      float* pfInClose,
                      float*,
                      float*,
                      float*,
                      float*) {
  JCJArray close(data_len, pfInClose);
  // GTY7:MA(EMA(CLOSE,12),150);
  JCJArray gty7 = JCJMA(JCJEMA(close, 12), 150);

  gty7.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY1(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY1:MA(EMA(CLOSE,60),10);
  JCJArray ty1 = JCJMA(JCJEMA(close, 60), 10);

  ty1.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY2(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY2:MA(EMA(CLOSE,60),30);
  JCJArray ty2 = JCJMA(JCJEMA(close, 60), 30);

  ty2.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY3(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY3:MA(EMA(CLOSE,60),50);
  JCJArray ty3 = JCJMA(JCJEMA(close, 60), 50);

  ty3.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY4(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY4:MA(EMA(CLOSE,60),70);
  JCJArray ty4 = JCJMA(JCJEMA(close, 60), 70);

  ty4.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY5(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY5:MA(EMA(CLOSE,60),90);
  JCJArray ty5 = JCJMA(JCJEMA(close, 60), 90);

  ty5.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY6(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY6:MA(EMA(CLOSE,60),120);
  JCJArray ty6 = JCJMA(JCJEMA(close, 60), 120);

  ty6.MemCopyTo(pfOUT);
}

void QuShiTongDaoTY7(int data_len,
                     float* pfOUT,
                     float* pfInClose,
                     float*,
                     float*,
                     float*,
                     float*) {
  JCJArray close(data_len, pfInClose);
  // TY7:MA(EMA(CLOSE,60),150);
  JCJArray ty7 = JCJMA(JCJEMA(close, 60), 150);

  ty7.MemCopyTo(pfOUT);
}
