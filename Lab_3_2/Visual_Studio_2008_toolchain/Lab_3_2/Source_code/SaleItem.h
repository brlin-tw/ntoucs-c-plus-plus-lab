/* SaleItem.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef SALEITEM_H_
  #define SALEITEM_H_
  /* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
  #ifdef __cplusplus
    extern "C"{
  #endif
  
  /*廣域化的商品物件*/
  typedef struct saleItem{
    /*整個資料結構的大小*/
    unsigned structure_size;
    /*廣域化的用來印出商品資訊的函式*/
    void (*print)(struct saleItem *);
    /**/
    unsigned char data[1];
  }SaleItem;

  /*書籍類商品*/
  typedef struct book{
    /**/
    unsigned size;
    /*廣域化的用來印出商品資訊的函式*/
    void (*print)(SaleItem *);
    /*書籍的標題*/
    char title[81];
    /*書籍的作者*/
    char author[51];
    /*書籍的出版商*/
    char publisher[51];
    /*書籍的出版年份*/
    short unsigned year;
    /*書籍的價格*/
    double price;
  }Book;

  /*狹域的印出書籍資料的函式*/
  void printBook(SaleItem *book);

  /*雜誌類商品*/
  typedef struct magazine{
    /**/
    unsigned size;
    /*廣域化的用來印出商品資訊的函式*/
    void (*print)(SaleItem *);
    char title[81];
    /*雜誌的集數*/
    char issue[11];
    short unsigned year;
    short unsigned month;
    char publisher[51];
    /*書籍的價格*/
    double price;
  }Magazine;

  /*狹域的印出雜誌資料的函式*/
  void printMagazine(SaleItem *magazine);

  /*VCD類商品*/
  typedef struct vcd{
    /**/
    unsigned size;
    /*廣域化的用來印出商品資訊的函式*/
    void (*print)(SaleItem *);
    char title[81];
    /*系列的名稱*/
    char series_title[81];
    /*演員群*/
    char casts[101];
    short unsigned year;
    /*製作人*/
    char producer[31];
    char publisher[51];
    /*書籍的價格*/
    double price;
  }VCD;

  /*狹域化的印出VCD資訊的函式*/
  void printVCD(SaleItem *vcd);
  /*用來做unit測試的初始化資料函式*/
  void unitTestInitialize(int *nItems, SaleItem *items[]);

  #ifdef __cplusplus
    }
  #endif
#endif /* SALEITEM_H_ */
