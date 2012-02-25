#ifdef __cplusplus
extern "C"{
#endif
  #include "Sorting_algorithm.h"
#ifdef __cplusplus
}
#endif
// function that sorts an array
void sort(int a[], int size)
{
  mergeSort(a, 0, size - 1);
  return;
}
