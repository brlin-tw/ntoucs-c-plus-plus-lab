/*排序演算法
-----------------------------------
程式框架版本(program framework version)：A
程式框架修訂號(program framework revision number)：201109251624
更新紀錄(changelog)：
  Changelog is now stored on github
已知問題(known issues)：
  Known issues is now stored on github
待辦事項(todo)：
  Todo is now stored on github
智慧財產授權條款：
*//* Copyright (C) 2012 林博仁(Henry Lin)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation version 2.1
 * of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*標準輸入／輸出函式庫(standard input/output library)
  版本：1.12(4)
  for printf(), scanf(), fgetc()...etc*/
#include <stdio.h>
/*or in C++*/
/*#include <cstdio>*/

/*C Standard General Utilities Library
  版本：1.01(8)*/
#include <stdlib.h>
/*or in C++*/
/*#include <cstdlib>*/

/* swap algorithm header file
 * 版本：1.00(0)
 */
#ifdef __cplusplus
extern "C"{
#endif
  #include "Swap_algorithm.h"
#ifdef __cplusplus
}
#endif

/*maxHeapify function prototype*/
void maxHeapify(int data[], unsigned array_size, unsigned current_index);

/*Insertion sort（插入式排序演算法）函式
  版本：1.02(12)
  傳入值：array整數陣列、array_size陣列大小
  傳回值：無
  */
void insertionSort(int array[], unsigned array_size)
{
  /*宣告與定義(Declaration & Definition)*/
  /*--函式雛型(function prototype)--*/

  /*--局域變數--*/
  /*當前要插入的元素*/
  int current_insert_element;

  /*－－－－－－－－－－－－－－－－－－－－－*/
  {
    int final_insert_index;

    /*處理序列中第二個物件到最後一個物件的迴圈。完成此
     * 迴圈表示序列已經完成排序。*/
    int i;
    for(i = 1; i < array_size; i++){
      /*用一個變數current_insert_element備份目前處理的物件的值。*/
      current_insert_element = array[i];

      /*用一個變數final_insert_index持有最後要插入目前處
       * 理的物件的index（索引）*/
      final_insert_index = i;

      /*從i到0尋找插入的位置（比較現在要插入的元素跟前面的元素的大小）*/
      while(final_insert_index != 0 &&
              array[final_insert_index - 1] >
              current_insert_element){
        /*將前面的元素移到後面*/
        array[final_insert_index] = array[final_insert_index - 1];
        /*判斷更前面的元素*/
        final_insert_index--;
      }

      /*插入現在要插入的元素*/
      array[final_insert_index] = current_insert_element;

    }
  }
  /*－－－－－－－－－－－－－－－－－－－－－*/
  /*傳回內容*/
  return ;
}

/*bubble sort函式
傳入參數：一個int陣列data、一個const unsigned的data
        陣列大小、一個指向提供排序順序判斷的函式的指標
傳回值：無*/
void bubbleSort(int data[],
                  const unsigned array_size,
                  int (*sortOrderBool)(int a,
                                        int b))
    {
        /*提供bubble sort遞增順序比較條件函式*/
        int sortAscendingly(int a, int b);

        /*提供bubble sort遞減順序比較條件函式*/
        int sortDescendingly(int a, int b);

        /*次數計數器*/
        unsigned times;
        unsigned compare;

        /*從最後一個數被保證排序正確至第二個數被保證排序正確*/
        for(times = array_size - 1; times >= 1; times--){
            /*從第一個數至times的前一個數取compare與compare+1開始判斷*/
            for(compare = 0; compare <= times - 1; compare++){
                /*如果compare大於compare+1就互換*/
                 if((*sortOrderBool)(data[compare], data[compare + 1])){
                    swapInt(&data[compare], &data[compare + 1]);
                 }
            }
        }
        return;
    }

/*提供bubble sort遞增順序比較條件函式*/
int sortAscendingly(int a, int b)
    {
        /*如果a小於b則不對調*/
        return (a < b)? 0 : 1;
    }

