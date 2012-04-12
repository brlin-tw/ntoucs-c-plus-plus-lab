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

using namespace std;
/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

Dice::Dice()
{

}
Dice::Dice(double probability[])
{
  double checksum = 0;
  for(short i = 0; i < 6; ++i){
    checksum += probability[i];
    m_probability[i] = probability[i];
  }
  assert(checksum - 1 < 0.0001);
}

int Dice::randomThrow()
{

  int division[5];
  double temp = 0;
  for(int i = 0; i < 5; ++i){
    temp += m_probability[i];
    division[i] = RAND_MAX * temp;
    cout << division[i];
  }

  int random = rand();
  int result;

  for(int i = 0; i < 5; ++i){
    if(random < division[i]){
      result = i;
    }
    if(i == 4){
      result = i;
    }
  }


  return result + 1;
}


Dice::~Dice()
{

}
