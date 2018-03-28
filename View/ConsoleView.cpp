#include "ConsoleView.h"

#include <iostream>

using namespace std;

/**
 * @brief ConsoleView::ConsoleView
 * Default constructor of ConsoleView
 * Initialize a view for the game Demineur
 */
ConsoleView::ConsoleView()
{
    v_controller=Controller();
}

/**
 * @brief ConsoleView::displayStart
 * Display message at the start of the game.
 * @return boolean, true if the user typed a correct choice
 */
bool ConsoleView::displayStart()
{
    bool choiceMade = false ;
    String choice ;
    cout << "Welcome in Demineur !" << endl
         << "Type 'start' to start a normal game (10x10 Board with 10 bombs)" << endl
         << "Type 'startCustom' to start a custom game" << endl
         << "Type 'score' to see the best scores" << endl ;

    cin >> choice ;

    switch(choice){
        case "start":
            v_controller.newGame(-1, -1, -1, -1); //Controller take negative parameters as normal game
            choiceMade = true ;
            break;

       case "startCustom":
            this->displayCustom();
            choiceMade = true ;
            break;

       case "score":
            this->displayScores();
            choiceMade = true ;
            break;

       default:
            cout << "Invalid input" << endl ;
    }

    return choiceMade ;
}

