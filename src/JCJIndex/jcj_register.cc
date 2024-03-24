#include "stdafx.h"
#include "jcj_register.h"
#include "jcj_index.h"
#include "jdxj_up.h"
#include "jdxj_down.h"
#include "zdld.h"
#include "dkxh.h"
#include "qstd.h"
#include "zldn.h"
#include "guocheng.h"

void WrapDrawXJT(int data_len,
                 float* pfOUT,
                 float* pfINa,
                 float*,
                 float*,
                 float*,
                 float*) {
	
  DrawXJT(data_len, pfOUT, pfINa);
}

void WrapDrawF1(int data_len,
                float* pfOUT,
                float* pfINa,  // CLOSE
                float*,
                float*,
                float*,
                float*) {
  DrawF1(data_len, pfOUT, pfINa);
}

void WrapDrawSJT(int data_len,
                 float* pfOUT,
                 float* pfINa,
                 float*,
                 float*,
                 float*,
                 float*) {
  DrawSJT(data_len, pfOUT, pfINa);
}

// 加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = {
    {1, (pPluginFUNC)&WrapDrawXJT},
    {2, (pPluginFUNC)&WrapDrawF1},
    {3, (pPluginFUNC)&WrapDrawSJT},
    {4, (pPluginFUNC)&DDXJDownDrawSJT},
    {5, (pPluginFUNC)&DDXJDownDrawY},
    {6, (pPluginFUNC)&DDXJDownDrawXJT},
    {7, (pPluginFUNC)&CalcXiao5},
    {8, (pPluginFUNC)&DuoKongXinHaoLow},
    {9, (pPluginFUNC)&DuoKongXinHaoHigh},
    {10, (pPluginFUNC)&QuShiTongDaoGTY1},
    {11, (pPluginFUNC)&QuShiTongDaoGTY2},
    {12, (pPluginFUNC)&QuShiTongDaoGTY3},
    {13, (pPluginFUNC)&QuShiTongDaoGTY4},
    {14, (pPluginFUNC)&QuShiTongDaoGTY5},
    {15, (pPluginFUNC)&QuShiTongDaoGTY6},
    {16, (pPluginFUNC)&QuShiTongDaoGTY7},
    {17, (pPluginFUNC)&QuShiTongDaoTY1},
    {18, (pPluginFUNC)&QuShiTongDaoTY2},
    {19, (pPluginFUNC)&QuShiTongDaoTY3},
    {20, (pPluginFUNC)&QuShiTongDaoTY4},
    {21, (pPluginFUNC)&QuShiTongDaoTY5},
    {22, (pPluginFUNC)&QuShiTongDaoTY6},
    {23, (pPluginFUNC)&QuShiTongDaoTY7},
    {24, (pPluginFUNC)&JcIndexWinner},
	{25, (pPluginFUNC)&_GetA1},
	{26, (pPluginFUNC)&_GetA2},
	{27, (pPluginFUNC)&_GetA3},
	{28, (pPluginFUNC)&_GetA4},
	{29, (pPluginFUNC)&_GetA5},
	{30, (pPluginFUNC)&_GetA6},
    {0, NULL},
};

// 导出给TCalc的注册函数
BOOL RegisterThrdFunc(PluginTCalcFuncInfo** pFun) {
  if (*pFun == NULL) {
    (*pFun) = g_CalcFuncSets;

    return TRUE;
  }
  return FALSE;
}
