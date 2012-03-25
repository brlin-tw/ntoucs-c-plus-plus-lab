/*main.cpp
-----------------------------------
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
著作權宣告：
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
/*我們需要vector物件*/
#include <vector>

/*我們需要輸出訊息的函式*/
#include <iostream>

/*我們需要使用暫停函式*/
#include "pauseProgram/Pause_program.h"

/*我們需要定義好的資料結構*/
#include "main.h"

/*我們需要輸出輸入用的函式*/
#include "input_output.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

int main()
{
  /*一個DataRecord的vector*/
  vector<DataRecord> recordArray;

/*用來重新開始程式的label*/
restart_program:

  /*讀取raw1.dat格式的檔案*/
  if(!readFile(recordArray)){
    cout << "讀取資料檔案結束。";

  }else{
    cout << "讀取資料檔案失敗！程式異常終止！";
    goto exit_program;
  }

/*用來結束程式的label*/
exit_program:
  /*暫停程式*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /*正常結束程式*/
  return 0;
}
