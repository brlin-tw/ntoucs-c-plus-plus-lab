/* Software_info.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef SOFTWARE_INFO_H_
  #define SOFTWARE_INFO_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  
  /*軟體名稱*/
  #define SOFTWARE_NAME "SOFTWARE_NAME"
  /*軟體開發者名稱*/
  #define DEVELOPER_NAME "DEVELOPER_NAME"
  /*軟體開發者的電子郵件地址*/
  #define DEVELOPER_EMAIL "developer@host.category.region"
  /*用在著作權宣告的軟體釋出年份*/
  #define SOFTWARE_RELEASE_YEAR "2012"
  /* 用在軟體所使用的授權條款（目前尚未實作）
   * 有效值："LGPL" "GPL" "ALL_RIGHTS_RESERVED"
  #define SOFTWARE_LICENSE "LGPL"*/
  /* 用在軟體所使用的授權條款版本（目前尚未實作）
   * 有效值："「數字」（+）" "NONE"
  #define SOFTWARE_LICENSE_VERSION "3+"*/
  #ifdef __cplusplus
    }
  #endif
#endif /* SOFTWARE_INFO_H_ */
