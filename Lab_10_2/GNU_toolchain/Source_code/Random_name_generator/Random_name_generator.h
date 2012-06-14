/* Random_name_generator.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef RANDOM_NAME_GENERATOR_C_
  #define RANDOM_NAME_GENERATOR_C_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  /* 隨機填入中文姓名的函式
   * 參數 | Parameters
   *  目標姓名字串陣列 */
  void generateRandomChineseName(char name[]);

  #ifdef __cplusplus
    }
  #endif
#endif /* RANDOM_NAME_GENERATOR_C_ */
