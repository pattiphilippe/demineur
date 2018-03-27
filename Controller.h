#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/Game.h"

class Controller{

public :

    Controller();

    void newGame(int nbLines, int nbColumns, int nbBombs, double densityBombs);
    inline Game getGame() const ;
    void reveal(unsigned line, unsigned column);
    void mark(unsigned line, unsigned column);


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


#endif // CONTROLLER_H
