/*排序演算法header*/
#include "Sorting_algorithm.h"

// function that sorts an array
void sort(int a[], int size)
{
  mergeSort(a, 0, size - 1);
  return;
}
