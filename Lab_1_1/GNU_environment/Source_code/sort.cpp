/*使用C的函數調用機制和namespace處理規則，而非C++的Name Mangling*/
#ifdef __cplusplus
  extern "C"{
    #include "Sorting_algorithm.h"
  }
#endif
// function that sorts an array
void sort(int a[], int size)
{
  mergeSort(a, 0, size - 1);
  return;
}
