/*testComplex.cpp
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin)
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
/*We need complex number class*/
#include "Complex_number_abstract_data_structure/Complex.h"

/*We need pauseProgram function*/
#include "pauseProgram/Pause_program.h"

/*We need console output method*/
#include <iostream>

/*我們需要程式名稱*/
#include "testComplex.h"

/*我們需要showSoftwareInfo() */
#include "Show_software_info/Show_software_info.h"

/*我們需要訊息標籤*/
#include "Messages_templates/zh_TW.h"

/*我們需要處理EOL*/
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/*我們需要解一元二次的函式 */
#include "Solve_equations_algorithms/Solve_equations_algorithms.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
int main()
{
  /*用來保存解方程式根的複數*/
  CComplex root1, root2;

restart_program:
  /*顯示軟體資訊*/
  show_software_info((char*)PROGRAM_NAME);

  //進行複數類別元件測試
  if(!CComplex::unitTest()){
    cout << "元件測試未通過！軟體無法繼續運行。" << endl
         << "請保留程式輸出之所有訊息以提交程式缺陷報告供軟體開發者處理這個問題。" << endl
         << "提交報告網頁地址：https://github.com/Vdragon/NTOU_CPP_Lab_Opensource_Project/issues" << endl;
  }

  /*向使用者要求a x^2 + b x + c = 0係數 a, b, c並求解*/
  {
    /*方程式的係數*/
    int a, b, c;

    cout << "a x^2 + b x + c = 0" << endl
         << "請輸入上列方程式的係數a, b, c：" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
#ifdef DEBUG
    cout << DEBUG_TAG
         << "a = " << a << ", "
         << "b = " << b << ", "
         << "c = " << c << endl;
#endif
    /*解方程式*/
    solveQuadraticEquation(a, b, c, root1, root2);
    /*移除standard input buffer中的EOL*/
    skipEOLsequence(cin);

  }

  /*顯示解*/
  cout << "x1 = " ;
  if(root1.isReal()){
    cout << root1.getReal() << endl;
  }else{
    root1.print(); cout << endl;
  }
  cout << "x2 = " ;
  if(root2.isReal()){
    cout << root2.getReal() << endl;
  }else{
    root2.print(); cout << endl;
  }

  {
    /*用來暫時存放x1, x2的複數*/
    CComplex x1temp1, x1temp2, x2temp1, x2temp2;

    /*計數器*/
    unsigned i;


    /*初始化為x1 跟x2的值*/
    x1temp1.setValue(root1.getReal(), root1.getImaginary());
    x1temp2.setValue(root1.getReal(), root1.getImaginary());
    x2temp1.setValue(root2.getReal(), root2.getImaginary());
    x2temp2.setValue(root2.getReal(), root2.getImaginary());

    /*乘以他們的次方數-1*/
    for (i = 0; i < (5 - 1); ++i) {
      x1temp1.multiply(root1);
    }
    for (i = 0; i < (5 - 1); ++i) {
      x2temp1.multiply(root2);
    }
    for (i = 0; i < (10 - 1); ++i) {
      x2temp2.multiply(root2);
    }
    for (i = 0; i < (7 - 1); ++i) {
      x1temp2.multiply(root1);
    }

    /*分母／分子分別計算*/
    x1temp1.add(x2temp1);
    x2temp2.subtract(x1temp2);

    /*最後將分子除以分母分子即為答案*/
    x1temp1.divide(x2temp2);

    /*印出左運算域*/
    cout << "((x1)^5 + (x2)^5) / ((x2)^10 - (x1)^7) = ";
    if(x1temp1.isReal()){
      cout << x1temp1.getReal();
    }else{
      x1temp1.print();
    }
  }
  if(pauseProgram() == 1){
    goto restart_program;
  }
/*end_program:*/
  return 0;
}
