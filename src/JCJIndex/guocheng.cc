#include "guocheng.h"
#include "dkxh.h"
#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"
//#include <windows.h>




//t11:=SYS_DLL1(1, C,H, L, O ,V);
void _GetA1(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* ,
	float* ,
	float* ,
	float*) 
{
	//MessageBoxA(0, "t_Macd0", 0, 0);
	//计算 MACD金叉 
	JCJArray close(data_len, pfInClose);
	// DIFF: = EMA(CLOSE, 8) - EMA(CLOSE, 13);
	auto diff = (JCJEMA(close, 8) - JCJEMA(close, 13));
	//DEA: = EMA(DIFF, 5);
	auto dea = JCJEMA(diff, 5);
	//A1: = (DIFF > DEA);
	auto A1 =(diff > dea);
	A1.MemCopyTo(pfOUT);
}

void _GetA2(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* pfInHigh,
	float* pfLow,
	float*,
	float*)
{
	JCJArray close(data_len, pfInClose);
	JCJArray low(data_len, pfLow);
	JCJArray high(data_len, pfInHigh);
	JCJArray right(high.length(), static_cast<float>(8));
	//RSV1: = (CLOSE - LLV(LOW, 8)) / (HHV(HIGH, 8) - LLV(LOW, 8)) * 100;
	auto RSV1 = (close - JCJLLV(low, 8)) / (JCJHHV(high, right) - JCJLLV(low, 8)) * 100;
	//K: = SMA(RSV1, 3, 1);
	auto k1 = JCJSMA(RSV1, 3, 1);
	//D: = SMA(K, 3, 1);
	auto d1 = JCJSMA(k1, 3, 1);
	//A2:=(K>D);
	auto A2 = (k1> d1);
	A2.MemCopyTo(pfOUT);
}

void _GetA3(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* ,
	float* ,
	float*,
	float*)
{
	JCJArray close(data_len, pfInClose);
	//LC: = REF(CLOSE, 1);
	auto lc = JCJRef(close, 1);
	//RSI1: = (SMA(MAX(CLOSE - LC, 0), 5, 1)) / (SMA(ABS(CLOSE - LC), 5, 1)) * 100;
	auto RSI1 = (JCJSMA(JCJMax(close - lc, 0), 5, 1) / JCJSMA(JCJAbs(close - lc), 5, 1)) * 100;
	//RSI2: = (SMA(MAX(CLOSE - LC, 0), 13, 1)) / (SMA(ABS(CLOSE - LC), 13, 1)) * 100;
	auto RSI2 = (JCJSMA(JCJMax(close - lc, 0), 13, 1) / JCJSMA(JCJAbs(close - lc), 13, 1)) * 100;
	//A3: = (RSI1 > RSI2);
    auto A3 = (RSI1 > RSI2);
	A3.MemCopyTo(pfOUT);
}

void _GetA4(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* pfInHigh,
	float* pfLow,
	float*,
	float*)
{
	JCJArray close(data_len, pfInClose);
	JCJArray low(data_len, pfLow);
	JCJArray high(data_len, pfInHigh);
	JCJArray right(high.length(), static_cast<float>(13));

	//RSV:=-(HHV(HIGH,13)-CLOSE)/(HHV(HIGH,13)-LLV(LOW,13))*100;
	JCJArray t = (JCJHHV(high, right) - close);
	//0-任何数 取 相反数
	JCJArray left(data_len, (float)0);
	JCJArray t1 =  left - t;
	auto RSV = t1 / (JCJHHV(high, right) - JCJLLV(low, 13)) * 100;

	//LWR1: = SMA(RSV, 3, 1);
	auto LWR1 = JCJSMA(RSV, 3, 1);
	//LWR2: = SMA(LWR1, 3, 1)
	auto LWR2 = JCJSMA(LWR1, 3, 1);
	//A4: = LWR1 > LWR2;
	auto A4 = (LWR1 > LWR2);
	A4.MemCopyTo(pfOUT);
}


void _GetA5(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* pfInHigh,
	float* pfLow,
	float*,
	float*)
{
	JCJArray close(data_len, pfInClose);
	//BBI: = (MA(CLOSE, 3) + MA(CLOSE, 6) + MA(CLOSE, 12) + MA(CLOSE, 24)) / 4;
	auto BBI = (JCJMA(close, 3) + JCJMA(close, 6) + JCJMA(close, 12) + JCJMA(close, 24)) / 4;
	//A5: = CLOSE > BBI;
	auto A5 = (close > BBI);
	A5.MemCopyTo(pfOUT);
}


void _GetA6(int data_len,
	float* pfOUT,
	float* pfInClose,
	float* pfInHigh,
	float* pfLow,
	float*,
	float*)
{
	JCJArray close(data_len, pfInClose);
	//MTM: = CLOSE - REF(CLOSE, 1);
	auto MTM = close - JCJRef(close, 1);

	JCJArray t1(data_len, (float)100);
	//MMS: = 100 * EMA(EMA(MTM, 5), 3) / EMA(EMA(ABS(MTM), 5), 3);
	auto MMS= (t1 * JCJEMA(JCJEMA(MTM, 5), 3)) / JCJEMA(JCJEMA(JCJAbs(MTM), 5), 3);
	//MMM: = 100 * EMA(EMA(MTM, 13), 8) / EMA(EMA(ABS(MTM), 13), 8);
	auto MMM = t1 * JCJEMA(JCJEMA(MTM, 13), 8) / JCJEMA(JCJEMA(JCJAbs(MTM), 13), 8);

	//A6: = MMS > MMM;
	auto A6 = (MMS > MMM);
	A6.MemCopyTo(pfOUT);
}