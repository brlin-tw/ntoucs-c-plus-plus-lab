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

    return 0;  // indicates successful terminhttps://docs.google.com/?tab=Xo&authuser=0#homeation
}





// determine most frequent data value
/*freq陣列：*/
void mode(int freq[], int dataArray[], int arraySize)
{
    int /*i,*/ j, k;
    int rating;
    int largest = 0;    // represents largest frequency
    int modeValue = 0;  // represents most frequent response

    printf("\n********\n  Mode\n********\n");

    // calculate the occuring frequency of data
    /* 將frequency陣列初始化為0 */
    for ( rating = 1; rating <= 9; rating++ ) {
      freq[ rating ] = 0;
    } /* end for */

    /* 總結frequency陣列 */
    for ( j = 0; j < arraySize; j++ ) {
      ++freq[ dataArray[ j ]];
    } /* end for */

    // output headers for result columns
    printf("Data  Frequency       Histogram\n"
           "                                1    1    2    2\n"
           "                           5    0    5    0    5\n\n");

    // output results
    for (rating = 1; rating <= 9; rating++) {
        printf("%4d%10d         ", rating, freq[rating]);

        // keep track of mode value and largest fequency value
        if (freq[rating] > largest)
        {
            largest = freq[rating];
            modeValue = rating;
        }

        // output histogram bar representing frequency value
        for (k = 1; k <= freq[rating]; k++)
            printf("*");
        printf("\n");
    }

    // display the mode value
    printf("The mode is the most frequent value.\n"
           "For this run the mode is %d which "
           "occurred %d times.\n", modeValue, largest);
}

