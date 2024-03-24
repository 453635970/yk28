#include "stdafx.h"
#include "tdx_register.h"
#include "jcj_index.h"

void WrapDrawXJT(int data_len, float* pfOUT, float* pfINa, float*, float*) {
  DrawXJT(data_len, pfOUT, pfINa);
}

void WrapDrawF1(int data_len,
                float* pfOUT,
                float* pfINa,  // CLOSE
                float*,
                float*) {
  DrawF1(data_len, pfOUT, pfINa);
}

void WrapDrawSJT(int data_len, float* pfOUT, float* pfINa, float*, float*) {
  DrawSJT(data_len, pfOUT, pfINa);
}

// 加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = {
    {1, (pPluginFUNC)&WrapDrawXJT},
    {2, (pPluginFUNC)&WrapDrawF1},
    {3, (pPluginFUNC)&WrapDrawSJT},
    {4, (pPluginFUNC)&TestJCJ},
    {0, NULL},
};

// 导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun) {
  if (*pFun == NULL) {
    (*pFun) = g_CalcFuncSets;
    return TRUE;
  }
  return FALSE;
}
