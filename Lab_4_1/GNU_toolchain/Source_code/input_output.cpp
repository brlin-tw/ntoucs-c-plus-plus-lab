/*input_output.cpp
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
  input_output.cpp is part of Lab_4_1
  Lab_4_1 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_4_1 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_4_1.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要檔案輸出輸入函式*/
#include <fstream>

/*我們需要協助開檔關檔的函式*/
#include "Operate_resources_helper/Operate_file_CPP.h"

/*我們需要系統最大容許的檔案名稱大小*/
#include <cstdio>

/*我們需要複數抽象資料結構的定義*/
#include "Complex_number_abstract_data_structure/Complex.h"

/*我們需要vector資料結構的定義*/
#include <vector>

/*我們需要狀態標籤*/
#include "Messages_templates/zh_TW.h"

/*需要cout*/
#include <iostream>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/**/
using namespace std;

  /*用來讀取資料檔案的函式*/
  short readFile(vector<CComplex> *pVector)
  {
    char filename[FILENAME_MAX];
#ifdef DEBUG
    cout << DEBUG_TAG
         << "用來存放檔案名稱的陣列大小為" << FILENAME_MAX << endl;
#endif
    askFile(filename);
    /*success*/
    return 0;
  }
