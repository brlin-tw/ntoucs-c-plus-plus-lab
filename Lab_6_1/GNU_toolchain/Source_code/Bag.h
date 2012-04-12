#ifndef BAG_H
#define BAG_H

#include "Ball.h"

class Bag
{
public:
    Ball *getABall();
    void putBallsBack();
    Bag(Ball::Colors color1, Ball::Colors color2, Ball::Colors color3);
    ~Bag();
private:
    Ball *m_balls[3];
    int m_numberOfBalls;
};

#endif
