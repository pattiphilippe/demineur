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

    void setModel(Game & game);

    void displayStart() const;
    void displayBoard() const;
    void displayScores(int, int, unsigned, vector<Score>) const ;
    void displayChrono() const ;
    void displayEndGame(GameState) const;
    void displayError() const;
    void displayExit() const;
    void displayCommands() const;

private:
    Game * game_;

};


#endif // CONSOLEVIEW_H
