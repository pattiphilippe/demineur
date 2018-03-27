#include "Controller.h"


/**
 * @brief Controller::Controller
 * Init a game with default board
 */
Controller::Controller():
    game_{}

{}


/**
 * @brief Controller::newGame
 * Replace current game with a new game
 */
void Controller::newGame(int nbLines, int nbColumns, int nbBombs, double densityBombs)
{
    unsigned u_nbLines = static_cast<unsigned>(nbLines);
    unsigned u_nbColumns = static_cast<unsigned>(nbColumns);
    unsigned u_nbBombs = static_cast<unsigned>(nbBombs);

    //TODO Correct "use of deleted function" errors

    if(nbLines<0 && nbColumns<0){
        game_ = Game();
    }else if(u_nbBombs<0){
        game_ = Game(u_nbLines, u_nbColumns);
    }else if(densityBombs<0){
        game_ = Game(u_nbLines, u_nbColumns, u_nbBombs);
    }else{
        game_ = Game(u_nbLines, u_nbColumns, densityBombs);
    }


    //game_ = Game(); FAIT DES EXCEPTIONS DS TOUT LE PROJET (pas comme en java)
}

/**
 * @brief Controller::reveal
 * Reveal case in the game
 * @param line Line of the case you want to reveal
 * @param column Column of the case you want to reveal
 */
void Controller::reveal(unsigned line, unsigned column)
{
    game_.reveal(Coordinates(line,column));
}

/**
 * @brief Controller::reveal
 * Reveal case in the game
 * @param line Line of the case you want to reveal
 * @param column Column of the case you want to reveal
 */
void Controller::mark(unsigned line, unsigned column)
{
    game_.mark(Coordinates(line,column));
}


