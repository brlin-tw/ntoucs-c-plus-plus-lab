/*College.h
-----------------------------------*/

#if !defined(_COLLEGE_H)
#define _COLLEGE_H

/* Standard C++ Library */
#include <vector>
#include <string>
using namespace std;

/*大學ADT*/
#include "Department.h"
#include "Institute.h"


class College {
public:
  College();
  ~College();
  /* 自Resources/ntou1.txt格式的資料檔案獲取學院資料的constructer */
  College(ifstream& universityData);

private:
  string m_name;
  vector<Department *> m_departments;
  vector<Institute *> m_institutes;

};

#endif  //_COLLEGE_H
