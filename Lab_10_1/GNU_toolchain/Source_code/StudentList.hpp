/* StudentList.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_
/*||||| Forward declarations |||||*/
class StudentList;
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
#include "Student.hpp"
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
/* 學生列表抽象資料類型 */
class StudentList{
public:
  StudentList();
  ~StudentList();
  /* 新增學生到list中的函式
   * 回傳值
   * 　0 - 操作成功
   * 　-1 - 操作失敗（可用記憶體空間不足）*/
  short appendEntry(Student *student);
private:
  /* list的節點 */
  class Node{
    friend short StudentList::appendEntry(Student *student);
  private:
    Student *_data;
    Node *_next;
  public:
    Node(Student *data);
    ~Node();
  };
  /* 指向list開頭與結尾節點的指標變數 */
  Node *_head, *_tail;
};

#endif /* STUDENTLIST_H_ */
