#ifndef TEST_DLL_H_
#define TEST_DLL_H_
void TestAbs(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*);

void TestSMA(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*);

void TestMAX(int data_len,
             float* pfOUT,
             float* pfInOpen,
             float* pfInHigh,
             float* pfInLow,
             float* pfInClose,
             float*);

void TestXiao2(int data_len,
               float* pfOUT,
               float* pfInOpen,
               float* pfInHigh,
               float* pfInLow,
               float* pfInClose,
               float*);

void TestIf(int data_len,
            float* pfOUT,
            float* pfInOpen,
            float* pfInHigh,
            float* pfInLow,
            float* pfInClose,
            float*);

void TestDDHDisspear(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*);

void TestT(int data_len,
           float* pfOUT,
           float* pfINa,
           float*,
           float*,
           float*,
           float*);

void TestGFDDH(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*);

void TestDH1_GEQ_DH3(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*);

void TestRefGFDDH(int data_len,
                  float* pfOUT,
                  float* pfINa,
                  float*,
                  float*,
                  float*,
                  float*);

void TestD9(int data_len,
            float* pfOUT,
            float* pfInClose,
            float* pfInN,
            float*,
            float*,
            float*);

void TestCG(int data_len,
            float* pfOUT,
            float* pfInClose,
            float* pfInN,
            float*,
            float*,
            float*);

void TestJCJ(int data_len,
             float* pfOUT,
             float* pfINa,
             float* pfINb,
             float* pfINc);

void TestMul(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestGoldCross(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*);

void TestBarsLast(int data_len,
                  float* pfOUT,
                  float* pfINa,
                  float*,
                  float*,
                  float*,
                  float*);

void TestEMA(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestSub(int data_len,
             float* pfOUT,
             float* pfINa,
             float* pfINb,
             float*,
             float*,
             float*);

void TestGreate(int data_len,
                float* pfOUT,
                float* pfINa,
                float*,
                float*,
                float*,
                float*);

void TestDIF(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestMACD(int data_len,
              float* pfOUT,
              float* pfINa,
              float*,
              float*,
              float*,
              float*);

void TestCross(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*);

void TestRef(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestDeadCross(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*);

void TestMN1(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestDHDXS(int data_len,
               float* pfOUT,
               float* pfINa,
               float*,
               float*,
               float*,
               float*);

void TestBG10Disspear(int data_len,
                      float* pfOUT,
                      float* pfINa,
                      float*,
                      float*,
                      float*,
                      float*);

void TestLLV(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

void TestBG7(int data_len,
             float* pfOUT,
             float* pfINa,
             float*,
             float*,
             float*,
             float*);

#endif /* TEST_DLL_H_ */
