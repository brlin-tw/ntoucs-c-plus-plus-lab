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

void readFile(unsigned *dataSize, int data[], unsigned dataSizeMax)
{
     unsigned i;
     FILE *fp;
     char filename[30];

     printf("Input the file name: ");
     gets(filename);

     fp = fopen(filename, "rt");
     /*假設讀取檔案存在*/
     assert(fp != NULL);
     fscanf(fp, "%u", dataSize);

     /*假設資料大小小於陣列最大大小*/
     assert(*dataSize <= dataSizeMax);

     for (i=0; i < *dataSize; i++){
        fscanf(fp, "%d", &data[i]);
        /*假設讀取到的資料都在 1 和 9 之間*/
        assert(data[i] >=1 && data[i] <= 9);
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

