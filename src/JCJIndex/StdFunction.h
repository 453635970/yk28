#ifndef STDFUNCTION_H_
#define STDFUNCTION_H_

void MyEMA(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyMul(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MySub(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyAdd(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyDiv(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyCROSS(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc);

void MyAND(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyREF(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyGreate(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc);

void MyBelow(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc);

void MyBEqual(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc);

void MyBARSLAST(int DataLen,
                float* pfOUT,
                const float* pfINa,
                const float* pfINb,
                const float* pfINc);

void MyLLV(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyNOT(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyOR(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc);

void MyCOUNT(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc);

void MyNotEqual(int DataLen,
                float* pfOUT,
                const float* pfINa,
                const float* pfINb,
                const float* pfINc);

void MyEqual(int DataLen,
             float* pfOUT,
             const float* pfINa,
             const float* pfINb,
             const float* pfINc);

void MyGEqual(int DataLen,
              float* pfOUT,
              const float* pfINa,
              const float* pfINb,
              const float* pfINc);

void MyHHV(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyBACKSET(int DataLen,
               float* pfOUT,
               const float* pfINa,
               const float* pfINb,
               const float* pfINc);

void MyISLASTBAR(int DataLen,
                 float* pfOUT,
                 const float* pfINa,
                 const float* pfINb,
                 const float* pfINc);

void MyMA(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc);

void MySMA(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyIF(int DataLen,
          float* pfOUT,
          const float* pfINa,
          const float* pfINb,
          const float* pfINc);

void MyABS(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyMAX(int DataLen,
           float* pfOUT,
           const float* pfINa,
           const float* pfINb,
           const float* pfINc);

void MyWiner(int DataLen,
	float* pfOUT,
	const float* pfParam,
	const float* pfHigh,
	const float* pfLow,
    const float* pfVolume,
    const float* pfCircleCapital);

#endif /* STDFUNCTION_H_ */
