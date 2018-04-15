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
    vector<Score> getScores(int nbLines, int nbCols, unsigned nbBombs) const;
};


#endif // CONTROLLER_H