/*提供bubble sort遞減順序比較條件函式*/
int sortDescendingly(int a, int b)
    {
        /*如果a大於b則不對調*/
        return (a > b)? 0 : 1;
    }

/*合併式的排序演算法
 * 版本：1.00(0)201110052034
 * 傳入值：
 *  array
 *  start_index
 *  end_index：最後一個存在的index value
 * 傳回值：
 *  0 -> 成功
 *  -1 ->可用記憶體不足
 */
void mergeSort(int array[],
          unsigned start_index,
         unsigned end_index)
{
   int mergeAndSort(int subArray[], unsigned start_index,
         unsigned half_index, unsigned end_index);
      if(end_index > start_index){
        unsigned half_index = (start_index + end_index) / 2;

        /* split array in half and sort each half recursively */
        mergeSort( array, start_index, half_index ); /* first half */
        mergeSort( array, half_index + 1, end_index ); /* second half */
        mergeAndSort( array, start_index, half_index, end_index);
      }

}
/*合併並排序子陣列的函式*/
int mergeAndSort(int subArray[], unsigned start_index,
      unsigned half_index, unsigned end_index)
{
  /*將兩子陣列資料複製到記憶體*/
  unsigned sizeA = half_index - start_index + 1,
            sizeB = end_index - half_index;

  int *memPtrA = (int *) malloc(sizeof(int) * sizeA);

  if(memPtrA != NULL){
  }else{
    printf("失敗！請確定可用記憶體是否不足。\n");
    return -1;
  }

  {
  unsigned i;
  for(i = 0; i < sizeA; i++){
    memPtrA[i] = subArray[start_index + i];
  }

  }

  int *memPtrB = (int *) malloc(sizeof(int) * sizeB);

  if(memPtrB != NULL){
  }else{
    printf("失敗！請確定可用記憶體是否不足。\n");
    return -1;
  }

  {
  unsigned i;
  for(i = 0; i < sizeB; i++){
    memPtrB[i] = subArray[half_index + 1 + i];
  }
  }

  {
  unsigned i;
  unsigned j = 0, k = 0;
  for(i = start_index; i <= end_index; i++){
    if(j != sizeA && k != sizeB){
      if(memPtrA[j] <= memPtrB[k]){
        subArray[i] = memPtrA[j];
        j++;
      }else{
        subArray[i] = memPtrB[k];
        k++;
      }
    }else{
      if(j == sizeA){
        subArray[i] = memPtrB[k];
        k++;
      }else{
        subArray[i] = memPtrA[j];
        j++;
      }
    }
  }
  }

  /*結束前清理*/
  free(memPtrA);
  free(memPtrB);

  return 0;
}


/*maxHeapify函式
  版本：0.00(0)*/
void maxHeapify(int data[], unsigned array_size, unsigned current_index)
    {
    /*宣告與定義(Declaration & Definition)*/
    /*--函式雛型(function prototype)--*/

    /*--局域變數--*/
    /*current largest node*/
    unsigned largest_index = current_index;

    /*the child index of current node may be*/
    unsigned left_child_index = current_index * 2,
            right_child_index = current_index * 2 + 1;
    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*if left child exist and greater than current node*/
    if(left_child_index <= array_size - 1 &&
       data[left_child_index] > data[current_index]){
       largest_index = left_child_index;
    }

    /*if right child exist and greater than current node*/
    if(right_child_index <= array_size - 1 &&
       data[right_child_index] > data[current_index]){
       largest_index = right_child_index;
    }

    /*if largest node isn't current node then swap with the largest
      then maxheapify it's child*/
    if(largest_index != current_index){
      swapInt(&data[current_index], &data[largest_index]);
      maxHeapify(data, array_size, largest_index);
    }

    /*－－－－－－－－－－－－－－－－－－－－－*/
    /*傳回內容*/
    return ;
    }
