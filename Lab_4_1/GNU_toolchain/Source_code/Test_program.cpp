/*Test_program.cpp
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
  Test_program.cpp is part of Lab_4_1
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
/*我們需要EXIT_SUCCESS*/
#include <cstdlib>
/**/
#include <vector>
/**/
#include <cassert>
/*we need sort*/
#include <algorithm>

/**/
#include "pauseProgram/Pause_program.h"
/**/
#include "Show_software_info/Show_software_info.h"
/**/
#include "Test_program.h"
/**/
#include "Complex_number_abstract_data_structure/Complex.h"
/**/
#include "Messages_templates/zh_TW.h"

/*我們需要輸出輸入的library*/
#include "input_output.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式及函式雛型(Function & Function Prototypes)////////*/
/*用來讓sort()做遞增排序的比較函式*/
inline bool compareIncrease(CComplex first, CComplex second)
{
  /*greater*/
  if(first.getMagnitude() < second.getMagnitude()){
    return true;
  }else{
    /*lesser*/
    return false;
  }
}

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/**/
using namespace std;

int main(void)
{


/*用來重新運行程式的label*/
restart_program:
  /**/
  vector<CComplex> complex_numbers;

  /**/
  show_software_info((char *)PROGRAM_NAME);

  /*步驟二、三*/
  if(!readFile(&complex_numbers)){
#ifdef DEBUG
  vector<CComplex>::iterator complexRef01;
  unsigned count;

  cout << DEBUG_TAG << "complex_number vector目前的內容：" << endl;
  for(complexRef01 = complex_numbers.begin(), count = 0;
      complexRef01 < complex_numbers.end(); ++complexRef01, ++count){
    cout << DEBUG_TAG << "complex_number[" << count << "] = "
         << (*complexRef01) << endl;
  }
#endif
  }else{
    cout << ERROR_TAG << "讀取檔案失敗！" << endl
         << ERROR_TAG << "程式無法繼續運行。" << endl;
    goto end_program;
  }

  /*步驟四、五*/
  {
    vector<CComplex>::iterator complexRef02;
    CComplex product, answer(-8.96419, -3.24387);

    for(complexRef02 = complex_numbers.begin(); complexRef02 < complex_numbers.end(); ++complexRef02){
      if(complexRef02 == complex_numbers.begin()){
        product.setValue(*complexRef02);
        continue;
      }
      /* TODO:或許可以實作overload operator*=？*/
      product.multiply(*complexRef02);
    }
#ifdef DEBUG
    cout << DEBUG_TAG
         << "product = " << product << endl;
#endif
    assert(product.isEqual(answer, MAX_ZERO_LIMIT));
  }

  /*步驟六、七*/
  {
    /**/
    unsigned i;

    sort(complex_numbers.begin(), complex_numbers.end(), compareIncrease);

    for(i = 0; i < complex_numbers.size(); ++i){
      cout << complex_numbers[i] << endl;
    }
  }


/**/
end_program:
  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  return EXIT_SUCCESS;
}
