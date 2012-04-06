/*SaleItem.c
-----------------------------------
更新紀錄 | Changelog
  Changelog is now stored on GitHub
已知問題 | Known Issues
  Known issues is now stored on GitHub
待辦事項 | Todos
  Todo is now stored on GitHub
著作權宣告 | Copyright notice
  Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
  SaleItem.c is part of Lab_3_2
  Lab_3_2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Lab_3_2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Lab_3_2.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*this*/
#include "SaleItem.h"

/*Standard C Library*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
  /*狹域的印出書籍資料的函式*/
  void printBook(SaleItem *book){
    /*將原先是SaleItem *型態的指標變數強制cast成pointer to
     * Book的型態，使該指標能夠dereference Book實際存在的member 屬性 */
    Book * accessPtr = (Book *)book;

    fprintf(stdout, "書籍名稱為「%s」\n", accessPtr->title);
    fprintf(stdout, "　　作者為「%s」\n", accessPtr->author);
    fprintf(stdout, "　　出版商為「%s」\n", accessPtr->publisher);
    fprintf(stdout, "　　出版年份為「西元%hu年」\n", accessPtr->year);
    fprintf(stdout, "　　定價為「%lf」元\n", accessPtr->price);

    /*done*/
    return;
  }

/*狹域的印出雜誌資料的函式*/
void printMagazine(SaleItem *magazine)
{
  /*將原先是SaleItem *型態的指標變數強制cast成pointer to
   * Magazine的型態，使該指標能夠dereference存在於Magazine資料結構的member屬性 */
  Magazine * accessPtr = (Magazine *)magazine;

  fprintf(stdout, "雜誌名稱為「%s」\n", accessPtr->title);
  fprintf(stdout, "　　集數為「%s」\n", accessPtr->issue);
  fprintf(stdout, "　　出版年份為「西元%hu年」\n", accessPtr->year);
  fprintf(stdout, "　　出版月份為「%hu月」\n", accessPtr->month);
  fprintf(stdout, "　　出版商為「%s」\n", accessPtr->publisher);
  fprintf(stdout, "　　定價為「%lf」元\n", accessPtr->price);
  /*done*/
  return;
}

/*狹域化的印出VCD資訊的函式*/
void printVCD(SaleItem *vcd)
{
  /*將原先是SaleItem *型態的指標變數強制cast成pointer to
   * VCD的型態，使該指標能夠dereference存在於VCD資料結構的member屬性 */
  VCD * accessPtr = (VCD *) vcd;

  fprintf(stdout, "雜誌名稱為「%s」\n", accessPtr->title);
  fprintf(stdout, "　　系列的名稱為「%s」\n", accessPtr->series_title);
  fprintf(stdout, "　　演員群為「%s」\n", accessPtr->casts);
  fprintf(stdout, "　　出版年份為「西元%hu年」\n", accessPtr->year);
  fprintf(stdout, "　　製作人為「%s」\n", accessPtr->producer);
  fprintf(stdout, "　　定價為「%lf」元\n", accessPtr->price);
  /*done*/
  return;
}

/*用來做unit測試的初始化資料函式*/
void unitTestInitialize(int *nItems, SaleItem *items[])
{
  Book *bPtr;
  Magazine*mPtr;
  VCD *vPtr;

  bPtr = (Book*) malloc(sizeof(Book)); // 配置
  items[0] = (SaleItem *) bPtr; // 強制型態轉換
  bPtr->size = sizeof(Book);  // 結構佔記憶體大小
  bPtr->print = printBook;  // 指向列印本結構之函式
  strncpy(bPtr->title,
    "Harry Potter and the Prisoner of Azkaban ", 81);
  bPtr->title[80] = '\0';
  strncpy(bPtr->author, "J.K. Rowling ", 51);
  bPtr->author[50] = '\0';
  strncpy(bPtr->publisher, "Bloomsbury", 51);
  bPtr->publisher[50] = '\0';
  bPtr->year = 2000;
  bPtr->price = 7.99;

  mPtr = (Magazine*)
      malloc(sizeof(Magazine));
  items[1] = (SaleItem *) mPtr;
  mPtr->size = sizeof(Magazine);
  mPtr->print = printMagazine;
  strncpy(mPtr->title, "Reader's Digest", 81);
  mPtr->title[80] = '\0';
  strncpy(mPtr->issue, "---", 11);
  mPtr->issue[10] = '\0';
  mPtr->year = 2005;
  mPtr->month = 03;
  strncpy(mPtr->publisher,
    "The Reader's Digest Association, Inc.", 51);
  mPtr->title[50] = '\0';
  mPtr->price = 13.5;

  vPtr = (VCD*) malloc(sizeof(VCD));
  items[2] = (SaleItem *) vPtr;
  vPtr->print = printVCD;
  strncpy(vPtr->title, "The Two Towers", 81);
  vPtr->title[80] = '\0';
  strncpy(vPtr->series_title, "Lord of the Rings", 81);
  vPtr->series_title[80] = '\0';
  strncpy(vPtr->casts, "Elijah Wood, Ian Mackellen", 101);
  vPtr->casts[100] = '\0';
  vPtr->year = 2003;
  strncpy(vPtr->producer, "Entertainment in Video", 31);
  vPtr->producer[30] = '\0';
  vPtr->price = 70;

  *nItems = 3;

  /*done*/
  return;
}
