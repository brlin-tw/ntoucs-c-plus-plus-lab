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
/*#include <stdio.h>*/
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#define MAX_FILENAME_SIZE 30
#include "main.h"

using namespace std;

void readFile(unsigned *dataSize, int data[])
{
     /*counter*/
     unsigned i;

     char filename[MAX_FILENAME_SIZE];
     string dummy_buffer;

     cout << "Input the file name: ";

      /*還沒有試出來如何限制讀取字元數*/
      cin >> filename;

      /*嘗試開啟檔案*/
      ifstream in_stream(filename);

      /*assertion:檔案的fail bit 為unset
      assert(in_stream.fail() == false);*/

     if(in_stream.is_open() == false){
        cerr << "開啟檔案失敗！，請確定當前工作目錄是否存在這個檔案。" << endl;

      }

      /*讀取總數值數*/
      in_stream >> *dataSize;

      /*ignore string at the back of the number*/
      getline(in_stream, dummy_buffer);

     /*假設資料大小小於陣列最大大小*/
     assert(*dataSize <= MAX_DATASIZE);


     for (i=0; i < *dataSize; i++){
        in_stream >> data[i];

        /*ignore string at the back of the number*/
        getline(in_stream, dummy_buffer);


        /*假設讀取到的資料都在 1 和 9 之間*/
        assert(data[i] >= 1 && data[i] <= 9);
     }

      /*關檔
     fclose(fp);*/
      in_stream.close();

}

short writeFile(const unsigned dataSize, const int data[])
{
  char filename[MAX_FILENAME_SIZE];
  unsigned i;

  /*open file phase*/
  cout << "Please input the filename to output(Max." << MAX_FILENAME_SIZE << ", enter \"NONE\" to skip):";
  cin >> filename;

  if(!strcmp(filename, "NONE")){
    return 0;
  }

  ofstream output_file(filename);

  if(!output_file.is_open()){
    cout << "[ERROR] File cannot be opened!" << endl;
    return -1;
  }

  /**write file phase**/
  /*write total number*/
  output_file << dataSize << endl;

  /*write all data*/
  for(i = 0; i < dataSize; ++i){
    output_file << data[i] << endl;
  }

  /*function ran successfully*/
  return 0;
}
// output array contents (20 values per row)
void printArray(const int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 20 == 0)  // begin new line every 20 values
            cout << endl;

        /*printf("%2d", a[i]);*/
        /*設定下一個cout使用的field大小*/
        cout.width(2);
        cout << a[i];

    }
}

