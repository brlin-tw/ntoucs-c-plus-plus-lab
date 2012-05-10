/* input_output.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef INPUT_OUTPUT_H_
  #define INPUT_OUTPUT_H_
  /**/
  #include <vector>
  using namespace std;

  #include "Complex_number_abstract_data_structure/Complex.h"

  /*用來讀取資料檔案的函式*/
  short readFile(vector<CComplex> *pVector);
  

#endif /* INPUT_OUTPUT_H_ */
