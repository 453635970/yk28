#include "stdafx.h"
#include "jcj_register.h"
#include "jcj_index.h"
#include "jdxj_up.h"
#include "jdxj_down.h"
#include "zdld.h"
#include "dkxh.h"
#include "qstd.h"
#include "test_dll.h"
#include "zldn.h"
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
    {4, (pPluginFUNC)&TestMACD},
    {5, (pPluginFUNC)&TestDIF},
    {6, (pPluginFUNC)&TestEMA},
    {7, (pPluginFUNC)&TestMul},
    {9, (pPluginFUNC)&TestSub},
    {10, (pPluginFUNC)&TestMN1},
    {11, (pPluginFUNC)&TestDeadCross},
    {12, (pPluginFUNC)&TestCross},
    {13, (pPluginFUNC)&TestRef},
    {14, (pPluginFUNC)&TestGreate},
    {15, (pPluginFUNC)&TestBarsLast},
    {16, (pPluginFUNC)&TestGoldCross},
    {17, (pPluginFUNC)&TestDHDXS},
    {18, (pPluginFUNC)&TestBG10Disspear},
    {19, (pPluginFUNC)&TestBG7},
    {20, (pPluginFUNC)&TestLLV},
    {21, (pPluginFUNC)&DDXJDownDrawSJT},
    {22, (pPluginFUNC)&DDXJDownDrawY},
    {23, (pPluginFUNC)&DDXJDownDrawXJT},

    {200, (pPluginFUNC)&TestDDHDisspear},
    {201, (pPluginFUNC)&TestT},
    {202, (pPluginFUNC)&TestGFDDH},
    {203, (pPluginFUNC)&TestDH1_GEQ_DH3},
    {204, (pPluginFUNC)&TestRefGFDDH},
    {206, (pPluginFUNC)&TestAbs},
    {207, (pPluginFUNC)&TestSMA},
    {208, (pPluginFUNC)&TestMAX},
    {209, (pPluginFUNC)&TestXiao2},
    {210, (pPluginFUNC)&TestIf},
    {211, (pPluginFUNC)&TestD9},
    {212, (pPluginFUNC)&TestCG},
	
    {300, (pPluginFUNC)&CalcXiao5},

    {400, (pPluginFUNC)&DuoKongXinHaoLow},
    {401, (pPluginFUNC)&DuoKongXinHaoHigh},

    {500, (pPluginFUNC)&QuShiTongDaoGTY1},
    {501, (pPluginFUNC)&QuShiTongDaoGTY2},
    {502, (pPluginFUNC)&QuShiTongDaoGTY3},
    {503, (pPluginFUNC)&QuShiTongDaoGTY4},
    {504, (pPluginFUNC)&QuShiTongDaoGTY5},
    {505, (pPluginFUNC)&QuShiTongDaoGTY6},
    {506, (pPluginFUNC)&QuShiTongDaoGTY7},
    {507, (pPluginFUNC)&QuShiTongDaoTY1},
    {508, (pPluginFUNC)&QuShiTongDaoTY2},
    {509, (pPluginFUNC)&QuShiTongDaoTY3},
    {510, (pPluginFUNC)&QuShiTongDaoTY4},
    {511, (pPluginFUNC)&QuShiTongDaoTY5},
    {512, (pPluginFUNC)&QuShiTongDaoTY6},
    {513, (pPluginFUNC)&QuShiTongDaoTY7},
	{514, (pPluginFUNC)&JcIndexWinner},	

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
