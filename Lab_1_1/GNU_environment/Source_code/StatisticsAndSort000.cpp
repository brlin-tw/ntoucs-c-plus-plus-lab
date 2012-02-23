// This program is supposed to compute the mean, median and mode
// of the data. In addition, this program print out the sorted
// data according to the computed statistics

#include <stdio.h>
#include <stdlib.h>
/*使用C的函數調用機制和名字處理規則，而非C++的Name Mangling*/
#ifdef __cplusplus
  extern "C"{
    #include "Sorting_algorithm.h"
#endif
#ifdef __cplusplus
  }
#endif
void readFile(int *dataSize, int data[]);
void mean(const int [], int);
void median(int [], int);
void mode(int [], int [], int);
void sort(int[], int);
void printArray(const int[], int);

#define DATASIZE 150
#define NDEBUG

int main()
{
    int dataSize;
    int frequency[10] = {0};
    int data[DATASIZE];


    /*測試當前的工作目錄為何？*/
    #ifdef DEBUG
    printf("\n目前的工作目錄為：\n");
    system("ls -l");
    printf("\n================\n");
    getchar();
    exit(0);
    #endif

    // reading file
    readFile(&dataSize, data);


    // process responses
    mean(data, dataSize);
    median(data, dataSize);
    mode(frequency, data, dataSize);

    return 0;  // indicates successful terminhttps://docs.google.com/?tab=Xo&authuser=0#homeation
}

void readFile(int *dataSize, int data[])
{
     int i;
     FILE *fp;
     char filename[30];

     printf("Input the file name: ");
     gets(filename);

     fp = fopen(filename, "rt");
     fscanf(fp, "%d", dataSize);
     for (i=0; i < *dataSize; i++)
          fscanf(fp, "%d", &data[i]);
     fclose(fp);
}

// calculate average of all values
void mean(const int dataArray[], int arraySize)
{
    double total = 0.0;

    printf("********\n  Mean\n********\n");

    // total response values
    for (int i = 0; i < arraySize; i++)
        total += dataArray[i];

    // format and output results
    printf("The mean is the average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all the data items divided by the number\n"
           "of data items ( %d ). The mean value for\n"
           "this run is: %f / %d = %f\n\n",
           arraySize, total, arraySize, total / arraySize);
}

// sort array and determine median element's value
void median(int dataArray[], int arraySize)
{
    printf("\n********\n Median\n********\nThe unsorted array of data is");

    printArray(dataArray, arraySize);  // output unsorted array

    sort(dataArray, arraySize);  // sort array of data

    printf("\n\nThe sorted array is");
    printArray(dataArray, arraySize);  // output sorted array

    // display median element
    printf("\n\nThe median is the %d-th element of\nthe sorted %d"
           " element array.\nFor this run the median is %d\n\n",
           arraySize/2, arraySize, dataArray[arraySize / 2]);
}


// function that sorts an array
void sort(int a[], int size)
{
  mergeSort(a, 0, size - 1);
  return;
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

