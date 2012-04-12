/*偵錯訊息*/
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef _H_INCLUDED
  #define _H_INCLUDED
  /*使用printf()*/
  #include <stdio.h>

  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /*偵錯訊息的標籤*/
  #define DEBUG_TAG "【偵錯用訊息】"

  /*用來定位錯誤發生的程式碼位置的MACRO*/
  #define DEBUG_LOCATION() printf(DEBUG_TAG "位置：" __FILE__":%d", __LINE__);

  #ifdef __cplusplus
    }
  #endif
#endif /* _H_INCLUDED */




