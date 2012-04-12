#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // srand()
#include <ctime>   // time()
#include <iostream>


int main()
{
  Game  theGame;
  srand(0);

  double result;
  result = theGame.test3when2(theGame);
  std::cout << "The probability that remaining ball is red = "
            << result << "\n";

  result = theGame.dice(theGame);

  return 0;
}
