#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Game.h"

class Controller{

public :

    Controller();
    ~Controller();

    void newGame();
    Game getGame() const ;


private :

    Game game ;

};


#endif // CONTROLLER_H
