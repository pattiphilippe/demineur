#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <Controller.h>

using namespace std;

class ConsoleView{
public:

    ConsoleView();

    bool displayStart();
    bool displayCustom();
    void displayChoices();
    void displayHelp();
    void displayBoard();
    void displayScores();
    void displayChrono();

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
