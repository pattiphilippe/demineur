#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/Game.h"
#include "Scores/Score.h"
#include "View/Consoleview.h"
#include <string>


class Controller{

public :

    Controller(Game & game, ConsoleView & view);
    void run();

private :
    Game & game_ ;
    ConsoleView view_;

    //COMMANDS METHODS
    void start();
    void custom();
    void reveal();
    void mark();
    void scores();

    void saveScore() const;
    inline duration<double> getScore() const;
    vector<Score> getScores(int nbLines, int nbCols, unsigned nbBombs) const;
};


/**
 * @brief Game::getScore
 * Returns the current time duration elapsed since the start of the game.
 * @return
 */
inline duration<double> Controller::getScore() const{
    return game_.getScore();
}



/**
 * @brief Controller::getGame
 * Instance of the actual game
 */
/*
Game Controller::getGame() const
{
    return game_ ;
}

/**
 * @brief gameState getter
 * Returns the game state.
*/
/*
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
/*
const BoardPublic & Controller::getBoard() const{
    return game_.getBoard() ;
}
*/



#endif // CONTROLLER_H
