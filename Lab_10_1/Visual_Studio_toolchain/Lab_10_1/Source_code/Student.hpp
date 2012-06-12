/* Student.hpp */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef STUDENT_HPP_
  #define STUDENT_HPP_
/*||||| Forward declarations |||||*/
class Student;
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* 標準C++函式庫 */
#include <iostream>
using namespace std;
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/* 學生抽像資料類型 */
class Student{
public:
  Student();
  Student(
    const char name[],
    const char ID[],
    const char phone[],
    const char department[]);
  ~Student();
  void display(ostream &output) const;
  static void unitTest();
private:
  /* 姓名 */
  char *_name;
  /* ID */
  char *_ID;
  /* 電話號碼 */
  char *_phone;
  /* 學系名稱 */
  char *_department;
};

#endif /* STUDENT_HPP_ */
