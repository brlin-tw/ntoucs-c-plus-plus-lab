#pragma once

/* 如果浮點數小於這個常數就會被視為等於零
 * 注意：設成太小的數值可能導致問題。*/
#define MAX_ZERO_LIMIT 0.0000001

/* 標示目前執行位置的標籤標籤*/
#define COMPLEX_NUMBER_DIVISION_TAG "【複數除法模組】"
#define UNIT_TEST_TAG "【元件測試模組】"


/*We use standard namespace*/
using namespace std;

class CComplex
{
public:
  CComplex(void);
  virtual ~CComplex(void);
  /*method to set value to a CComplex*/
  void setValue(double real, double imaginary);
  /*method to add another CComplex to this CComplex*/
  void add(CComplex target);
  /*method to subtract another CComplex to this CComplex*/
  void subtract(CComplex target);
  /*method to multiply another CComplex to this CComplex*/
  void multiply(CComplex target);
  /*method to divide another CComplex to this CComplex*/
  bool divide(CComplex divider);
  /*method to get the length of the CComplex*/
  double magnitude();
  /*method to test if both complex number is equal */
  bool equal(CComplex target, double max_zero_limit);
  /*method to get this CComplex's real fraction*/
  double getReal();
  /*method to get this CComplex's imaginary fraction*/
  double getImaginary();
  /*method to print complex number in standard form*/
  void print();
  /*a method to test CComplex class*/
  static bool unitTest();
  /*an inline method to check if complex number is 0,
   * originally used for divide-by-0 checking*/
  inline bool isZero();
  /*一個inline的method用來將一個複數轉型成其共軛型式*/
  inline void toConjugate();
private:
  double m_real;
  double m_imaginary;
};


