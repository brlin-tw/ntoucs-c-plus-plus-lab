#ifndef game_h
#define game_h

/* 試驗進行的次數 */
#define EXPERIMENT_REPEAT 100000

class Bag;

class Game
{
public:
  Bag *getABag();
  Game();
  ~Game();
  //袋、球試驗
  double bagBallExperiment(Game& theGame);
  /* 骰子試驗 */
  double diceExperiment(Game& theGame);
private:
    const int m_numberOfBags;
    Bag *m_bags[4];
};

#endif
