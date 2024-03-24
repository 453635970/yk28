
#include "StdAfx.h"
#include "StdFunction.h"
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <cfloat>

#define EPSINON (0.00001)
#define equ_than_0(f) ((f) >= -EPSINON && (f) <= EPSINON)
#define greater_than_0(f) ((f) > EPSINON)
#define greater_equ_than_0(f) ((f) >= -EPSINON)
#define less_than_0(f) ((f) < -EPSINON)
#define less_equ_than_0(f) ((f) <= EPSINON)

const uint8_t avoid_mask[] = {0xF8, 0xF8, 0xF8,
                              0xF8};  // 无效数据标志(通达信系统定义)

static bool isValidateNum(float num) {
  if (num == *reinterpret_cast<const float*>(avoid_mask))
    return false;
  return true;
}

/*四舍五入.
用法:
ROUND(X),返回X四舍五入到个位的数值*/
static int round_float(double number) {
  return (number > 0.0) ? ::floor(number + 0.5) : ::ceil(number - 0.5);
}

// > 大于号
void MyGreate(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    bool aValidate = isValidateNum(pfINa[i]);
    bool bValidate = isValidateNum(pfINb[i]);

    if (aValidate && bValidate) {
      pfOUT[i] = greater_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;
    } else {
    }
  }
}

// >= 大于等于号
void MyGEqual(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    bool aValidate = isValidateNum(pfINa[i]);
    bool bValidate = isValidateNum(pfINb[i]);

    if (aValidate && bValidate) {
      // 有等于比较时，需要把数据四舍五入去做比较
      pfOUT[i] = greater_equ_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;

    } else if (!aValidate && !bValidate) {
      pfOUT[i] = 1;
    } else {
    }
  }
}

// < 小于号
void MyBelow(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    bool aValidate = isValidateNum(pfINa[i]);
    bool bValidate = isValidateNum(pfINb[i]);

    if (aValidate && bValidate) {
      pfOUT[i] = less_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;
    } else {
    }
  }
}

// <= 小于等于号
void MyBEqual(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    bool aValidate = isValidateNum(pfINa[i]);
    bool bValidate = isValidateNum(pfINb[i]);

    if (aValidate && bValidate) {
      // 有等于比较时，需要把数据四舍五入去做比较
      pfOUT[i] = less_equ_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;

    } else if (!aValidate && !bValidate) {
      pfOUT[i] = 1;
    } else {
    }
  }
}

// = 等于号
void MyEqual(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      // 有等于比较时，需要把数据四舍五入去做比较
      pfOUT[i] = equ_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;

    } else if (!isValidateNum(pfINa[i]) && !isValidateNum(pfINb[i])) {
      pfOUT[i] = 1;
    } else {
      pfOUT[i] = 0;
    }
  }
}

// != 不等于
void MyNotEqual(int DataLen,
                float* pfOUT,
                const float* pfINa,
                const float* pfINb,
                const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      pfOUT[i] = !equ_than_0(pfINa[i] - pfINb[i]) ? 1 : 0;
    } else if (!isValidateNum(pfINa[i]) && !isValidateNum(pfINb[i])) {
      pfOUT[i] = 0;
    } else {
      pfOUT[i] = 1;
    }
  }
}

// + 加号
void MyAdd(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i]))
      pfOUT[i] = (pfINa[i] + pfINb[i]);
  }
}

// - 减号
void MySub(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i]))
      pfOUT[i] = (pfINa[i] - pfINb[i]);
  }
}

// * 乘号
void MyMul(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i]))
      pfOUT[i] = (pfINa[i] * pfINb[i]);
  }
}

// / 除号
void MyDiv(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i]) && pfINb[i] != 0) {
      pfOUT[i] = (pfINa[i] / pfINb[i]);
    } else {
      pfOUT[i] = *reinterpret_cast<const float*>(avoid_mask);
    }
  }
}

// AND && 并且
void MyAND(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      pfOUT[i] = (pfINa[i] && pfINb[i]) ? 1 : 0;
    }
  }
}

// OR || 或者
void MyOR(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      pfOUT[i] = (pfINa[i] || pfINb[i]) ? 1 : 0;
    } else if (!isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      pfOUT[i] = pfINb[i] ? 1 : 0;
    } else if (isValidateNum(pfINa[i]) && !isValidateNum(pfINb[i])) {
      pfOUT[i] = pfINa[i] ? 1 : 0;
    }
  }
}

