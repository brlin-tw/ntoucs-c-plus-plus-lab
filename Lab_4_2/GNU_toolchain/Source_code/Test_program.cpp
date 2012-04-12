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
  Test_program.cpp is part of Lab_4_2
  Lab_4_2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_4_2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_4_2.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/**/
#include <cstdlib>

/**/
#include "pauseProgram/Pause_program.h"

/*complex number*/
#include "Complex_number_abstract_data_structure/Complex.h"

/**/
#include <fstream>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;

int main()
{
/*用來重新運行程式的label*/
restart_program:

  /*unit test*/
  CComplex::unitTest();

  /*步驟五*/
  {
    CComplex x;

    x.setValue(3, 4);

    ofstream file("outputfile.txt", ios::out);

    file << x; // 在檔案裡寫入 3 + 4 i
  }


  /*步驟六*/
  {
    CComplex x, y;

    x.setValue(3, 4); y.setValue(5, 6);

    operator<<(operator<<(operator<<(operator<<(operator<<(cout, '('), x) , ")*(") , y), ')') << endl;

  }

  /*步驟七*/
  {
    CComplex x1, x2;

    x1.setValue(3.22, -4.19);
    x2.setValue(-3.1415, 200);

    operator<<(&cout, x1);

    *operator<<(&cout, x1) << endl;
    *operator<<(operator<<(&cout, x1), x2) << endl;

  }
  /*暫停程式運行（於main函式中）*/
  if(pauseProgram() == 1){
    goto restart_program;
  }

  /**/
  return EXIT_SUCCESS;
}
