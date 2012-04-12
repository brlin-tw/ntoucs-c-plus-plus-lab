/* Show_software_info.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef SHOW_SOFTWARE_INFO_H_
  #define SHOW_SOFTWARE_INFO_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif

  /* 顯示軟體資訊的函式
   *   印出資訊，將控制交還給主要程式
   * 參數：
   *   program_name:程式名稱（非軟體名稱）的陣列*/
  void show_software_info(const char program_name[]);

  #ifdef __cplusplus
    }
  #endif
#endif /* SHOW_SOFTWARE_INFO_H_ */
