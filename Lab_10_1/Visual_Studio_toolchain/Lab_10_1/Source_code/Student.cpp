/* Student.cpp
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
  Student.cpp is part of CPP_Lab_10_1
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
/* 學生ADT */
#include "Student.hpp"

/* 標準C++函式庫 */
#include <iostream>
#include <cstring>
using namespace std;

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
Student::Student(
    const char name[],
    const char ID[],
    const char phone[],
    const char department[]){
  _name = new (nothrow) char[51];
  strncpy(_name, name, 51); _name[50] = '\0';
  _ID = new (nothrow) char[21];
  strncpy(_ID, ID, 21); _ID[20] = '\0';
  _phone = new (nothrow) char[31];
  strncpy(_phone, phone, 31); _phone[30] = '\0';
  _department = new (nothrow) char[51];
  strncpy(_department, department, 51); _department[50] = '\0';
}

Student::~Student(){
  delete [] _name;
  delete [] _ID;
  delete [] _phone;
  delete [] _department;
}

void Student::display(ostream &output) const{
  output << "====學生資料====" << endl;
  output << "學生名稱：" << _name << endl;
  output << "學生ＩＤ：" << _ID << endl;
  output << "學生電話：" << _phone << endl;
  output << "學生系所：" << _department << endl;
  output << "===============" << endl;
  return;
}

void Student::unitTest(){
  cout << "====學生抽像資料類型元件測試====" << endl;

  /* set value constructer
   * Student::display() */{
    Student test("王大明", "A200799088", "0483726938", "中興大學資訊工程學系");
    test.display(cout);
  }

  cout << "============================" << endl;
  return;
}
