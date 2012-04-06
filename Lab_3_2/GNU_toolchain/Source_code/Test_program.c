/*Test_program.c
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
  Test_program.c is part of Lab_3_2
  Lab_3_2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_3_2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_3_2.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*Standard C Library*/
#include <stdlib.h>

/*Vdragons_C_CPP_Libraries_Collection*/
#include "pauseProgram/Pause_program.h"
#include "Show_software_info/Show_software_info.h"

/*SaleItem物件實作*/
#include "SaleItem.h"

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
int main(void)
{
SaleItem *items[100];

/*商品的數量*/
int nItems;

restart_program:
  show_software_info("Lab 3-2測試程式");

  unitTestInitialize(&nItems, items);

  /* 請在此處撰寫一個迴圈來列印所有 nItems 個商品
   * 的內容，這個迴圈的內容應該只有一個簡單的函式
   * 呼叫，通通透過欄位 print 這個函式指標變數來呼叫，
   * 因為此時已經將所有商品抽象化看成是一致的 SaleItem
   * 的東西了 */
  {
    unsigned i;

    for (i = 0; i < (unsigned)nItems; ++i) {
      (*items[i]).print(items[i]);
    }
  }
  {
    unsigned i;
    for (i=0; i < (unsigned)nItems; ++i)
      free(items[i]);
  }

  if(pauseProgram() == 1){
    goto restart_program;
  }
  /*成功結束*/
  return EXIT_SUCCESS;
}
