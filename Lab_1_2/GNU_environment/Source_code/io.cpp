/**************************************************************************
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
#include <stdio.h>
#include <assert.h>

#define MAX_FILENAME_SIZE 30
#include "main.h"

void readFile(unsigned *dataSize, int data[])
{
     unsigned i, j;

     FILE *fp;
     char filename[30];


    do{
     printf("Input the file name: ");

     /*使用標準C函式fgets代替較不安全的gets()
       因為fgets()讀不到字串時fopen()會開檔失敗故無需檢查回傳
       數值*/
     fgets(filename, MAX_FILENAME_SIZE, stdin);

      /*如果遇到換行符號就改成\0*/
      for(j = 0; j < MAX_FILENAME_SIZE; j++){
        if(filename[j] == '\r' || filename[j] == '\n'){
          filename[j] = '\0';
          break;
        }
      }

    /*因為可移植性不夠所以不實作fopen的安全性加強，用C++的library來替代之
      http://stackoverflow.com/questions/2575116/fopen-fopen-s-and-writing-to-files
    */
     fp = fopen(filename, "rt");

     if(fp == NULL){
      printf("您輸入的檔案名稱不存在於您目前的工作目錄，請再次輸入一次或是按下Ctrl-C按鍵組合強行中止程式運行。\n"
             "請按Enter鍵繼續…\n");
      getchar();
      continue;
     }else{
      break;
     }

     }while(1);

      /*將讀取範圍限制在9999以內*/
     fscanf(fp, "%4u", dataSize);

     /*假設資料大小小於陣列最大大小*/
     assert(*dataSize <= MAX_DATASIZE);

     for (i=0; i < *dataSize; i++){
        fscanf(fp, "%5d", &data[i]);

        /*假設讀取到的資料都在 1 和 9 之間*/
        assert(data[i] >= 1 && data[i] <= 9);
     }


     fclose(fp);
}

// output array contents (20 values per row)
void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 20 == 0)  // begin new line every 20 values
            printf("\n");

        printf("%2d", a[i]);

    }
}

