/*Input_output.cpp
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
  Input_output.cpp is part of Lab_6_2
  Lab_6_2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_6_2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_6_2.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*Vdragon's C_CPP_Libraries_Collection*/
#include "Operate_resources_helper/Operate_file_CPP.h"
#include "Messages_templates/zh_TW.h"

/*大學ADT*/
#include "University.h"

/*標準C++函式庫*/
#include <string>
#include <iostream>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/* 讀取含有大學資料檔案的函式 */
short importData(University *university)
{
  string filename;
  ifstream universityData;

  askFile(filename);
  if(openFile(filename, "r", universityData) == -1){
    cerr << ERROR_TAG << "無法匯入大學資料！" << endl;
    return -1;
  }
  /* 開始讀取檔案 */
  university = new University(universityData);

  /* 關閉檔案 */
  closeFile(filename, universityData);
  /*成功完成*/
  return 0;
}
