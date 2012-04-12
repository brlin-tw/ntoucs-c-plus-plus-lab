#ifndef game_h
#define game_h

class Bag;

class Game
{
public:
    Bag *getABag();
    Game();
    ~Game();
private:
    Bag *m_bags[3];
};

#endif