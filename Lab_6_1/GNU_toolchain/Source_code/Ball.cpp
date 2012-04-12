#include "Ball.h"

Ball::Ball(Colors color)
    : m_color(color)
{
}

bool Ball::isRed()
{
    if (m_color == Red)
        return true;
    else
        return false;
}