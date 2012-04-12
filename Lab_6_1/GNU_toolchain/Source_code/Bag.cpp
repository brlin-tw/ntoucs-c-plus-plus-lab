#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()


Bag::Bag(Ball::Colors color1, Ball::Colors color2, Ball::Colors color3)
    : m_numberOfBalls(3)
{

    m_balls[0] = new Ball(color1);
    m_balls[1] = new Ball(color2);
    m_balls[2] = new Ball(color3);
}

Bag::~Bag()
{
    delete m_balls[0];
    delete m_balls[1];
    delete m_balls[2];
}

Ball *Bag::getABall()
{
    /*如果袋中沒有球*/
    if (m_numberOfBalls == 0)
        return (Ball *)NULL;
    /*袋中有一球*/
    else if (m_numberOfBalls == 1)
    {
        m_numberOfBalls = 0;
        return m_balls[0];
    }
    /*多於一顆球*/
    else
    {
      int iPicked = rand() % m_numberOfBalls;
      Ball *pickedBall = m_balls[iPicked];
      for(int i = iPicked; i <= m_numberOfBalls - 2; ++i){
        m_balls[i] = m_balls[i + 1];
      }
      m_balls[m_numberOfBalls - 1] = pickedBall;
      --m_numberOfBalls;
      return pickedBall;

    }
}

void Bag::putBallsBack()
{
    m_numberOfBalls = 3;
}
