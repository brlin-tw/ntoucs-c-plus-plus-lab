﻿/*University.cpp
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
  University.cpp is part of Lab 6-2
  This software is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This software is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this software.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*大學ADT*/
#include "University.h"

/*Standard C++ Library*/
#include <vector>
using namespace std;

/* Ｖ字龍的Ｃ＋＋函式庫蒐集 */
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式和函式雛型(Function & Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/


University::University() {

}

/* 從resource/ntou1.txt檔案格式的檔案讀取資料並建構University物件
 * 的constructor
 *
 * 參數
 * 　infile 資料檔案的stream
 */
University::University(ifstream &universityData)
{
  /* 讀取大學名稱 */
  portableGetline(universityData, m_name);

  /* 建立底下的Department */{
    unsigned numberOfColleges;

    universityData >> numberOfColleges;
    skipEOLsequence(universityData);

    for(register unsigned i = 0; i < numberOfColleges; ++i){
      m_colleges.push_back(new (nothrow) College(universityData));
    }
  }

}
University::~University() {

  /* 解構所有的學院 */
  for(vector<College *>::iterator i = m_colleges.begin();
      i < m_colleges.end(); ++i){
    delete *i;
  }

}

