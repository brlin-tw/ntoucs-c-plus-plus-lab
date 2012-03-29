#ifndef COMPLEX_H_INCLUDED
  #define COMPLEX_H_INCLUDED
  /* 如果浮點數小於這個常數就會被視為等於零
   * 注意：設成太小的數值可能導致問題。*/
  #define MAX_ZERO_LIMIT 0.0000001

  /* 標示目前執行位置的標籤*/
  #define COMPLEX_NUMBER_DIVISION_TAG "【複數除法模組】"
  #define UNIT_TEST_TAG "【元件測試模組】"

  /**/
  #include <iostream>
  using namespace std;


  /*複數物件類別*/
  class CComplex
  {
  public:
    CComplex(void);

    virtual ~CComplex(void);

    /*計算模塊*/
    /*method to assign value to a CComplex*/
    void setValue(double real, double imaginary);
    /* an method to copy an 存在的複數到此複數物件中*/
    void setValue(CComplex &source);
    /*method to add another CComplex to this CComplex*/
    void add(CComplex target);
    /*method to subtract another CComplex to this CComplex*/
    void subtract(CComplex target);
    /*method to multiply another CComplex to this CComplex*/
    void multiply(CComplex target);
    /*method to divide another CComplex to this CComplex*/
    bool divide(CComplex divider);
    /*method to test if both complex number is equal */
    bool isEqual(CComplex target, double max_zero_limit);
    /*an inline method to check if complex number is 0,
     * originally used for divide-by-0 checking*/
    inline bool isZero();
    /*一個inline的method用來將一個複數轉型成其共軛型式*/
    inline void toConjugate();
    /* an inline method to check if complex number is real,
     * originally used for print() format check*/
    inline bool isReal();

    /*取值模組*/
    /*method to get this CComplex's real fraction*/
    double getReal();
    /*method to get this CComplex's imaginary fraction*/
    double getImaginary();
    /*method to get the length of the CComplex*/
    double getMagnitude();

    /*輸出輸入模組*/
    /* method to print complex number in standard form to standard output.
     * this method is DEPRECATED, use print2Stream() instead.*/
    void print();
    /* 將物件印到output stream的method
     * 此method為print()的generalized版本*/
    void print2Stream(ostream &out);

    /*測試模組*/
    /*a method to test CComplex class*/
    static bool unitTest();

  private:
    /*複數的實數部份*/
    double m_real;
    /*複數的虛數部份*/
    double m_imaginary;
  };

  /* overload ostream::operator<< 的 複數insertion operator */
  ostream &operator<<(ostream &os, CComplex &rhs);


#endif

