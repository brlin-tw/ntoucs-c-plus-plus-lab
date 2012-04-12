/*College.h
-----------------------------------*/

#if !defined(_COLLEGE_H)
#define _COLLEGE_H
#include <vector>
using namespace std;

/*大學ADT*/
#include "Department.h"
#include "Institute.h"


class College {
public:

private:
  int m_name;
  vector<Department *> m_departments;
  vector<Institute *> m_institutes;
  ~College();
  College();
};

#endif  //_COLLEGE_H
