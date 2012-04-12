#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()

Game::Game()
{
    m_bags[0] = new Bag(Ball::Red, Ball::Red);
    m_bags[1] = new Bag(Ball::Red, Ball::White);
    m_bags[2] = new Bag(Ball::White, Ball::White);
}

Game::~Game()
{
    int i;
    for (i=0; i<3; i++)
        delete m_bags[i];
}

Bag *Game::getABag()
{
    return m_bags[rand()%3];
}