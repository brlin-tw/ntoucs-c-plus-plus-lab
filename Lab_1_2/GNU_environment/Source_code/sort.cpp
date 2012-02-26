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
/*排序演算法header*/
#include "Sorting_algorithm.h"
#include <assert.h>

/*checkSortedInt函式：確定int排序演算法沒有出錯
    auguments:
      sorted_data：應該要被排序的int資料陣列
      size：陣列大小
    回傳數值：
      -1：排序有問題
      0：排序正常*/
short checkSortedInt(int sorted_data[], unsigned size);

// function that sorts an array
void sort(int a[], int size)
{
  mergeSort(a, 0, size - 1);
  assert(checkSortedInt(a, size) == 0);
  /*假設排序沒有問題*/

  return;
}

short checkSortedInt(int sorted_data[], unsigned size)
{
  unsigned i;

  for(i = 0; i < size - 1; i++){
    if(sorted_data[i] > sorted_data[i + 1]){
      return -1;/*排序異常*/
    }
  }
  return 0;/*排序正常*/
}
