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
#include "io.h"
#include "sort.h"

// calculate average of all values
void mean(const int dataArray[], int arraySize)
{
    double total = 0.0;

    printf("********\n  Mean\n********\n");

    // total response values
    for (int i = 0; i < arraySize ; i++)
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


// determine most frequent data value
/*freq陣列：*/
void mode(int freq[], int dataArray[], int arraySize)
{
    int j, k;
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

