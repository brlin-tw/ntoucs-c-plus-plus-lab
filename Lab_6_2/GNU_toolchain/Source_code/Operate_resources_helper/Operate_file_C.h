/* Operate_file.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef OPERATE_FILE_H_
  #define OPERATE_FILE_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*詢問欲開啟檔案的函式*/
  void askFile(char filename[]);

  /*開啟檔案函式*/
  FILE * openFile(const char const filename[], const char const mode[]);
  /*關閉檔案函式*/
  short closeFile(const char const filename[], FILE * * filePtrRef);
  #ifdef __cplusplus
    }
  #endif
#endif /* OPERATE_FILE_H_ */
