/*Solve_equations_algorithms.cpp
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
  Solve_equations_algorithms.cpp is part of Solve_equations_algorithms
  Solve_equations_algorithms is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Solve_equations_algorithms is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Solve_equations_algorithms.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要Complex類別的定義*/
#include "../Complex_number_abstract_data_structure/Complex.h"

/*我們需要浮點數等於零判斷*/
#include "../Project_specific_configurations/Math.h"

/*我們需要console輸出*/
#include <iostream>

/*我們需要預設的訊息*/
#include "../Messages_templates/zh_TW.h"

/*我們需要header檔案的常數*/
#include "Solve_equations_algorithms.h"

/*我們需要sqrt()*/
#include <cmath>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*使用standard namespace*/
using namespace std;

/* 解一元二次方程式的函式*/
  short solveQuadraticEquation(double a, double b, double c, CComplex& root1, CComplex& root2)
  {
    /*用來暫存資料的浮點數*/
    double tempDouble01;

    /*用來暫存資料的複數*/
    CComplex tempComplex01;


    /*如果a = 0則無解*/
    if(a < MAX_ZERO_DECISION){
      cout << ERROR_TAG << SOLVE_QUADRATIC_EQUATION_TAG
           << "根為無線大(infinity)。\n";
      return -1;
    }

    /*先解根號b平方減4ac*/
    tempDouble01 = pow(b,2) - 4 * a * c;
#ifdef DEBUG
    cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
         << "square(b) - 4ac = " << tempDouble01 << endl;
#endif

    if(tempDouble01 == 0){
      /*如果b平方減4ac為零則重根2a分之-b*/
#ifdef DEBUG
      cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
           << "判斷方程式有兩相等實根。" << endl;
#endif
      root1.setValue((-b) / (2 * a), 0);
      root2.setValue((-b) / (2 * a), 0);
    }else if(tempDouble01 > 0){
      /*如果是正數的話就直接算出實數部份之後賦值給兩根*/
#ifdef DEBUG
      cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
           << "判斷方程式有兩相異實根。" << endl;
#endif
      tempDouble01 = sqrt(tempDouble01);
      root1.setValue((-b + tempDouble01) / (2 * a), 0);
      root2.setValue((-b - tempDouble01) / (2 * a), 0);
    }else{
      /*計算虛數解*/
#ifdef DEBUG
      cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
           << "判斷方程式有兩相異虛根。" << endl;
#endif
      /*i的係數*/
      tempDouble01 = sqrt(-tempDouble01);
      /*-b + ni*/
      root1.setValue(-b, tempDouble01);

      /*/2a*/
      tempComplex01.setValue(2 * a, 0);
      if(root1.divide(tempComplex01) == false){
        cout << ERROR_TAG << SOLVE_QUADRATIC_EQUATION_TAG
             << "複數除法出現開發者未預料到的問題，解方程式失敗！" << endl;
        return -1;
      }

      /*-b - ni*/
      root2.setValue(-b, -tempDouble01);
      tempComplex01.setValue(2 * a, 0);
      if(root2.divide(tempComplex01) == false){
        cout << ERROR_TAG << SOLVE_QUADRATIC_EQUATION_TAG
             << "複數除法出現開發者未預料到的問題，解方程式失敗！" << endl;
        return -1;
      }
    }
#ifdef DEBUG
    cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
         << "根1 = "; root1.print(); cout << endl;

    cout << DEBUG_TAG << SOLVE_QUADRATIC_EQUATION_TAG
         << "根2 = "; root2.print(); cout << endl;
#endif
    /*正常運作*/
    return 0;
  }
