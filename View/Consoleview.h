#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include "Model/Board.h"
#include "Model/Case.h"
#include <string>
#include "View/ConsoleRead.h"
#include "Model/Game.h"
#include "Libraries/observer/observer.h"
#include "Libraries/observer/subject.h"
#include "Scores/Score.h"

using namespace std;


class ConsoleView : public nvs::Observer{
public:

    ConsoleView(Game & game);

    virtual ~ConsoleView();
    virtual void update(const nvs::Subject *subject) override;

    //void start();
    //bool custom();
    void displayStart();
    void displayCustom();
    //void displayChoices();
    void displayBoard();
    void displayScores(int, int, unsigned, vector<Score>);
    void displayChrono();
    void displayError();
    void displayExit();
    //void helpMenu();
    void displayCommands();
    //void action(string action);
    //bool commandCheck(Command cmd);

    //inline Controller getController() const;


private:
    Game game_;

};


/**
 * @brief ConsoleView::getController
 * Getter for the controller
 * @return controller of the game
 */
/*
Controller ConsoleView::getController() const{
    return ctrl_ ;
}
*/

#endif // CONSOLEVIEW_H
