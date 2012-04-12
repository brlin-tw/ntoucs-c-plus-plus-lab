#ifndef game_h
#define game_h

class Bag;

class Game
{
public:
    Bag *getABag();
    Game();
    ~Game();
    double test3when2(Game& theGame);
    double dice(Game& theGame);
private:
    const int m_numberOfBags;
    Bag *m_bags[4];
};

#endif
