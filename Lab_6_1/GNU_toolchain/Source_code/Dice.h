/* Dice.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef DICE_H_
  #define DICE_H_

/* 訊息標籤 */
#define DICE_UNITTEST_TAG "【骰子類別元件測試模組】"

/* 骰子類別 */
class Dice{
public:
  Dice();
  //根據probability[]的值進行各個點數面的出現機率設定
  Dice(double probability[]);
  ~Dice();

  /*我們可以在任何時候丟這個骰子, 來看到它出現的點數
   * 回傳數值
   *  1~6：擲出之點數
   *  0：程式有問題*/
  short randomThrow();
  //元件測試模組
  static bool unitTest();
private:
  /* 各個骰面的出現機率*/
  double m_probability[6];

};
#endif /* DICE_H_ */
