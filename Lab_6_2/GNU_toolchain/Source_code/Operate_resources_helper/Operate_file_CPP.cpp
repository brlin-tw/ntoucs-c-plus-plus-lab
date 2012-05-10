/*Operate_file_CPP.cpp
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
  Operate_file_CPP.cpp is part of Operate_resources_helper
  Operate_resources_helper is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Operate_resources_helper is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Operate_resources_helper.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*we need cout*/
#include <iostream>
/*we need file operation*/
#include <fstream>
#include <string>
#include <cstdio>

/*we need list files*/
#include "../List_directory_files/listDirectoryFiles.h"
/*askFile 需要吃EOL*/
#include "../portableEOLalgorithm/portableEOLalgorithm.h"
/**/
#include "../Messages_templates/zh_TW.h"





/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
/* 詢問欲開啟檔案的函式 */
  void askFile(string& filename)
  {
    listDirectoryFiles();
    cout << "目前工作目錄(working directory)下的檔案資訊如上，請輸入要開啟的檔案名稱：";
    cin >> filename;

    /*此時輸入stream中會有換行字元序列，我們不需要它*/
    skipEOLsequence(cin);
    /*done*/
    return;
  }

  /* 開啟檔案函式
   * 回傳值：
   *   0  關閉檔案成功
   *   -1 關閉檔案失敗*/
  short openFile(const string& filename, const char mode[], ifstream& input_file)
  {
    /* FIXME:目前無視於mode的設定直接假設開啟的檔案為RW*/
    input_file.open(filename.c_str(), fstream::in);
    if(!input_file.is_open()){
      cerr << ERROR_TAG << ERROR_FILE_OPEN_FAIL;
      DEBUG_LOCATION();
      /*檔案開啟失敗*/
      return -1;
    }
    /*開啟檔案成功*/
    return 0;
  }

  /* 關閉檔案函式
   * 回傳值：
   *   0  關閉檔案成功
   *   -1 關閉檔案失敗*/
  short closeFile(const string& filename, ifstream& input_file)
  {
    input_file.clear();
    input_file.close();
    /* FIXME:一定會進去fail()*/
    if(input_file.fail()){
      cerr << ERROR_TAG << ERROR_FILE_CLOSE_FAIL;
      DEBUG_LOCATION();
      return -1;
    }
    cout << "檔案「" << filename << "」已關閉。" << endl;
    /*success*/
    return 0;
  }
