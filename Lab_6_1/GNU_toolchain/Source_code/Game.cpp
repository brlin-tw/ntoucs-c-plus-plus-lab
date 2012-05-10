
//試驗函式庫
#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include "Dice.h"

//標準C++函式庫
#include <cstdlib> // rand()
#include <cassert>
#include <iostream>
using namespace std;

//Ｖ字龍的函式庫蒐集
#include "Messages_templates/zh_TW.h"

/* 訊息 */
#define GAME_BAGBALLEXP_TAG "【Game::BagBallExperiment()】"

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
    for (int i=0; i < m_numberOfBags; i++){
      delete m_bags[i];
      m_bags[i] = NULL;
    }
}

Bag *Game::getABag()
{
    return m_bags[rand()% m_numberOfBags];
}

double Game::bagBallExperiment(Game& theGame)
{
  Bag  *pickedBag;
  Ball *pickedBall;
  int   totalCount = 0;
  int   thirdIsAlsoRed = 0;

  int   i;
  for (i=0; i<EXPERIMENT_REPEAT; i++)
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
#ifndef NDEBUG
  cout << DEBUG_TAG << GAME_BAGBALLEXP_TAG
       << "thirdIsAlsoRed = " << thirdIsAlsoRed << endl;
#endif
  return (double)thirdIsAlsoRed / totalCount;
}

double Game::diceExperiment(Game& theGame)
{
  double unfair_probability[6] =
          {1/(double)4, 1/(double)6, 1/(double)6,
          1/(double)6, 1/(double)6, 1/(double)12};
  Dice fair;
  Dice unfair(unfair_probability);
  Dice *dices[2] = {&fair, &unfair};

  Bag *pickedBag = NULL;
  Ball *pickedBall = NULL;

  unsigned hit = 0, total = 0;
  for (register int i = 0; i < EXPERIMENT_REPEAT; ++i) {
    /* 1. 請由四個袋子中任意挑選一袋 */
    pickedBag = theGame.getABag();
    /* 2. 請由袋子中選一顆球出來, 如果是紅球的話, 把球放回去, 重新再來 */
    if((pickedBall = pickedBag->getABall())->isRed()){
      pickedBag->putBallsBack();
      continue;
    }
    /* 3. 如果在 2 中挑到白球, 請隨便挑一顆骰子丟, 如果是奇數的話,
       不做任何事, 如果是偶數的話再挑一顆球, 把球留在外面 */
    if(dices[rand() % 2]->randomThrow() % 2 == 0){
      pickedBag->getABall();
    }
    /* 4. 最後再由袋子裡挑一顆球,請計算它是白球的機率 */
      total += 1;
    if(!(pickedBall = pickedBag->getABall())->isRed()){
      hit += 1;
    }
    /* 5.把球放回袋中 */
    pickedBag->putBallsBack();
  }
  return (double)hit / total;
}
