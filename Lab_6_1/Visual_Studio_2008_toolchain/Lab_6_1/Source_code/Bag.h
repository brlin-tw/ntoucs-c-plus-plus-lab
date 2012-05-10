#ifndef BAG_H
#define BAG_H

#include "Ball.h"

/*訊息標籤*/
#define BAG_GETABALL_TAG "【Bag::getABall】"

class Bag
{
public:
  Bag(Ball::Colors color1, Ball::Colors color2, Ball::Colors color3);
  ~Bag();

  /* 自袋中取一球（操作完袋內會少一球）
   * 取出來的球會放到m_numberOfBalls遞減後多出來的不會被取到的位置
   * 用putBallsBack()就能再取到相同的球。
   */
  Ball *getABall();

  void putBallsBack();
private:
  //袋中的球
  Ball *m_balls[3];
  //袋中所有的球數
  const int m_numberOfBalls;
  //袋中目前的球數
  int m_currentBalls;
};

#endif
