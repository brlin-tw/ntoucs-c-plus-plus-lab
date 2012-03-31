/* Operate_file_CPP.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef OPERATE_FILE_CPP_H_
  #define OPERATE_FILE_CPP_H_
  /**/
#include <fstream>
using namespace std;

  /*詢問欲開啟檔案的函式*/
  void askFile(char filename[]);

  /*開啟檔案函式*/
  short openFile(const char filename[], const char mode[], ifstream& input_file);

  /*關閉檔案函式*/
  short closeFile(const char filename[], ifstream& input_file);
  

#endif /* OPERATE_FILE_CPP_H_ */
