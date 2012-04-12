/*Course.h*/


#if !defined(_COURSE_H)
#define _COURSE_H
/**/
#include <string>
/*大學ADT*/
#include "Teacher.h"


using namespace std;

class Course {
private:
  string m_name;
  unsigned m_ID;
  unsigned m_year;
  unsigned m_semester;
  Teacher *teacher;
  Course();
  ~Course();
};

#endif  //_COURSE_H
