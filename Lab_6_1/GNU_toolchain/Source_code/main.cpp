#include "Game.h"
#include "Bag.h"
#include "Ball.h"
#include <cstdlib> // srand()
#include <ctime>   // time()
#include <iostream>

void main()
{
    int   i;
    Game  theGame;
    Bag  *pickedBag;
    Ball *pickedBall;
    int   totalCount = 0;
    int   secondIsAlsoRed = 0;

    srand(time(0));

    for (i=0; i<10000; i++)
    {
        pickedBag = theGame.getABag();
        pickedBall = pickedBag->getABall();
        if (pickedBall->isRed())
        {
            totalCount++;
            if (pickedBag->getABall()->isRed())
                secondIsAlsoRed++;
        }
        pickedBag->putBallsBack();
    }

    std::cout << "The probability that remaining ball is red = " 
              << ((double)secondIsAlsoRed/totalCount) << "\n";
}