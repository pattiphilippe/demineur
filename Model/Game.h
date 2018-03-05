#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "vector"

enum GameState{
    inProgress,
    win,
    lose
}

class Game {
private:
    Board board;
    GameState state;

    void setGameState() const;

public:
    Game();


};

#endif // GAME_H
