/*main.cpp
-----------------------------------
程式框架版本(program framework version)：A
程式框架修訂號(program framework revision number)：201109251624
更新紀錄(changelog)：
  Changelog is now stored on github.
已知問題(known issues)：
  Known issues is now stored on github.
待辦事項(Todo)：
  Todo is now stored on github.
*/
/*智慧財產授權條款：
  *************************************************************************
 * (C) Copyright 1992-2007 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/
/*是否顯示偵錯數據（０為否）？*/
/*#define SHOW_DEBUG_MESSAGE*/

/*編譯ＯＳ種類：
Windows console = 0, Linux console = 1, Symbian console = 2, PSP console = 3*/
#define SYSTEM_CATEGORY 0

#define DEBUG

/*////////程式所include的標頭檔(Included Headers)////////*/
#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "statistics.h"
/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

#define DATASIZE 150
/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/

// This program is supposed to compute the mean, median and mode
// of the data. In addition, this program print out the sorted
// data according to the computed statistics

int main()
{
    int dataSize;
    int frequency[10] = {0};
    int data[DATASIZE];


    /*測試當前的工作目錄為何？*/
    #ifdef SHOW_DEBUG_MESSAGE
    printf("\n====偵錯用資訊======\n");
    printf("目前的工作目錄為：\n");
    if(SYSTEM_CATEGORY == 0){
        system("dir");
    }
    else{
        system("ls -l");
    }
    printf("\n==================\n"
           "請按Enter鍵繼續...");
    getchar();
    #endif

    // reading file
    readFile(&dataSize, data);


    // process responses
    mean(data, dataSize);
    median(data, dataSize);
    mode(frequency, data, dataSize);


    return 0;  // indicates successful termination
}
