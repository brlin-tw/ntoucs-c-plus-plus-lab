/* Random_name_generator.c
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
  Random_name_generator.c is part of 亂數姓名產生器
  亂數姓名產生器 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  亂數姓名產生器 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with 亂數姓名產生器.  If not, see <http://www.gnu.org/licenses/>.
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
#include "Random_name_generator.h"

/* for random generator */
#include <stdlib.h>

/* for string manipulation */
#include <string.h>

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 隨機填入中文姓名的函式 */
void generateRandomChineseName(char name[])
{
  const char *twoSurnames[40] = {"軒轅", "歐陽", "司馬", "司徒", "司空", "司寇", "上官", "尉遲", "羊舌", "第五", "梁丘", "鍾離", "東郭", "公孫", "孟孫", "仲孫", "叔孫", "季孫", "長孫", "慕容", "宇文", "閭丘", "諸葛", "東方", "西門", "公羊", "夏侯", "万俟", "百里", "端木", "公冶", "皇甫", "呼延", "浮屠", "令狐", "淳于", "即墨", "單於", "南宮", "毌丘"};
  const char *oneNames[40] = {"轅", "陽", "馬", "徒", "空", "寇", "官", "遲", "舌", "五", "丘", "離", "郭", "孫", "孫", "孫", "孫", "孫", "孫", "容", "文", "丘", "葛", "方", "門", "羊", "侯", "俟", "里", "木", "冶", "甫", "延", "屠", "狐", "于", "墨", "於", "宮", "丘"};

  strcpy(name, twoSurnames[rand() % 40]);
  strcat(name, oneNames[rand() % 40]);
  return;
}
