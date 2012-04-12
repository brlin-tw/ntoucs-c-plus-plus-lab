#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // rand()
#include <cassert>
#include "Dice.h"

Game::Game()
  :m_numberOfBags(4)
{

    m_bags[0] = new Bag(Ball::Red, Ball::Red, Ball::Red);
    m_bags[1] = new Bag(Ball::Red, Ball::Red, Ball::White);
    m_bags[2] = new Bag(Ball::Red, Ball::White, Ball::White);
    m_bags[3] = new Bag(Ball::White, Ball::White, Ball::White);
}

Game::~Game()
{
    int i;
    for (i=0; i < m_numberOfBags; i++)
        delete m_bags[i];
}

Bag *Game::getABag()
{
    return m_bags[rand()% m_numberOfBags];
}

double Game::test3when2(Game& theGame)
{
  int   i;

  Bag  *pickedBag;
  Ball *pickedBall;
  int   totalCount = 0;
  int   thirdIsAlsoRed = 0;



  for (i=0; i<10000; i++)
  {
      pickedBag = theGame.getABag();
      pickedBall = pickedBag->getABall();
      if (pickedBall->isRed())
      {

          if (pickedBag->getABall()->isRed()){
            totalCount++;
            if (pickedBag->getABall()->isRed()){
              thirdIsAlsoRed++;

            }
          }

      }
      pickedBag->putBallsBack();
  }

  assert(thirdIsAlsoRed == 2533);
  return (double)thirdIsAlsoRed / totalCount;
}

double Game::dice(Game& theGame)
{
  Dice dummy;
  dummy.randomThrow();

  double result;
  return result;
}
