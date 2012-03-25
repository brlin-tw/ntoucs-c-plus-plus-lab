/*
 * main.h
 *
 *  Created on: 2012/3/17
 *      Author: vdragon
 */

#ifndef MAIN_H_INCLUDED
  #define MAIN_H_INCLUDED
  /*使用std namespace的identifier*/
  using namespace std;

  /*DataRecord資料結構*/
  typedef struct dataRecord{
    /*行號*/
    int lineNumber;
    /*數值*/
    int value;
  }DataRecord;

#endif /* MAIN_H_INCLUDED */