// 返回指数移动平均
// 用法:
// EMA(X,N):X的N日指数移动平均.算法:Y=(X*2+Y'*(N-1))/(N+1)
//						  EMA(X,N)相当于SMA(X,N+1,2),N支持变量
void MyEMA(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  double db = 0.0;
  for (int i = 0; i < DataLen; i++) {
    if (!isValidateNum(pfINb[i])) {
      pfOUT[i] = *reinterpret_cast<const float*>(avoid_mask);
      continue;
    }

    if (!isValidateNum(pfINa[i])) {
      pfOUT[i] = *reinterpret_cast<const float*>(avoid_mask);
      continue;
    }

    if (i >= 1) {
      if (isValidateNum(pfOUT[i - 1])) {
        db = (pfINa[i] * 2.0 + db * (pfINb[i] - 1.0)) / (pfINb[i] + 1.0);
      } else {
        db = pfINa[i];
      }
    } else {
      db = pfINa[i];
    }
    pfOUT[i] = db;
  }
}

// 两条线交叉.
// 用法:
// CROSS(A,B)表示当A从下方向上穿过B时返回1,否则返回0
// 例如:
// CROSS(MA(CLOSE,5),MA(CLOSE,10))表示5日均线与10日均线交金叉
void MyCROSS(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc) {
  int bl = 0;
  int be = DataLen - 1;

  for (int i = bl; i <= be; i++) {
    if (i == bl) {
      pfOUT[i] = 0;
    } else if (pfINa[i - 1] <= pfINb[i - 1] && pfINa[i] > pfINb[i]) {
      pfOUT[i] = 1;
    } else {
      pfOUT[i] = 0;
    }
  }
}

// 引用若干周期前的数据(平滑处理).
// 用法:
// REF(X,A),引用A周期前的X值.A可以是变量.
// 平滑处理:当引用不到数据时进行的操作.此函数中,平滑时使用上一个周期的引用值.
// 例如:
// REF(CLOSE,BARSCOUNT(C)-1)表示第二根K线的收盘价.
void MyREF(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  // for (int i = 0;i < DataLen;i++)
  // {

  // 	if (!isValidateNum(pfINb[i]))
  // 		continue;

  // 	int N = pfINb[i];
  // 	if (N == 0)
  // 	{
  // 		pfOUT[i] = pfINa[i];
  // 	}
  // 	else
  // 	{
  // 		if (i >= N)
  // 		{
  // 			pfOUT[i] = pfINa[i - N];
  // 		}
  // 		else {
  // 			pfOUT[i] = pfINa[i];
  // 		}
  // 	}
  // }


  for (int i = 0; i < DataLen; i++) {
    int cycle = i - pfINb[i];
    if (cycle < 0 || cycle >= DataLen)
      cycle = 0;

    pfOUT[i] = pfINa[cycle];
  }
}

// 求最低值.
// 用法:
// LLV(X, N), 求N周期内X最低值, N = 0则从第一个有效值开始.
// 例如 :
//	LLV(LOW, 0)表示求历史最低价

// void MyLLV(int DataLen, float* pfOUT, const float* pfINa, const float* pfINb,
// const float* pfINc)
// {
// 	for (int i = DataLen - 1;i >= 0;i--)
// 	{
// 		int N = pfINb[i];
// 		if (!isValidateNum(pfINb[i]))
// 		{
// 			N = 0; //值非法时，当成0来处理
// 		}
//
// 		if (!isValidateNum(pfINa[i]))
// 			continue;
//
// 		float temp = pfINa[i];
// 		bool bResult = true;
//
// 		//N = 0则从第一个有效值开始.
// 		if (N == 0)
// 			N = i + 1;
//
// 		for (int j = 0;j < N;j++)
// 		{
// 			if (i >= j)
// 			{
// 				if (!isValidateNum(pfINa[i - j]))
// 				{
// 					//bResult = false;
// 					//break;
// 					continue;
// 				}
// 				temp = min(temp, pfINa[i - j]);
// 			}
// 		}
// 		if (bResult)
// 			pfOUT[i] = temp;
// 	}
// }

