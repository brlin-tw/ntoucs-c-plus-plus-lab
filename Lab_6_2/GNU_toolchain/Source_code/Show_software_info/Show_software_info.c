/*Show_software_info.c
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
  Show_software_info.c is part of Show_software_info
  Show_software_info is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Show_software_info is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Show_software_info.  If not, see <http://www.gnu.org/licenses/>.
*/

/*--------------程式碼開始(Code Started)--------------*/
/*--------------前期處理器指令(Preprocessor Directive)--------------*/
/*////////程式所include之函式庫的標頭檔(Included Library Headers)////////*/
/*我們需要Project_specific_configurations中定義的軟體訊息*/
#include "../Project_specific_configurations/Software_info.h"

/*我們需要printf()*/
#include <stdio.h>

/*////////常數與巨集(Constants & Macros)////////*/

/*////////其他前期處理器指令(Other Preprocessor Directives////////*/

/*--------------全域宣告與定義(Global Declaration & Definition)--------------*/
/*////////Classes、資料結構(Data Structures)、type definitions跟enumerations////////*/

/*////////函式雛型(Function Prototypes)////////*/

/*////////全域變數(Global Variables)////////*/

/*--------------主要程式碼(Main Code)--------------*/
/* 顯示軟體資訊的函式
   *  印出資訊，將控制交還給主要程式*/
void show_software_info(const char program_name[])
{
  /*顯示程式名稱及著作權宣告*/
  printf("%s\n", program_name);
  printf("Copyright " SOFTWARE_RELEASE_YEAR " " DEVELOPER_NAME "(" DEVELOPER_EMAIL ")\n");
  putchar('\n');

  /*顯示授權條款*/
  printf("%s is part of " SOFTWARE_NAME ".\n", program_name);
  printf(SOFTWARE_NAME " is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or(at your option) any later version.\n");
  putchar('\n');

  /* 顯示免責條款*/
  printf(SOFTWARE_NAME " is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.\n");
  putchar('\n');

  /*顯示附帶說明*/
  printf("You should have received a copy of the GNU Lesser General Public License along with " SOFTWARE_NAME ".  If not, see <http://www.gnu.org/licenses/>.\n");

  /*顯示分隔線*/
  printf("---------------------------------\n");
  /* 結束*/
  return ;
}
