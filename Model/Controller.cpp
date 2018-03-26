#include "Controller.h"

Game game;

/**
 * @brief Controller::Controller
 * Init a game with default board
 */
Controller::Controller()
{
    game = Game();
}

/**
 * @brief Controller::getGame
 * Instance of the actual game
 */
Controller::getGame()
{
    return game ;
}

/**
 * @brief Controller::newGame
 * Replace current game with a new game
 */
Controller::newGame()
{
    game = Game();
}



