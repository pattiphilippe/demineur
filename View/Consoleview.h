#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <Controller.h>
#include "Model/Board.h"
#include "Model/Case.h"
#include <string>

using namespace std;


class ConsoleView{
public:

    ConsoleView();

    bool displayStart();
    bool displayCustom();
    void displayChoices();
    void displayBoard();
    void displayScores();
    void displayChrono();
    void action(string action);

    inline Controller getController() const;


private:

    Controller v_controller ;
};

/**
 * @brief ConsoleView::getController
 * Getter for the controller
 * @return controller of the game
 */
Controller ConsoleView::getController() const{
    return v_controller ;
}

#endif // CONSOLEVIEW_H
