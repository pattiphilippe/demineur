#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model/Game.h"

class Controller{

public :

    Controller();

    void newGame();
    inline Game getGame() const ;


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
