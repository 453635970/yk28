#ifndef JDXJ_DOWN_H_
#define JDXJ_DOWN_H_

class JCJArray;

void JcIndexDown(int data_len,
                 float* pfOUT,
                 float* pfINa,  // close
                 JCJArray* out_ddhdisspear,
                 JCJArray* out_tg10_disspear,
                 JCJArray* out_tg7_disspear,
                 JCJArray* out_t,
                 JCJArray* out_tg7_draw,
                 JCJArray* out_tg10_draw);

void DDXJDownDrawSJT(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*);

void DDXJDownDrawY(int data_len,
                   float* pfOUT,
                   float* pfINa,
                   float*,
                   float*,
                   float*,
                   float*);

void DDXJDownDrawXJT(int data_len,
                     float* pfOUT,
                     float* pfINa,
                     float*,
                     float*,
                     float*,
                     float*);

#endif /* JDXJ_DOWN_H_ */
