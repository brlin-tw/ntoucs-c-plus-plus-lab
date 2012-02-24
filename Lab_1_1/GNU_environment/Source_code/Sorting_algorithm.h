#ifndef INCLUDED_SORTING_ALGORITHM_H
  #define INCLUDED_SORTING_ALGORITHM_H
  /*Insertion sort（插入式排序演算法）函式的(function prototype)*/
  void insertionSort(int array[], unsigned array_size);

  /*bubble sort（冒泡式排序演算法）函式的(function prototype)*/
  void bubbleSort(int data[],
                    const unsigned array_size,
                    int (*sortOrderBool)(int a,
                                          int b));

  /*merge sort(合併式排序演算法)函式的function prototype*/
  void mergeSort(int data[],
                  const unsigned start_index,
                  const unsigned end_index);

  /*Heap sort function prototype*/
  /*
  void heapSort(int data[],
                 const unsigned array_size,
                 );
  */
#endif