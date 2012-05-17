/*testComplex.cpp
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/

/*////////程式所include的標頭檔(Included Headers)////////*/
/*we need CComplex declaration*/
#include "Complex.h"

/*we need assertion*/
#include <cassert>

/*we need squt()*/
#include <cmath>

/*We need error messages*/
#include "../Messages_templates/zh_TW.h"

/* We need cout*/
#include <iostream>

/* 我們需要編譯DEBUG專用的程式碼*/
#include "../Project_specific_configurations/Debug.h"


/**/
#include <iostream>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*We use standard namespace*/
using namespace std;

CComplex::CComplex(void)
{
}

CComplex::CComplex(double real, double imaginary)
{
  m_real = real;
  m_imaginary = imaginary;
  return;
}

CComplex::~CComplex(void)
{
}

/*method to set value to a CComplex*/
void CComplex::setValue(double real, double imaginary)
{
  m_real = real;
  m_imaginary = imaginary;
  return ;
}


/*method to add another CComplex to this CComplex*/
void CComplex::add(CComplex target)
{
  m_real += target.getReal();
  m_imaginary += target.getImaginary();
  /*done*/
  return ;
}

/*method to subtract another CComplex to this CComplex*/
void CComplex::subtract(CComplex target)
{
  m_real -= target.getReal();
  m_imaginary -= target.getImaginary();
  /*done*/
  return ;
}

/* 複數乘法method
 * 參數：
 *   target 乘數*/
void CComplex::multiply(CComplex target)
{

  CComplex temp1, temp2;

  /*將被乘數實數部份乘到target*/
  temp1.setValue(m_real * target.getReal(), m_real * target.getImaginary());

  /*將被乘數虛數部份乘到target*/
  temp2.setValue(-m_imaginary * target.getImaginary(), m_imaginary * target.getReal());

  /*let this reset to 0*/
  setValue(0, 0);

  /*add temp to this*/
  add(temp1);
  add(temp2);

  /*done*/
  return ;
}
/*method to divide another CComplex to this CComplex*/
bool CComplex::divide(CComplex divider)
{
  /*用來暫時保存數值的複數*/
  CComplex tempComplex01;

  /*用來暫時保存數值的double*/
    //double tempdouble01;

  /***測試例外情況階段***/
  /*被除數是零除法沒有定義*/
  if(divider.isZero()){
    cout << ERROR_TAG << COMPLEX_NUMBER_DIVISION_TAG << ERROR_DIVIDE_BY_ZERO
         << ERROR_TAG << COMPLEX_NUMBER_DIVISION_TAG << "Complex Number Division Failed!" << endl;
    return false;
  }

  /*dividend multiply with divider's complex conjugate*/
  tempComplex01.setValue(divider.getReal(), -divider.getImaginary());
  multiply(tempComplex01);

  /*, than divide the divider times divider's conjugate*/
  tempComplex01.setValue(divider.getReal(), divider.getImaginary());
  tempComplex01.toConjugate();
  tempComplex01.multiply(divider);
#ifdef DEBUG
  cout << DEBUG_TAG << COMPLEX_NUMBER_DIVISION_TAG
       << "目前數值："; print(); cout << endl;
#endif
  m_real = m_real / tempComplex01.getReal();
  m_imaginary = m_imaginary / tempComplex01.getReal();
#ifdef DEBUG
  cout << DEBUG_TAG << COMPLEX_NUMBER_DIVISION_TAG
       << "目前數值："; print(); cout << endl;
#endif
  /*successful division*/
  return true;
}
/*method to get the length of the CComplex*/
double CComplex::getMagnitude()
{
  return sqrt(m_real * m_real + m_imaginary * m_imaginary);
}

/*method to test if both complex number is equal */
bool CComplex::isEqual(CComplex target, double max_zero_limit)
{
  subtract(target);
  if(getMagnitude() < max_zero_limit){
    return true;
  }
  else{
  return false;
  }

}
/*method to get this CComplex's real fraction*/
double CComplex::getReal()
{
  return this->m_real;
}

/*method to get this CComplex's imaginary fraction*/
double CComplex::getImaginary()
{
  return this->m_imaginary;
}

