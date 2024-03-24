#ifndef JCJ_UTILS_H_
#define JCJ_UTILS_H_ 
#include <vector>
class JCJArray {
  public:
    explicit JCJArray(size_t data_len);

    JCJArray(size_t data_len, float init);

    JCJArray(size_t data_len, float* array);

    size_t length() const;

    const float* data() const;

    float* multable_data();


    void MemCopyTo(float* dest);
    std::size_t size() const;
	

	inline void Negate(){
		for (int i = 0; i < data_.size(); i++)
			data_[i] = 0 - data_[i];
	}

 private:
    std::vector<float> data_;
};

JCJArray operator+(const JCJArray& left, const JCJArray& right);
JCJArray operator+(const JCJArray& left, int right);
JCJArray operator+(int left, const JCJArray& right);

JCJArray operator-(const JCJArray& left, const JCJArray& right);
JCJArray operator-(const JCJArray& left, int right);
JCJArray operator-(int left, const JCJArray& right);

JCJArray operator*(const JCJArray& left, const JCJArray& right);
JCJArray operator*(const JCJArray& left, int right);
JCJArray operator*(int left, const JCJArray& right);

JCJArray operator/(const JCJArray& left, const JCJArray& right);
JCJArray operator/(const JCJArray& left, int right);
JCJArray operator/(int left, const JCJArray& right);

JCJArray operator>(const JCJArray& left, const JCJArray& right);
JCJArray operator>(const JCJArray& left, int right);
JCJArray operator>(int left, const JCJArray& right);

JCJArray operator<(const JCJArray& left, const JCJArray& right);
JCJArray operator<(const JCJArray& left, int right);
JCJArray operator<(int left, const JCJArray& right);

JCJArray operator<=(const JCJArray& left, const JCJArray& right);
JCJArray operator<=(const JCJArray& left, int right);
JCJArray operator<=(int left, const JCJArray& right);

JCJArray operator>=(const JCJArray& left, const JCJArray& right);
JCJArray operator>=(const JCJArray& left, int right);
JCJArray operator>=(int left, const JCJArray& right);

JCJArray operator&&(const JCJArray& left, const JCJArray& right);
JCJArray operator&&(const JCJArray& left, int right);
JCJArray operator&&(int left, const JCJArray& right);

JCJArray operator||(const JCJArray& left, const JCJArray& right);
JCJArray operator||(const JCJArray& left, int right);
JCJArray operator||(int left, const JCJArray& right);

JCJArray operator!=(const JCJArray& left, const JCJArray& right);
JCJArray operator!=(const JCJArray& left, int right);
JCJArray operator!=(int left, const JCJArray& right);

JCJArray operator==(const JCJArray& left, const JCJArray& right);
JCJArray operator==(const JCJArray& left, int right);
JCJArray operator==(int left, const JCJArray& right);

JCJArray operator!(const JCJArray& left);

JCJArray JCJEMA(const JCJArray& input, int number);

JCJArray JCJCross(const JCJArray& left, const JCJArray& right);

JCJArray JCJRef(const JCJArray& input, int ref);

JCJArray JCJRef(const JCJArray& left, const JCJArray& right);

JCJArray JCJBarsLast(const JCJArray& input);

JCJArray JCJLLV(const JCJArray& left, const JCJArray& right);

JCJArray JCJLLV(const JCJArray& left, int right_num);

JCJArray JCJNot(const JCJArray& input);

JCJArray JCJCount(const JCJArray& left, const JCJArray& right);

JCJArray JCJHHV(const JCJArray& left, const JCJArray& right);

JCJArray JCJSMA(const JCJArray& x, const JCJArray& n, const JCJArray& m);
JCJArray JCJSMA(const JCJArray& x, int n, int m);

JCJArray JCJAbs(const JCJArray& in);

JCJArray JCJMax(const JCJArray& left, const JCJArray& right);

JCJArray JCJMax(const JCJArray& left, int right);

JCJArray JCJIf(const JCJArray& cond, const JCJArray& t, int f);

JCJArray JCJMA(const JCJArray& x, int n);

JCJArray JCJBackSet(const JCJArray& x, int n);

JCJArray JCJWiner(const JCJArray& x, const JCJArray& volume, const JCJArray& high, const JCJArray& low, const JCJArray& cirle_capital);

#endif /* JCJ_UTILS_H_ */
