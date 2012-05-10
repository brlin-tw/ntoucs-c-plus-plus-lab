/*Pause_program.c
-----------------------------------
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

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////環境設定(Environment Settings)////////*/
/* we need project specified settings*/
#include "../Project_specific_configurations/System_category.h"

/*////////程式所include的標頭檔(Included Headers)////////*/
/* we need printf and scanf*/
  #include <stdio.h>

/* we need system() */
  #include <stdlib.h>

/*////////常數與巨集(Constants & Macros)以及其他#define指令////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////資料結構(Structures)、typedefs跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/




/*暫停運行函式*/
short int pauseProgram(void)
  {
    printf("\n------------------------------------------------\n");

    printf("顯示運行結果，程式暫停運行...\nProgram paused for displaying execution result...\n");

    {
    /*儲存輸入的字元*/
    char inputChar;

    do{
        printf("請問您要重新運行本程式嗎（Ｙ／Ｎ）？\nDo you want to execute this program again(Y/N)?");

    /*確保輸入是正確的*/
    }while(!((inputChar = getchar()) == 'y' || inputChar == 'Y'
                || inputChar == 'n' || inputChar == 'N'));

      if(inputChar == 'y' || inputChar == 'Y'){
        /*丟掉換行符號*/
        scanf("%*c");

        /*清空螢幕*/
        if(SYSTEM_CATEGORY == 0){
          system("cls");
        }
        else{
          system("clear");
        }

        /*return true*/
        return 1;
      }
    }

    /*return false*/
    return 0;
  }
