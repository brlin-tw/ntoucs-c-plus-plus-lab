/* Test_program.cpp
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
  Test_program.cpp is part of CPP_Lab_10_1
  CPP_Lab_10_1 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  CPP_Lab_10_1 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with CPP_Lab_10_1.  If not, see <http://www.gnu.org/licenses/>.
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* 學生抽像資料類型 */
#include "Student.hpp"

/* 學生列表抽像資料類型 */
#include "StudentList.hpp"

/* Standard C++ Library */
#include <cstdlib>
#include <iostream>
using namespace std;

/* Vdragon's Library Collection */
#include "pauseProgram/Pause_program.h"

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
int main(int argc, char *argv[])
{
  restart_program:
  Student::unitTest();
  StudentList::unitTest();

  StudentList sList;
  sList.appendEntry(new Student("Mary Chen", "111111111",
                                "0933111111", "Business"));
  sList.appendEntry(new Student("John Wang", "222222222",
                                "0928222222",
                                "Computer Science"));
  sList.appendEntry(new Student("Mel Lee", "333333333",
                                "0968333333",
                                "Mechanical Engineering"));
  sList.appendEntry(new Student("Bob Tsai", "444444444",
                                "0930444444",
                                "Electrical Engineering"));
  sList.appendEntry(new Student("Ron Yang", "555555555",
                                "0918555555",
                                "Computer Science"));

  sList.find("222222222")->display(cout); cout << endl;

  if (sList.deleteEntry("444444444"))
      cout << "Bob Tsai's entry deleted successfully!\n";
  else
      cout << "Bob Tsai's entry deletion failed!\n";

  if (sList.find("444444444") == 0)
      cout << "Can not fine Bob Tsai's entry!\n";

  if(1 == pauseProgram()){
    goto restart_program;
  }
  return EXIT_SUCCESS;
}
