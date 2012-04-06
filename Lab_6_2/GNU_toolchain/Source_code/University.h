/*University.h*/
#if !defined(_UNIVERSITY_H)
#define _UNIVERSITY_H
/**/
#include <string>
#include <vector>

/*我們需要College的定義*/
#include "College.h"

using namespace std;

class University {
private:
  /*大學的名稱*/
  string m_name;
  /*此大學底下的所有的college
   *  TODO:使此vector改成pointer to College vector並於College解構時解構所有底下的
            College。*/
  vector <College> m_colleges;

  University();
  ~University();
};

#endif  //_UNIVERSITY_H
