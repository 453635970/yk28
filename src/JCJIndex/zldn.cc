#include <vector>
#include <assert.h>
#include "jcj_utils.h"
#include "StdFunction.h"

// TestWinner
void JcIndexWinner(int data_len,
	float* pfOUT,
	float* pfINParam,  // param
	float* pfINHigh,  // hight
	float* pfINLow,  // low
	float* pfINVolume,  // volume
	float* pfINCircleCapital  // circle_capital
) {
	JCJArray param(data_len, pfINParam);
	JCJArray volume(data_len, pfINVolume);
	JCJArray high(data_len, pfINHigh);
	JCJArray low(data_len, pfINLow);
	JCJArray cirle_capital(data_len, pfINCircleCapital);

	// result:WINNER(CLOSE)    
	auto result = JCJWiner(param, volume, high, low, cirle_capital);

	// out
	result.MemCopyTo(pfOUT);
}
