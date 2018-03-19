#ifndef GAME_H
#define GAME_H

#include "Case.h"
#include "Board.h"
#include "vector"

using namespace std;

enum GameState{
    init,
    inProgress,
    win,
    lose
};

class Game {
private:
    Board board_;
    BoardPublic boardPublic_;
    GameState state_ {init};

    inline void setGameState(GameState);

public:
    Game();
    vector<CasePublic> reveal(int line, int column);
    void mark(int line, int column);
    BoardPublic getBoard() const;
    inline GameState getGameState() const;
};

void Game::setGameState(GameState state){
    state_ = state;
}

GameState Game::getGameState() const{
    return state_;
}

#endif // GAME_H
