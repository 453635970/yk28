#include "jcj_utils.h"
#include <assert.h>
#include <iterator>
#include "StdFunction.h"
#include <cfloat>

JCJArray::JCJArray(size_t data_len) : data_(data_len) {}
JCJArray::JCJArray(size_t data_len, float init) : data_(data_len, init) {}

JCJArray::JCJArray(size_t data_len, float* array) : data_(data_len) {
  memcpy(data_.data(), array, sizeof(float) * data_len);
}

size_t JCJArray::length() const {
  return data_.size();
}

const float* JCJArray::data() const {
  return data_.data();
}

float* JCJArray::multable_data() {
  return data_.data();
}

void JCJArray::MemCopyTo(float* dest) {
  memcpy(dest, data_.data(), sizeof(float) * length());
}

std::size_t JCJArray::size() const {
    return data_.size();
}

JCJArray operator+(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyAdd(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator+(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left + right;
}

JCJArray operator-(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MySub(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator*(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyMul(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator*(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left * right;
}

JCJArray operator/(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyDiv(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator/(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left / right;
}

JCJArray operator>(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyGreate(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator>(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left > right;
}

JCJArray operator<(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyBelow(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray operator<(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left < right;
}

JCJArray operator<=(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyBEqual(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator<=(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left <= right;
}

JCJArray operator>=(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyGEqual(result.length(), result.multable_data(), left.data(), right.data(),
           nullptr);
  return result;
}

JCJArray operator>=(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left >= right;
}

JCJArray operator&&(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyAND(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray operator||(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyOR(result.length(), result.multable_data(), left.data(), right.data(),
       nullptr);
  return result;
}

JCJArray operator!=(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyNotEqual(result.length(), result.multable_data(), left.data(), right.data(),
             nullptr);
  return result;
}

JCJArray operator==(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyEqual(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray operator==(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return left == right;
}

JCJArray operator!(const JCJArray& left) {
  return JCJNot(left);
}

JCJArray JCJEMA(const JCJArray& input, int number) {
  JCJArray wrapper_number(input.length(), static_cast<float>(number));
  JCJArray result(input.length());
  MyEMA(result.length(), result.multable_data(), input.data(),
        wrapper_number.data(), nullptr);
  return result;
}

JCJArray JCJCross(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());

  MyCROSS(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray JCJRef(const JCJArray& input, int ref) {
  JCJArray result(input.length());
  JCJArray wrapper_ref(input.length(), static_cast<float>(ref));

  MyREF(result.length(), result.multable_data(), input.data(),
        wrapper_ref.data(), nullptr);

  return result;
}

JCJArray JCJRef(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyREF(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);

  return result;
}

JCJArray JCJBarsLast(const JCJArray& input) {
  JCJArray result(input.length());
  MyBARSLAST(result.length(), result.multable_data(), input.data(), nullptr,
             nullptr);
  return result;
}

JCJArray JCJLLV(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyLLV(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray JCJLLV(const JCJArray& left, int right_num) {
  JCJArray right(left.length(), static_cast<float>(right_num));
  return JCJLLV(left, right);
}

JCJArray JCJNot(const JCJArray& input) {
  JCJArray result(input.length());
  MyNOT(result.length(), result.multable_data(), input.data(), nullptr,
        nullptr);
  return result;
}


JCJArray JCJCount(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyCOUNT(result.length(), result.multable_data(), left.data(), right.data(),
          nullptr);
  return result;
}

JCJArray JCJHHV(const JCJArray& left, const JCJArray& right) {
  assert(left.length() == right.length());
  JCJArray result(left.length());
  MyHHV(result.length(), result.multable_data(), left.data(), right.data(),
        nullptr);
  return result;
}

JCJArray JCJSMA(const JCJArray& x, int n_num, int m_num) {
  JCJArray n(x.length(), n_num);
  JCJArray m(x.length(), m_num);

  JCJArray result(x.length());
  MySMA(result.length(), result.multable_data(), x.data(), n.data(), m.data());
  return result;
}

JCJArray JCJAbs(const JCJArray& in) {
  JCJArray result(in.length());
  MyABS(result.length(), result.multable_data(), in.data(), nullptr, nullptr);
  return result;
}

JCJArray JCJMax(const JCJArray& left, int right_num) {
  JCJArray out(left.length());
  JCJArray right(left.length(), right_num);
  MyMAX(out.length(), out.multable_data(), left.data(), right.data(), nullptr);
  return out;
}

JCJArray JCJIf(const JCJArray& cond, const JCJArray& t, int f_num) {
  JCJArray out(cond.length());
  JCJArray f(cond.length());
  MyIF(out.length(), out.multable_data(), cond.data(), t.data(), f.data());
  return out;
}

JCJArray JCJBackSet(const JCJArray& x, int n_num) {
  JCJArray out(x.length());
  JCJArray n(x.length(), n_num);
  MyBACKSET(x.length(), out.multable_data(), x.data(), n.data(), nullptr);
  return out;
}

JCJArray JCJMA(const JCJArray& x, int n_num) {
  JCJArray out(x.length());
  JCJArray n(x.length(), n_num);
  MyMA(x.length(), out.multable_data(), x.data(), n.data(), nullptr);
  return out;
}

JCJArray JCJWiner(const JCJArray& x, const JCJArray& volume,  const JCJArray& high, const JCJArray& low, const JCJArray& cirle_capital) {
	JCJArray out(x.length()); 
    MyWiner(x.size(), out.multable_data(), x.data(), high.data(), low.data(), volume.data(), cirle_capital.data());
    return out;
}

