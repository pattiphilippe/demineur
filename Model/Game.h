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
    Game(unsigned nbLines, unsigned nbColumns);
    Game(unsigned nbLines, unsigned nbColumns, unsigned nbBombs);
    Game(unsigned nbLines, unsigned nbColumns, double densityBombs);
    //TODO rajouter constr pour taille de board
    void reveal(Coordinates);
    void mark(Coordinates);
    inline BoardPublic getBoard() const;
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

/**
 * @brief public board getter
 * Returns the public version of the board,
 * so that you can get the infos you need to show the board,
 * but can't modify the data.
 * @return the public version of the board
*/
BoardPublic Game::getBoard() const{
    return boardPublic_;
}

#endif // GAME_H
