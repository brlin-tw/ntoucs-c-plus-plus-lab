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
 * programs or to the documentation contained in thesek books. The authors*
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/

/*////////程式所include的標頭檔(Included Headers)////////*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "main.h"
#include "io.h"
#include "statistics.h"
#include "Pause_program.h"

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
using namespace std;
// This program is supposed to compute the mean, median and mode
// of the data. In addition, this program print out the sorted
// data according to the computed statistics

int main()
{
    unsigned dataSize;
    int frequency[10] = {0};
    int data[MAX_DATASIZE];

/*program restart point*/
restart_program:

    /*呼叫ios::sync_with_stdio(), 以避免 iostream 和 stdio 各用各的緩衝區的問題*/
    ios::sync_with_stdio(true);

    /*測試當前的工作目錄為何？*/
    #ifdef SHOW_DEBUG_MESSAGE
    cout << "\n====偵錯用資訊======" << endl;
    cout <<"目前的工作目錄為：" << endl;
    if(SYSTEM_CATEGORY == 0){
        system("dir");
    }
    else{
        system("ls -l");
    }
    std::cout << std::endl << "==================" << std::endl
                            <<"請按Enter鍵繼續...";
    getchar();
    #endif

    // reading file
    readFile(&dataSize, data);


    // process responses
    mean(data, dataSize);
    median(data, dataSize);
    mode(frequency, data, dataSize);

    // pause program
    if(pauseProgram() == 1){
      goto restart_program;
    }

    return 0;  // indicates successful termination
}
