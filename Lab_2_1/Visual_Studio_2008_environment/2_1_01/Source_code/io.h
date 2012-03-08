#ifndef INCLUDED_IO_H
  #define INCLUDED_IO_H

  /*readFile函式
    dataSize：可修改的陣列大小
    data[]：保存讀檔資料的陣列*/
  void readFile(unsigned *dataSize, int data[]);

  void printArray(const int[], int);

  /*writeFile function
      dataSize:array size
      data: data array*/
  short writeFile(const unsigned dataSize, const int data[]);
#endif // INCLUDED_IO_H
