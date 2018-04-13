#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <Controller.h>
#include "Model/Board.h"
#include "Model/Case.h"
#include <string>
#include "View/ConsoleRead.h"

using namespace std;


class ConsoleView{
public:

    ConsoleView();

    void start();
    bool custom();
    void displayChoices();
    void displayBoard();
    void displayScores();
    void displayChrono();
    void displayError();
    void displayExit();
    void helpMenu();
    void help();
    void action(string action);
    bool commandCheck(Command cmd);

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
