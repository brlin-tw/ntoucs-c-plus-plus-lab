/* Operate_file_CPP.h
 * 依賴List_directory_files
 *    Messages_templates
 *    portableEOLalgorithm */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef OPERATE_FILE_CPP_H_
  #define OPERATE_FILE_CPP_H_
  /*標準C++函式庫*/
  #include <fstream>
  #include <string>

using namespace std;

  /*詢問欲開啟檔案的函式*/
  void askFile(string& filename);

  /*開啟檔案函式*/
  short openFile(const string& filename, const char mode[], ifstream& input_file);

  /*關閉檔案函式*/
  short closeFile(const string& filename, ifstream& input_file);
  

#endif /* OPERATE_FILE_CPP_H_ */
