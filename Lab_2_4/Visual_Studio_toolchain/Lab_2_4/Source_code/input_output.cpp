/*input_output.cpp
-----------------------------------
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
/*我們需要vector的定義*/
#include "input_output.h"

/*我們需要檔案輸出輸入的類別*/
#include <fstream>

/*我們需要string的定義*/
#include <string>

/*我們需要輸出輸入的類別*/
#include <iostream>

/*我們需要portable的EOL函式*/
#include "portableEOLalgorithm/portableEOLalgorithm.h"

/*我們需要列出當前作用中目錄的函式*/
#include "List_directory_files/listDirectoryFiles.h"

/*我們需要一些提示訊息*/
#include "Messages_templates/zh_TW.h"

/*我們需要存取專案的偵錯設定*/
#include "Project_specific_configurations/Debug.h"


/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*讀取raw1.dat格式檔案的函式*/
short readFile(vector<DataRecord> &data_array)
{
  /*用來保存使用者輸入檔案名稱的字串*/
  string filename;

  /*用來開啟檔案的stream object*/
  ifstream input_file;

  /*保存總資料筆數的變數*/
  unsigned total;

  /*counter*/
  unsigned i;

  /*用來保存從檔案讀取到的datarecord*/
  DataRecord read_temp;

  /*跟使用者要求檔案名稱*/
  listDirectoryFiles();
  cout << PROMPT_FILE_CURRENT_DIR
       << PROMPT_FILE_OPEN;
  cin >> filename;
  skipEOLsequence(cin);

#ifdef DEBUG
  cout << DEBUG_TAG << "filename = \"" << filename << "\"" << endl;;
#endif
  /*開啟檔案*/
  input_file.open(filename.c_str(), ifstream::in);
  if(input_file.is_open()){
    /*檔案開啟成功，開始存取檔案*/
    /*讀取第1行：總資料筆數*/
    input_file >> total;
    skipEOLsequence(input_file);
#ifdef DEBUG
    cout << DEBUG_TAG << "total = " << total << endl;
#endif

    /*批量讀取檔案資料到vector中*/
    for(i = 0; i < total; ++i){
      /*將資料讀到read_temp中*/
      read_temp.lineNumber = i;
      input_file >> read_temp.value;

      /*將read temp push 至vector中*/
      data_array.push_back(read_temp);

#ifdef DEBUG
      cout << DEBUG_TAG << read_temp.lineNumber << ' ' << read_temp.value << endl;
#endif
    }

    /*關閉檔案*/
    input_file.close();
  }else{
    /*開啟檔案失敗*/
    cout << ERROR_FILE_OPEN_FAIL;
    return -1;
  }
#ifdef DEBUG
  cout << DEBUG_TAG << "vector目前保存的資料筆數為" << data_array.size() << "筆。" << endl;
  cout << DEBUG_TAG << "vector目前的大小為" << data_array.capacity() << "筆資料的大小。" << endl;
#endif
  /*完成*/
  return 0;
}
