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
#include <cassert>
#include <iostream>
using namespace std;
/*|||||常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
StudentList::StudentList()
  :_head(NULL), _tail(NULL), size(0){
}

StudentList::~StudentList(){
  /* 情況 - 列表中無資料 */
  if(_head == NULL){
    return;
  }else/* 情況 - 列表中有資料 */{
    StudentList::Node *next = NULL;
    for(StudentList::Node *i = _head; i != NULL; i = next){
      next = i->_next;
      assert(i != NULL);
      delete i;
    }
  }
}

short StudentList::appendEntry(Student *newStudent){
  Node *new_node = new (nothrow)Node(newStudent);
  if(new_node == NULL){
    cout << ERROR_TAG << ERROR_MEMORY_ALLOCATION_FAIL;
    return -1;
  }

  if(/* 狀況 - list中沒有節點 */
      _head == NULL){
    _head = _tail = new_node;
  }/* 狀況 - list中有節點 */else{
    _tail->_next = new_node;
    _tail = new_node;
  }
  ++size;
  /* 完成appendEntry操作 */
  return 0;
}

Student * StudentList::find(string id)const{
  for(StudentList::Node *iter = _head;
      iter != NULL;
      iter = iter->_next){
    if(iter->_data->equal(id)){
      return iter->_data;
    }
  }
  return NULL;
}

/* 刪除列表中指定學生的函式
 * 參數 | Parameters
 *   id - 學生ID
 * 回傳值
 *   刪除成功與否 */
bool StudentList::deleteEntry(const char *id){
  //string temp(id);

  /* 狀況 - 列表是空的 */
  if(_head == NULL){
    return false;
  }else if(_head == _tail){
    /* 狀況 - 只有一名學生 */
    if(_head->_data->equal(id)){
      assert(_head != NULL);
      delete _head;
      _head = _tail = NULL;
      --size;
      return true;
    }else{
      return false;
    }
  }else{
    StudentList::Node *newHead = NULL;
    /* 狀況 - 有兩名學生或以上
     * 由於是uniLinkedList所以需要兩個ptr指向前一個學生與現在判斷的學生
     * 第一個學生與其他學生分開來檢查 */
    if(_head->_data->equal(id)){
      newHead = _head->_next;
      assert(_head != NULL);
      delete _head;
      _head = newHead;
      --size;
      return true;
    }else{
      StudentList::Node *previous, *current, *newNext = NULL;
      for(previous = _head, current = _head->_next;
          current != NULL;
          previous = previous->_next, current = current->_next){
        if(current->_data->equal(id)){
          newNext = current->_next;
          assert(current != NULL);
          delete current;
          previous->_next = newNext;
          current = newNext;
          --size;
          return true;
        }
      }
    }
  }
  /* 沒找到指定學生 */
  return false;
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

  /* 測試find()跟deleteEntry()跟size() */{
    StudentList sList;
    sList.appendEntry(new Student("Mary Chen", "111111111",
                                  "0933111111", "Business"));
    sList.appendEntry(new Student("John Wang", "222222222",
                                  "0928222222",
                                  "Computer Science"));
    assert(2 == sList.size);
    sList.appendEntry(new Student("Mel Lee", "333333333",
                                  "0968333333",
                                  "Mechanical Engineering"));
    sList.appendEntry(new Student("Bob Tsai", "444444444",
                                  "0930444444",
                                  "Electrical Engineering"));
    sList.appendEntry(new Student("Ron Yang", "555555555",
                                  "0918555555",
                                  "Computer Science"));
    assert(5 == sList.size);
    sList.find("222222222")->display(cout); cout << endl;

    if (sList.deleteEntry((const char*)"444444444"))
        cout << "Bob Tsai's entry deleted successfully!\n";
    else
        cout << "Bob Tsai's entry deletion failed!\n";
    assert(4 == sList.size);
    if (sList.find("444444444") == 0)
        cout << "Can not fine Bob Tsai's entry!\n";
  }

  cout << "================================" << endl;

  /* 測試Iterator */{

  }
  cout << "============元件測試結束==========" << endl;
  return;
}

/* 以陣列下標方式存取列表內學生的成員函式
Student *& StudentList::operator[](int index) const{
  for(unsigned i = 0; i < index; ++i){

  }
} */


StudentList::Node::Node(Student *data)
  :_data(data), _next(NULL){
}

StudentList::Node::~Node(){
  assert(_data != NULL);
  delete _data;
}

StudentList::Iterator::Iterator(StudentList &list)
  :_iterator(list._head), _list(&list){
}

StudentList::Iterator::~Iterator(){
}

void StudentList::Iterator::reset(){
  _iterator = _list->_head;
  return;
}

/* 將iterator移到下一個Student的成員函式 */
void StudentList::Iterator::next(){
  /* 情況
   * 　列表是空的 - error return
   * 　列表僅有一位學生 - error return
   * 　函式有多於一位學生，Iterator指向最後一個學生 - error return
   * 　還是有多於一位學生，Iterator指向非最後一個學生 - assign iterator
   */
  if(hasMoreRecord()){
  _iterator = _iterator->_next;
  return;
  }else{
    cerr << ERROR_TAG << STUDENT_LIST_TAG
         << "偵測到程式錯誤的試圖存取不存在的資料！" << endl;
  }
}

/* 判斷Iterator指向的學生的後面是否還有學生的函式 */
bool StudentList::Iterator::hasMoreRecord() {
  /* 情況
   * 　列表是空的 - false
   * 　列表僅有一位學生 - false
   * 　函式有多於一位學生，Iterator指向最後一個學生 - false
   * 　還是有多於一位學生，Iterator指向非最後一個學生 - true
   */
  return _iterator != _list->_tail;
}

/* dereference iterator to get node */
Student & StudentList::Iterator::operator*() {
  /* 狀況
   *   列表是空的 - errorly return _notexist student
   *   列表不是空的 - return student reference
   */
  if(_list->size == 0){
    cerr << ERROR_TAG << STUDENT_LIST_TAG
         << "偵測到違法的Iterator dereference操作" << endl;
    /* FIXME : Source_code/StudentList.cpp:272: undefined reference to `StudentList::Iterator::_notexist'
collect2: ld returned 1 exit status
    return _notexist;*/
  }
  return *(_iterator->_data);
}