/*a method to test CComplex class*/
bool CComplex::unitTest()
{
  {

    /*複數等於零method測試*/
    CComplex x1, x2, x3, x4;

    x1.setValue(0,0);
    x2.setValue(0.02, -0.14);
    x3.setValue(3,0);
    x4.setValue(0,3);

    assert(x1.isZero());
    assert(!x2.isZero());
    assert(!x3.isZero());
    assert(!x4.isZero());
#ifdef DEBUG
  cout << DEBUG_TAG << UNIT_TEST_TAG
       << "複數等於零method測試通過！" << endl;
#endif
  }
  {

    /*複數相等method測試*/
    CComplex z1, z2;

    z1.setValue(3.14159, 2.71787);
    z2.setValue(3.14159, 2.71787);
    assert("z1.isEqual(z2)");
  #ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "複數相等method測試通過！" << endl;
  #endif
  }

  {/*addition test*/
    CComplex y1, y2, y3;

    y1.setValue(3.086, -2.54);
    y2.setValue(2.968, 33.235);
    y1.add(y2);
    y3.setValue(3.086 + 2.968, -2.54 + 33.235);
    assert(y1.isEqual(y3, MAX_ZERO_LIMIT));
  #ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "複數加法method測試通過！" << endl;
  #endif
  }
  {/*複數減法測試*/
  CComplex z1, z2, z3;

  z1.setValue(3.086, -2.54);
  z2.setValue(2.968, 33.235);
  z1.subtract(z2);
  z3.setValue(3.086 - 2.968, -2.54 - 33.235);
  assert(z1.isEqual(z3, MAX_ZERO_LIMIT));
#ifdef DEBUG
  cout << DEBUG_TAG << UNIT_TEST_TAG
       << "複數減法method測試通過！" << endl;
#endif

  }

  {/*division test*/
    /*complex numbers for division*/
      CComplex x1, x2, x3;


      x1.setValue(7, 3);
  #ifdef DEBUG
      cout << DEBUG_TAG << UNIT_TEST_TAG
           << "x1 = "; x1.print(); cout <<endl;
  #endif

      x2.setValue(1, 1);
  #ifdef DEBUG
      cout << DEBUG_TAG << UNIT_TEST_TAG
           << "x2 = "; x2.print();cout <<endl;
  #endif

      x3.setValue(5, -2);
  #ifdef DEBUG
      cout << DEBUG_TAG << UNIT_TEST_TAG
           << "x1 / x2 = 5 - 2i" << endl;
  #endif

      assert(x1.divide(x2));
  #ifdef DEBUG
      cout << DEBUG_TAG << UNIT_TEST_TAG
           << "assert(x1.divide(x2)) = "; x1.print();cout <<endl;
  #endif
      assert(x1.isEqual(x3, 1e-10));
      x2.setValue(0, 0);
      assert(!x1.divide(x2));
  #ifdef DEBUG
      cout << DEBUG_TAG << UNIT_TEST_TAG
           << "複數除法method測試通過！" << endl;
  #endif
  }
  {/* 是否為實數method測試*/
    CComplex x1, x2, x3;
    x1.setValue(3, 0);
    x2.setValue(3,-3);
    x3.setValue(0,3);

    assert(x1.isReal());
    assert(!x2.isReal());
    assert(!x3.isReal());
#ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "是否為實數method測試通過！" << endl;
#endif
  }

  {/* 複製複數method測試*/
    CComplex x1, x2;
    x1.setValue(3, 0);
    x2.setValue(x1);
    assert(x1.isEqual(x2, MAX_ZERO_LIMIT));
#ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "複製複數method測試通過！" << endl;
#endif
  }

  {/* 印出複數method測試*/
    CComplex x1, x2;
#ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "印出複數method測試：" << endl;
    x1.setValue(-1.54, 3.22);
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "(-1.54 + 3.22i).print() = "; x1.print(); cout << endl;
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "(-1.54 + 3.22i).print2Stream(cout) = "; x1.print2Stream(cout); cout << endl;
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << x1 << " << (-1.54 + 3.22i)" << endl;
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "請自行檢查輸出是否正確。" << endl;
#endif
  }
  {/* overloaded operator測試*/
    CComplex x1, x2;
#ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "overloaded operator測試：" << endl;
#endif
    x1.setValue(-1.54, 3.22);
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "(-1.54 + 3.22i) = " << x1 << endl;
#ifdef DEBUG
    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "請自行檢查輸出是否正確。" << endl;
#endif
  }
  /*測試setValue功能的constructor*/
  {
    CComplex x1(1.23, -4.56), x2;
    x2.setValue(1.23, -4.56);

    assert(x1.isEqual(x2, MAX_ZERO_LIMIT));

    cout << DEBUG_TAG << UNIT_TEST_TAG
         << "setValue功能的constructor測試通過！" << endl;
  }
  /*success*/
#ifdef DEBUG
  cout << DEBUG_TAG << UNIT_TEST_TAG
       << "複數抽象資料結構單元測試完全通過！" << endl;
#endif
  return true;
}

/*method to print complex number in standard form*/
void CComplex::print()
{
  cout << m_real << " + " << m_imaginary << 'i';
  /*done*/
  return;
}

/*an inline method to check if complex number is 0,
   * originally used for divide-by-0 checking*/
inline bool CComplex::isZero()
{

  /*實虛部係數皆為零者為零*/
  return (fabs(m_real) < MAX_ZERO_LIMIT && fabs(m_imaginary) < MAX_ZERO_LIMIT);
}

/*一個inline的method用來將一個複數轉型成其共軛型式*/
inline void CComplex::toConjugate()
{
  /*將虛數部份對調正負號*/
  m_imaginary = -m_imaginary;

  /*done*/
  return;
}

/* an inline method to check if complex number is real,
 * originally used for print() format check*/
inline bool CComplex::isReal()
{
  if(fabs(m_imaginary) < MAX_ZERO_LIMIT){
    return true;
  }else{
    return false;
  }
}

/* an method to copy an 存在的複數到此複數物件中*/
void CComplex::setValue(CComplex source)
{
  setValue(source.getReal(), source.getImaginary());

  /*done*/
  return;
}

/* 將物件印到指定output stream的method
 * 此method為print()的廣域用途版本*/
void CComplex::print2Stream(ostream &output)
{
  output << m_real << " + " << m_imaginary << 'i';

  /*完成*/
  return;
}

/* overload ostream 的 << operator*/
ostream &operator<<(ostream &os, CComplex &rhs)
{


  rhs.print2Stream(os);

  return os;
}
