/* Dice.h */
/* include guard：避免同一個header檔案被include第二次。*/
#ifndef DICE_H_
  #define DICE_H_
  
/*骰子類別*/
class Dice{
public:
  Dice();
  Dice(double probability[]);
  ~Dice();
  int randomThrow();
private:
  double m_probability[6];

};


#endif /* DICE_H_ */
