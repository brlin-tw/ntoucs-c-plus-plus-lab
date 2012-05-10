/*University.h*/
#if !defined(_UNIVERSITY_H)
#define _UNIVERSITY_H
/**/
#include <string>
#include <vector>

/*大學ADT*/
#include "College.h"
#include "Institute.h"
#include "Department.h"
#include "Course.h"
#include "Teacher.h"



using namespace std;

class University {
public:
  University();
  /* 從resource/ntou1.txt檔案格式的檔案讀取資料並建構University物件
   * 的constructor
   *
   * 參數
   * 　infile 資料檔案的stream
   */
  University(ifstream &infile);
  ~University();
private:
  /*大學的名稱*/
  string m_name;
  /*此大學底下的所有的college
   *  TODO:使此vector改成pointer to College vector並於College解構時解構所有底下的
            College。*/
  vector <College *> m_colleges;


};

#endif  //_UNIVERSITY_H
