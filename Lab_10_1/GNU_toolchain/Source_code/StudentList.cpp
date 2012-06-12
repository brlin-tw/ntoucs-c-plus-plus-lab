/* StudentList.cpp
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
 StudentList.cpp is part of CPP_Lab_10_1
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
#include "StudentList.hpp"
#include "Student.hpp"

/* Vdragon's Library Collection */
#include "Messages_templates/zh_TW.h"
#include "Random_name_generator/Random_name_generator.h"

/*Standard C++ Library */
#include <cstdlib>
#include <ctime>

/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
StudentList::StudentList(){
  _tail = _head = NULL;
}

StudentList::~StudentList(){
  /* 情況 - 列表中無資料 */
  if(_head == NULL){
    return;
  }else/* 情況 - 列表中有資料 */{
    StudentList::Node *next = NULL;
    for(StudentList::Node *i = _head; i != NULL; i = next){
      next = _head->_next;
      delete i;
    }
  }
}

StudentList::Node::Node(Student *data){
  _data = data;
  _next = NULL;
}

StudentList::Node::~Node(){
  delete _data;
}

short StudentList::appendEntry(Student *newStudent){
  Node *new_item = new (nothrow)Node(newStudent);
  if(new_item == NULL){
    cout << ERROR_TAG << ERROR_MEMORY_ALLOCATION_FAIL;
    return -1;
  }

  if(/* 狀況Ａ - list中沒有節點 */
      _head == NULL){
    _head = _tail = new_item;
  }/* 狀況Ｂ - list中有節點 */else{
    _tail->_next = new_item;
  }

  /* 完成appendEntry操作 */
  return 0;
}

void StudentList::unitTest(){
  cout << "====學生列表抽象資料類型元件測試====" << endl;
  /* 測試appendEntry()跟destructor */{
    char name_temp[11];

    srand(time(NULL));
    for(short i = 0; i < 15; ++i){
      generateRandomChineseName(name_temp);
      Student *student_temp_ref = new Student(name_temp, "A200799088", "0483726938", "中興大學資訊工程學系");
      StudentList list;
      student_temp_ref->display(cout);

      list.appendEntry(student_temp_ref);
    }
  }
  cout << "================================" << endl;
  return;
}
