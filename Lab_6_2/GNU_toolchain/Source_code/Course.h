/*Course.h*/
#ifndef COURSE_H
#define COURSE_H

/*||||| Forward declarations |||||*/
class Course;
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/**/
#include <string>
using namespace std;

/*大學ADT*/
#include "Teacher.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
class Course {
public:
  Course();
  ~Course();
private:
  string m_name;
  unsigned m_ID;
  unsigned m_year;
  unsigned m_semester;
  Teacher *teacher;

};

#endif  //_COURSE_H
