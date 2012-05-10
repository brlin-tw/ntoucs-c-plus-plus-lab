#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()
#include <iostream>

using namespace std;

//Ｖ字龍的函式庫收集
#include "Messages_templates/zh_TW.h"

Bag::Bag(Ball::Colors color1, Ball::Colors color2, Ball::Colors color3)
  :m_numberOfBalls(3)
{
    m_currentBalls = m_numberOfBalls;
    m_balls[0] = new Ball(color1);
    m_balls[1] = new Ball(color2);
    m_balls[2] = new Ball(color3);
}

Bag::~Bag()
{
  for (int i = 0; i < m_numberOfBalls; ++i) {
    delete m_balls[i];
    m_balls[i] = NULL;
  }
}

Ball *Bag::getABall()
{
  /*如果袋中沒有球*/
  if (m_currentBalls == 0){
    cerr << ERROR_TAG << BAG_GETABALL_TAG
         << "袋中已經沒有球了！" << endl;
    return (Ball *)NULL;
  }
  /*袋中有一球*/
  else if (m_currentBalls == 1)
  {
      m_currentBalls = 0;
      return m_balls[0];
  }
  /*多於一顆球*/
  else
  {
    int iPicked = rand() % m_currentBalls;
    Ball *pickedBall = m_balls[iPicked];
    --m_currentBalls;
    //把後面的球平移到前面
    for(int i = iPicked; i <= m_numberOfBalls - 1; ++i){
      m_balls[i] = m_balls[i + 1];
    }
    //將拿取的球移動到平移後多出來的位子，在putBallBack()中才能將袋中球恢復成原本的狀態
    m_balls[m_numberOfBalls - 1] = pickedBall;
    return pickedBall;
   }
}

void Bag::putBallsBack()
{
  //由於getABall()會不會變動袋中的球所以改變數量即可
  m_currentBalls = 3;
}
