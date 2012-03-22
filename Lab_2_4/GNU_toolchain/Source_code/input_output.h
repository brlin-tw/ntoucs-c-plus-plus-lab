/*
 * input_output.h
 * input output function definitions
 *
 *  Created on: 2012/3/17
 *      Author: vdragon
 */
/*我們需要使用vector*/
#include <vector>

/*我們需要使用std namespace的東西*/
#include "main.h"

#ifndef INPUT_OUTPUT_H_INCLUDED
  #define INPUT_OUTPUT_H_INCLUDED
  /*讀取raw1.dat格式檔案的函式
   * 引數：
   * 　vector<DataRecord>
   * 回傳值：
   *   0－讀檔完成
   *   -1－檔案開啟失敗*/
  short readFile(vector<DataRecord> data_array);



#endif /* INPUT_OUTPUT_H_INCLUDED */
