#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Snackfield.h"

class Game {
private:
    int rows;
    int cols;
    Player     player;
    Snackfield* field;   // pointer so we can build it after asking map size

    void getMapSize();
    void gameLoop();
    void getValidPosition(int& r, int& c);
    void processTile(int r, int c);
    void displayStatus();
    void showEnding();

public:
    Game();
    ~Game();
    void run();
};

#endif
