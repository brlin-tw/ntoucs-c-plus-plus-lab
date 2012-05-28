#if !defined(_INSTITUTE_H)
#define _INSTITUTE_H
/*Institute.h
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
  Institute.h is part of Lab 6-2
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
class Institute;
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/*Standard C++ Library*/
#include <string>
#include <vector>
using namespace std;

/*大學抽象資料類型*/
#include "Course.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
class Institute {
public:
  Institute();
  ~Institute();
private:
  vector<Course *> courses;
  string m_name;

};
#endif  //_INSTITUTE_H
