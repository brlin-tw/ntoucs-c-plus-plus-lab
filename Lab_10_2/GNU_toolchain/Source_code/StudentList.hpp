/* StudentList.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_
/*||||| Forward declarations |||||*/
class StudentList;
class Iterator;
class Node;
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
#include "Student.hpp"

/* 標準C++函式庫 */
#include <string>

/*||||| 常數與巨集 | Constants & Macros |||||*/
#define STUDENT_LIST_TAG "學生列表抽象資料類型"

/*||||| Definition of data type, enumeration, data structure and class |||||*/
/* 學生列表抽象資料類型 */
class StudentList{
  friend class Iterator;
private:
  /* list的節點 */
  class Node{
    friend class StudentList;
  private:
    Student *_data;
    Node *_next;
  public:
    Node(Student *data);
    ~Node();
  };
  /* 指向list開頭與結尾節點的指標變數 */
  StudentList::Node *_head, *_tail;

public:
  /* list的iterator */
  class Iterator{
  public:
    Iterator();
    ~Iterator();
    /* 設定Iterator所屬Student List並初始化_iterator的constructor
     * 參數 | Arguments
     *   要讓Iterator針對的Student List 的參考
     *   TODO : 了解為什麼Iterator已經是List的子class還需要這麼做
     *   */
    Iterator(StudentList &list);
    /* 將iterator重設到list開頭的成員函式 */
    void reset();
    /* 將iterator移到下一個Student的成員函式 */
    void next();
    /* 判斷Iterator指向的學生的後面是否還有學生的函式 */
    bool hasMoreRecord();
    /* dereference iterator to get student reference */
    Student& operator*() ;

  private:
    StudentList::Node *_iterator;
    StudentList *_list;
    /* 用來當operator*()傳回的錯誤值 */
    static Student _notexist;
  };

  StudentList();
  ~StudentList();
  /* 新增學生到list中的函式
   * 回傳值
   * 　0 - 操作成功
   * 　-1 - 操作失敗（可用記憶體空間不足）*/
  short appendEntry(Student *student);
  /* 透過學生姓名尋找列表中學生的成員函式
   * 參數 | Parameters
   *   id - 學生ID
   * 回傳值
   *   該學生的記憶體位址   */
  Student *find(string id) const;
  /* 刪除列表中指定學生的函式
   * 參數 | Parameters
   *   id - 學生ID
   * 回傳值
   *   刪除成功與否 */
  bool deleteEntry(const char *id);
  /* 以陣列下標方式存取列表內學生的成員函式*/
  Student *& operator[](int index) const;
  /* 元件測試成員函式 */
  static void unitTest();

  /* 列表中的學生數目 */
  unsigned size;
};

#endif /* STUDENTLIST_H_ */
