#ifndef GAME_H
#define GAME_H

#include "Case.h"
#include "Board.h"
#include "vector"

using namespace std;

/**
 * Possibles state of the game.
*/
enum GameState{
    init,
    inProgress,
    win,
    lose
};

/**
 * @brief Represents a demineur game.
 * Class that englobes the model and all the rules for a demineur game.
 * Englobes the board and the score.
*/
class Game {
private:
    Board board_;
    BoardPublic boardPublic_;
    GameState state_ {init};

    inline void setGameState(GameState);

public:
    Game();
    //TODO rajouter constr pour taille de board
    void reveal(int line, int column);
    void mark(int line, int column);
    BoardPublic getBoard() const;
    inline GameState getGameState() const;
};

/**
 * @brief gameState setter
 * Sets the game to the given state.
*/
void Game::setGameState(GameState state){
    state_ = state;
}

/**
 * @brief gameState getter
 * Returns the game state.
*/
GameState Game::getGameState() const{
    return state_;
}



#endif // GAME_H
