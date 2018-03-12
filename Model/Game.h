#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "vector"

enum GameState{
    inProgress,
    win,
    lose
};

class Game {
private:
    Board board_;
    GameState state_;

    inline void setGameState() const;

public:
    Game();
    vector<CasePublic> reveal(int line, int column);
    void mark(int line, int column);
    BoardPublic getBoard();
    inline GameState getGameState() const;
};

void Game::setGameState(GameState state){
    state_ = state;
}

GameState Game::getGameState(){
    return state_;
}

#endif // GAME_H
