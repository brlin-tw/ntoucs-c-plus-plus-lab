/*Dice.cpp
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
  Dice.cpp is part of Lab_6_1
  Lab_6_1 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_6_1 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_6_1.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*this*/
#include "Dice.h"

/*Standard C++ Library*/
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*Ｖ字龍的函式庫蒐集 */
#include "Messages_templates/zh_TW.h"

/*////////常數與巨集(Constants & Macros)////////*/
/* 訊息 */
#define DICE_DICE_TAG "【Dice::Dice()】"

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

Dice::Dice()
{
  //預設骰子每個點數面出現機率相等
  for (int i = 0; i < 6; ++i) {
    m_probability[i] = 1/6;
  }

}

//手動設定每個骰子點數面的出現機率
Dice::Dice(double probability[])
{
  double checksum = 0;
  for(register short i = 0; i < 6; ++i){
    checksum += probability[i];
    m_probability[i] = probability[i];
  }
#ifndef NDEBUG
    cout << DEBUG_TAG << DICE_DICE_TAG
         << "checksum = " << checksum << endl;
#endif
  if(fabs(checksum - 1) > 0.001){
    cerr << ERROR_TAG << DICE_DICE_TAG
         << "骰子各個點數面的出現機率和必須為100%！" << endl
         << ERROR_TAG << DICE_DICE_TAG
         << "出現機率將重設為1/6。" << endl;
    for (register short i = 0; i < 6; ++i) {
      m_probability[i] = (double)1/6;
    }
  }
}


Dice::~Dice()
{

}

/*我們可以在任何時候丟這個骰子, 來看到它出現的點數*/
short Dice::randomThrow()
{
  /* 各個擲出點數面的判定界線
   * 有效索引值：0(0)~6(RAND_MAX) */
  unsigned division[7];
  /* 擲出結果 */
  int result = 0;

  /* 決定判斷界線 */{
    double temp = 0;
    division[0] = 0;
    for(int i = 1; i <= 5; ++i){
      temp += m_probability[i - 1];
      division[i] = RAND_MAX * temp;
    }
    division[6] = RAND_MAX;
  }

  /* 抽出亂數值（介於0和RAND_MAX之間），判定擲出之骰面 */{
    unsigned random = rand();

    for(register short i = 1; i <= 6; ++i){
      if(random <= division[i]){
        result = i;
      }
    }
  }
  assert(result >= 1 && result <= 6);
  return result;
}

/*元件測試模組
 * 回傳值
 *  真 - 成功
 *  非 - 失敗
 */
bool unitTest()
{
  /* 測試建構元(constructor)*/{
    /*沒有可以測試的項目*/
  }


  //測試成功
  cout << DICE_UNITTEST_TAG
       << "元件測試全部通過！" << endl;
  return true;
}