// 求最低值.
// 用法:
// LLV(X, N), 求N周期内X最低值, N = 0则从第一个有效值开始.
// 例如 :
//	LLV(LOW, 0)表示求历史最低价

void MyLLV(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  int idx = 0;
  for (int i = 0; i <= DataLen - 1; i++) {
    int ret = pfINb[i];

    if (ret < 0)
      ret = 0;

    if (ret == 0)
      idx = 0;
    else
      idx = min(DataLen - 1, max(0, i - ret + 1));

    pfOUT[i] = *std::min_element(&pfINa[idx], &pfINa[i + 1]);
  }
}

// 求最高值.
// 用法:
// HHV(X,N),求N周期内X最高值,N=0则从第一个有效值开始.
// 例如:
// HHV(HIGH,30)表示求30日最高价
void MyHHV(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = DataLen - 1; i >= 0; i--) {
    int N = pfINb[i];
    if (!isValidateNum(pfINb[i])) {
      N = 0;  // 值非法时，当成0来处理
    }

    if (!isValidateNum(pfINa[i]))
      continue;

    float temp = pfINa[i];
    bool bResult = true;

    // N = 0则从第一个有效值开始.
    if (N == 0)
      N = i + 1;

    for (int j = 0; j < N; j++) {
      if (i >= j) {
        if (!isValidateNum(pfINa[i - j])) {
          // bResult = false;
          // break;
          continue;
        }
        temp = max(temp, pfINa[i - j]);
      }
    }
    if (bResult)
      pfOUT[i] = temp;
  }
}

// 上一次条件成立到当前的周期数.
// 用法:
// BARSLAST(X):上一次X不为0到现在的天数
// 例如:
// BARSLAST(CLOSE/REF(CLOSE,1)>=1.1)表示上一个涨停板到当前的周期数

void MyBARSLAST(int DataLen,
                float* pfOUT,
                const float* pfINa,
                const float* pfINb,
                const float* pfINc) {
  // for (int i = 0; i < DataLen; i++)
  // {
  // 	for (int j = i; j >= 0; j--)
  // 	{
  // 		//he fa zhi
  // 		if (pfINa[j] && isValidateNum(pfINa[j]))
  // 		{
  // 			pfOUT[i] = i - j;
  // 			break;
  // 		}
  // 	}
  // }

  int j = 0;
  int k = j;
  int l = j;
  for (int i = j; i < DataLen; ++i) {
    if (pfINa[i] != 0) {
      if (j == k)
        l = i;
      k = i;
    }
    pfOUT[i] = i - k;
  }
}

//	求逻辑非.
// 用法:
// NOT(X)返回非X,即当X=0时返回1,否则返回0
// 例如:
//	NOT(ISUP)表示平盘或收阴
void MyNOT(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (!pfINa[i])
      pfOUT[i] = 1;
    else
      pfOUT[i] = 0;
  }
}

// 统计满足条件的周期数.
// 用法:
// COUNT(X,N),统计N周期中满足X条件的周期数,若N<0则从第一个有效值开始.
// 例如:
// COUNT(CLOSE>OPEN,20)表示统计20周期内收阳的周期数
void MyCOUNT(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc) {
  for (int i = DataLen - 1; i >= 0; i--) {
    if (!isValidateNum(pfINb[i]))
      continue;

    int N = pfINb[i];

    int nCount = 0;

    int jIndex = 0;
    if (i - N >= 0)
      jIndex = i - N;
    else
      jIndex = 0;

    bool bResult = true;
    for (int j = i; j > jIndex; j--) {
      if (isValidateNum(pfINa[j])) {
        if (pfINa[j])
          nCount++;
      } else {
        bResult = false;
        break;
      }
    }
    if (bResult)
      pfOUT[i] = nCount;
  }
}

void MyBACKSET(int DataLen,
               float* pfOUT,
               const float* pfINa,
               const float* pfINb,
               const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (!isValidateNum(pfINa[i]))
      continue;

    if (pfINa[i]) {
      if (!isValidateNum(pfINb[i]))
        continue;

      int N = (int)pfINb[i];

      for (int j = 0; j < N; j++) {
        if (i >= j)
          pfOUT[i - j] = 1;
        else
          pfOUT[i] = 1;
      }
    } else
      pfOUT[i] = 0;
  }
}


