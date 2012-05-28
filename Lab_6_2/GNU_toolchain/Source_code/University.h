/*University.h*/
#if !defined(_UNIVERSITY_H)
#define _UNIVERSITY_H


/*||||| Forward declarations |||||*/
class University;

/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/**/
#include <string>
#include <vector>
using namespace std;

/*大學ADT*/
#include "College.h"
#include "Institute.h"
#include "Department.h"
#include "Course.h"
#include "Teacher.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
class University {
public:
  University();
  /* 從resource/ntou1.txt檔案格式的檔案讀取資料並建構University物件
   * 的constructor
   *
   * 參數
   * 　universityData 資料檔案的stream
   */
  University(ifstream &universityData);
  ~University();

  /* 印出大學資訊的函式
   * 參數
   * 　output - 輸出資訊的stream   */
  void print(std::ostream &output);
private:
  /*大學的名稱*/
  string m_name;

  /*此大學底下的所有的college
   *  TODO:使此vector改成pointer to College vector並於College解構時解構所有底下的
            College。*/
  vector <College *> m_colleges;
};

#endif  //_UNIVERSITY_H
