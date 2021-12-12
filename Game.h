#include <LedControl.h>
#include "Consts.h"


class Game {
private:
    State Status;
    LedControl Matrix[4];
    bool Selection;

    int SnakeLength;
    vec SnakeSegments[256];
	  vec Apple;
	  bool AppleAppearance;
	  Dir Direction;
	  bool AppleValid();

public:
    Game();
    void setLed(int x, int y, bool on);
    void setStatus(State s);
    State getStatus();
    void menu();
    void menuUpdate();
    void snake();
    void snakeInit();
    void tetris();
    void tetrisInit();
    void clearAll();
};
