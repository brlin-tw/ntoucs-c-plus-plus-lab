/*College.h
-----------------------------------*/

#if !defined(_COLLEGE_H)
#define _COLLEGE_H

/*||||| Forward declarations |||||*/
class College;

/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard C++ Library */
#include <vector>
#include <string>
using namespace std;

/*大學ADT*/
#include "Department.h"
#include "Institute.h"
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
class College {
public:
  College();
  ~College();
  /* 自Resources/ntou1.txt格式的資料檔案獲取學院資料的constructer */
  College(ifstream& universityData);
  /* 印出學院資訊的函式
   * 參數
   * 　output - 輸出資訊的stream   */
  void print(std::ostream &output);
private:
  string m_name;
  vector<Department *> m_departments;
  vector<Institute *> m_institutes;

};

#endif  //_COLLEGE_H
