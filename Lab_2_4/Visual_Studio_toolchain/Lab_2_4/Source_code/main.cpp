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

/*我們需要sort()函式*/
#include <algorithm>

/*我們需要定義好的訊息*/
#include "Messages_templates/zh_TW.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Data Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/
/*給sort()當作判斷依據的函式*/
inline bool compareDecrease(const DataRecord element1, const DataRecord element2)
{
  return element1.value > element2.value;
}

/*輸出vector內DataRecord 內容的函式*/
void dumpVectorDataRecord(vector<DataRecord> data);

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/*我們使用std namespace*/
using namespace std;

int main()
{

/*用來重新開始程式的label*/
restart_program:
  /*一個DataRecord的vector*/
  vector<DataRecord> recordArray;

  /*讀取raw1.dat格式的檔案*/
  if(readFile(recordArray) == 0){
    cout << "讀取資料檔案結束。" << endl;
#ifdef DEBUG_TAG
    cout << DEBUG_TAG
         << "recordArray.size() = " << recordArray.size() << endl;
#endif
  }else{
    cout << "讀取資料檔案失敗！程式異常終止！" << endl;
    goto exit_program;
  }

  /*輸出排序前資料*/
  cout << "排序前vector資料：" << endl;
  dumpVectorDataRecord(recordArray);

  /*依據value大小排序vector中的資料*/
  sort(recordArray.begin(), recordArray.end(), compareDecrease);

  /*輸出排序後資料*/
  cout << "排序後vector資料：" << endl;
  dumpVectorDataRecord(recordArray);

  /*步驟四：於recordArray中尋找目標資料*/
  {
    /*尋找目標DataRecord*/
    DataRecord goal1, goal2;
    /*用來保存find()結果的DataRecord iterator*/
    vector<DataRecord>::iterator result_iterator01;

    goal1.lineNumber = 17;
    goal1.value = 8;
    goal2.lineNumber = 60;
    goal2.value = 5;

    /*尋找goal1的位置*/
    result_iterator01 = find(recordArray.begin(), recordArray.end(), goal1);
    /*如果iterator等於recordArray.end()表示沒找到*/
    if(result_iterator01 != recordArray.end()){
      cout << "找到位於recordArray[" << result_iterator01 - recordArray.begin()
           << "]的資料{17, 8}。" << endl;
    }else{
      cout << "沒有在recordArray[]中找到資料{17, 8}。" << endl;
    }
    /*尋找goal2的位置*/
    result_iterator01 = find(recordArray.begin(), recordArray.end(), goal2);
    /*如果iterator等於recordArray.end()表示沒找到*/
    if(result_iterator01 != recordArray.end()){
      cout << "找到位於recordArray[" << result_iterator01 - recordArray.begin()
           << "]的資料{60, 5}。" << endl;
    }else{
      cout << "沒有在recordArray[]中找到資料{60, 5}。" << endl;
    }

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


/*輸出vector內DataRecord 內容的函式*/
void dumpVectorDataRecord(vector<DataRecord> data)
{
  /*計數器*/
  unsigned i;

  /*印出欄位名稱*/
  cout << "vector_index " << "orig._line_num " << "value" << endl;

#ifdef DEBUG
  cout << DEBUG_TAG
       << "data.size() = " << data.size() << endl;
#endif

  for(i = 0; i < data.size(); ++i){
    cout.width(12); cout << i << ' ';
    cout.width(14); cout << data[i].lineNumber << ' ';
    cout.width(5);  cout << data[i].value << endl;
  }
  /*完成*/
  return;
}

bool dataRecord::operator ==(const DataRecord &y)
  {

  return (lineNumber == y.lineNumber && value == y.value);
  }
