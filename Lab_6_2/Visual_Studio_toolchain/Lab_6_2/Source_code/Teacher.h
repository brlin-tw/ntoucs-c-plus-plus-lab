#if !defined(_TEACHER_H)
#define _TEACHER_H

/*Teacher.h
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
  Teacher.h is part of Lab 6-2
  This software is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This software is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this software.  If not, see <http://www.gnu.org/licenses/>.
*/
/*||||| Forward declarations |||||*/
/* 宣告Course */
class Course;

/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/*標準C++函式庫*/
#include <string>
#include <vector>
using namespace std;

/*大學ADT*/
#include "Course.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
class Teacher {
public:
  Teacher();
  ~Teacher();
private:
  string m_name;
  /* Building file: ../Source_code/College.cpp
Invoking: GCC C++ Compiler
g++ -DDEBUG -I/usr/include -I/usr/include/i386-linux-gnu/ -I/usr/lib/gcc/i686-linux-gnu/4.6/include/ -I/usr/include/c++/4.6.1 -I/usr/include/c++/4.6.1/i686-linux-gnu/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source_code/College.d" -MT"Source_code/College.d" -o"Source_code/College.o" "../Source_code/College.cpp"
In file included from ../Source_code/Course.h:9:0,
                 from ../Source_code/Department.h:40,
                 from ../Source_code/College.h:10,
                 from ../Source_code/College.cpp:31:
../Source_code/Teacher.h:55:10: 錯誤： 「Course」 在此作用欄位中尚未宣告
   因為Course.h尚未parse至宣告Course class的位置，而本檔案第39行所include的Course.h因為include guard而
   略過此header的parsing所以會找不到Course的定義，此時需額外宣告使toolchain知道Course的存在。*/
  vector<Course *> courses;

public:

};

#endif  //_TEACHER_H
