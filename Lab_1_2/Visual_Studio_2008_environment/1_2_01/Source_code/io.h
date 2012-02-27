#ifndef INCLUDED_IO_H
#define INCLUDED_IO_H

/*readFile函式
  dataSize：可修改的陣列大小
  data[]：保存讀檔資料的陣列
  dataSizeMax：保存資料陣列的最大大小*/
void readFile(unsigned *dataSize, int data[], unsigned dataSizeMax);

void printArray(const int[], int);

#endif // INCLUDED_IO_H
