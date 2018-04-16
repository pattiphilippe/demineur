#ifndef GAME_H
#define GAME_H

#include "Case.h"
#include "Board.h"
#include "vector"
#include <chrono>
#include "Libraries/observer/subject.h"

using namespace std::chrono;

/**
 * Possibles state of the game.
*/
enum GameState{
    INIT,
    IN_PROGRESS,
    WON,
    LOST
};

/**
 * @brief Represents a demineur game.
 * Class that englobes the model and all the rules for a demineur game.
 * Englobes the board and the score.
*/
class Game : public nvs::Subject{
private:
    Board board_;
    BoardPublic boardPublic_;
    GameState state_ {INIT};
    time_point<system_clock> startTime_;

    void hasWon();

public:
    Game();
    Game(int nbLines, int nbColumns);
    Game(int nbLines, int nbColumns, unsigned nbBombs);
    Game(int nbLines, int nbColumns, double densityBombs);
    void reveal(Coordinates);
    void mark(Coordinates);
    inline const BoardPublic & getBoard() const;
    inline GameState getGameState() const;
    inline duration<double> getScore() const;
    Game & operator=(const Game& other);
};


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
const BoardPublic & Game::getBoard() const{
    return boardPublic_;
}

/**
 * @brief Game::getScore
 * Returns the current time duration elapsed since the start of the game.
 * @return
 */
inline duration<double> Game::getScore() const{
    return system_clock::now() - startTime_;
}

#endif // GAME_H
