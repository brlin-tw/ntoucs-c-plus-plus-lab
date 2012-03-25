/*Skip_EOL_algorithm.cpp
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
/*we need io functions*/
#include <fstream>

/* we need iostream to output debug message*/
#include <iostream>

/*我們需要專案的設定值*/
#include "../Project_specific_configurations/Debug.h"

/*我們需要一些defined訊息*/
#include "../Messages_templates/zh_TW.h"

/*我們需要標示當前模組的字串*/
#include "portableEOLalgorithm.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*我們需要std namespace*/
using namespace std;

/*跳過stream中的換行字元序列的函式*/
short skipEOLsequence(istream& file_stream)
{
  /*用來測試的字元*/
  char test;

  /*guess first character, may be '\r'(MS-DOS later or MAC) or '\n'(Unix)*/
  test = file_stream.peek();

  switch(test){
  case '\n':
    /*if is Unix...eat it and done*/
#ifdef DEBUG
    cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
         << "吃掉[LF]" << endl;
#endif
    file_stream.ignore(1);
    /*return Unix*/
    return 1;
    break;
  case '\r':
    /*maybe MS-DOS or Mac...ignore it and peek next*/
    file_stream.ignore(1);
    test = file_stream.peek();
    if(test == '\n'){
#ifdef DEBUG
      cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
           << "吃掉[CR][LF]" << endl;
#endif
      file_stream.ignore(1);
      /*return Windows*/
      return 2;
    }
    /*return Mac*/
#ifdef DEBUG
    cout << DEBUG_TAG << SKIP_EOL_SEQUENCE_TAG
         << "吃掉[CR]" << endl;
#endif
    return 3;
    break;
  default:
    /*shouldn't be EOL else...*/
    return -1;
    break;
  }

}

/*portable getline function*/
std::istream& portableGetline(std::istream& is, std::string& t)
{
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();

    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
        case '\r':
            c = sb->sgetc();
            if(c == '\n')
                sb->sbumpc();
            return is;
        case '\n':
        case EOF:
            return is;
        default:
            t += (char)c;
        }
    }
}

void dumpInvisibleContent(string& input)
{
  /*counter*/
  unsigned i;
  char buffer;

  /*從第一個到最後一個字串字元*/
  for(i = 0; i < input.length(); ++i){
    buffer = input[i];
    switch(buffer){
    case '\n':
      cout << "[LF]";
      break;
    case '\r':
      cout << "[CR]";
      break;
    default:
      cout << buffer;
      break;
    }
  }
  /*完成*/
  return;
}