void MyISLASTBAR(int DataLen,
                 float* pfOUT,
                 const float* pfINa,
                 const float* pfINb,
                 const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (i != DataLen - 1)
      pfOUT[i] = 0;
    else
      pfOUT[i] = 1;
  }
}

void MyMA(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc) {
  // memset(pfOUT, *reinterpret_cast<const uint32_t*>(avoid_mask), sizeof(float) * DataLen);

  int ret = pfINb[0];
	if (ret < 1)
		ret = 1;
  int bl = ret - 1;
  int be = DataLen - 1;
  float ax = 0.0;
  for (int i = bl; i <= be; i++) {
    int param = pfINb[i];
    if (param < 1)
      param = 1;
     
    if (i == bl) {
      for (int j = i - param + 1; j <= i; j++)
        ax += pfINa[j];

      pfOUT[i] = ax / param;
      ret = param;
    } else {
      if (ret == param) {
        ax -= pfINa[i - param];
        ax += pfINa[i];
        pfOUT[i] = ax / param;
      } else {
        ax = 0.0;
        for (int j = i - param + 1; j <= i; j++)
          ax += pfINa[j];

        pfOUT[i] = ax / param;
        ret = param;
      }
    }
  }
}

void MyIF(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i])) {
      if (pfINa[i] != 0)
        pfOUT[i] = pfINb[i];
      else
        pfOUT[i] = pfINc[i];
    } else {
      pfOUT[i] = *reinterpret_cast<const float*>(avoid_mask);
    }
  }
}

void MySMA(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (!isValidateNum(pfINb[i]) || !isValidateNum(pfINc[i])) {
      continue;
    }

    if (pfINb[i] <= pfINc[i])
      continue;

    if (!isValidateNum(pfINa[i])) {
      continue;
    }
    if (i >= 1) {
      if (isValidateNum(pfOUT[i - 1])) {
        pfOUT[i] =
            (pfINc[i] * pfINa[i] + (pfINb[i] - pfINc[i]) * pfOUT[i - 1]) /
            pfINb[i];
      } else {
        pfOUT[i] = pfINa[i];
      }
    } else
      pfOUT[i] = pfINa[i];
  }
}

void MyABS(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]))
      pfOUT[i] = fabsf(pfINa[i]);
  }
}

void MyMAX(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc) {
  for (int i = 0; i < DataLen; i++) {
    if (isValidateNum(pfINa[i]) && isValidateNum(pfINb[i]))
      pfOUT[i] = max(pfINa[i], pfINb[i]);
  }
}

void MyWiner(int DataLen,
    float* pfOUT,
    const float* pfParam,
    const float* pfHigh,
    const float* pfLow,
    const float* pfVolume,
    const float* pfCircleCapital) {	

	float* rate = new float[DataLen];
	std::memset(rate, 0, sizeof(float) * DataLen);

	float* allvo = new float[DataLen];
	std::memset(allvo, 0, sizeof(float) * DataLen);
	for (std::size_t i = 0; i < DataLen; ++i)
        allvo[i] = pfCircleCapital[i];

    float chouma_limit{}, winv{}, sumv{}, tmpVal{};

	for (auto i = DataLen - 1; i >= 0; i--) {
		// 基于当天的数据,来推到历史每天筹码盈利比例
		for (auto k = i; k >= 0; k--)	 {
			const auto& hp = pfHigh[k];
			const auto& lp = pfLow[k];

			float fOffset = (pfParam[i] > 20.0) ? 0.01 : 0.05;
			if (lp > pfParam[i])
				rate[k] = 0;
			else if (hp <= pfParam[i])
				rate[k] = 1;
			else
				rate[k] = (pfParam[i] - lp + fOffset) / (hp - lp + fOffset);
		}

        // 根据计算的历史筹码比例,计算基于筹码比例的成交量
        // 基于历史筹码量总和与当日流通股数得出筹码比例对应值
        chouma_limit = allvo[i];
		winv = sumv = 0;

		for (auto k = i; k >= 0; k--) {
			const auto& tmpVal = pfVolume[i];
			winv += tmpVal * rate[k];
			sumv += tmpVal;
			if (sumv >= chouma_limit)
				break;
		}

        pfOUT[i] = sumv ? winv / sumv : 0;
	}   

    delete[] rate;
    delete[] allvo;
}
