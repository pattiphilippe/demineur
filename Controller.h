#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/Game.h"
#include <string>

class Controller{

public :

    Controller();

    void newGame(int nbLines, int nbColumns, int nbBombs, double densityBombs);
    inline Game getGame() const ;
    void reveal(unsigned line, unsigned column);
    void mark(unsigned line, unsigned column);
    void saveScore(std::string player) const;

    inline BoardPublic getBoard() const;
    inline GameState getGameState() const;
    inline duration<double> getScore() const;


private :

    Game game_ ;

};


/**
 * @brief Controller::getGame
 * Instance of the actual game
 */
Game Controller::getGame() const
{
    return game_ ;
}

/**
 * @brief gameState getter
 * Returns the game state.
*/
GameState Controller::getGameState() const{
    return game_.getGameState();
}

/**
 * @brief public board getter
 * Returns the public version of the board,
 * so that you can get the infos you need to show the board,
 * but can't modify the data.
 * @return the public version of the board
*/
BoardPublic Controller::getBoard() const{
    return game_.getBoard() ;
}

/**
 * @brief Game::getScore
 * Returns the current time duration elapsed since the start of the game.
 * @return
 */
inline duration<double> Controller::getScore() const{
    return game_.getScore();
}


#endif // CONTROLLER_H
