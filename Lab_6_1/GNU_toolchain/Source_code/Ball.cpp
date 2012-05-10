#include "Ball.h"

Ball::Ball(Colors color)
{
  m_color = color;
}

Ball::~Ball()
{


}
bool Ball::isRed()
{
    if (m_color == Red)
        return true;
    else
        return false;
}
