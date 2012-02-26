#ifndef INCLUDED_SWAP_ALGORITHM_H
  #define INCLUDED_SWAP_ALGORITHM_H
  /*使用C的函數調用機制和namespace處理規則，而非C++的Name Mangling*/
  #ifdef __cplusplus
  extern "C"{
  #endif
    /*swap函式 func. prototype*/
        void swapInt(int * swap_a, int * swap_b);

    /*func. prototype for swap func.(unsigned整數專用版本)*/
        void swapUnsignedInt(unsigned int * swap_a, unsigned int * swap_b);

    /*func. prototype of swapLongInt*/
        void swapLongInt(long int * a,long int * b);

    /*func. prototype for Swap(無負短整數專用版本)*/
        void swapUnsignedShortInt(unsigned short int * swap_a, unsigned short int * swap_b);

    /*swapDouble func. prototype*/
        void swapDouble(double * a,double * b);
  #ifdef __cplusplus
  }
  #endif
#endif

