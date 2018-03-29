#include "ConsoleView.h"

#include <iostream>
#include <vector>

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
    string choice ;
    cout  << "Type 'start' to start a normal game (10x10 Board with 10 bombs)" << endl
          << "Type 'startCustom' to start a custom game" << endl
          << "Type 'score' to see the best scores" << endl ;

    cin >> choice ;

    unsigned int choice_int ;

    if (choice=="start"){   //Conversion of string to int to make it usable in switch
        choice_int = 1 ;
    }else if(choice=="startCustom"){
        choice_int = 2 ;
    }else if(choice=="score"){
        choice_int = 3 ;
    }

    switch(choice_int){
        case 1:
            v_controller.newGame(-1, -1, -1, -1); //Controller take negative parameters as normal game
            choiceMade = true ;
            break;

       case 2:
            choiceMade = this->displayCustom();
            break;

       case 3:
            this->displayScores();
            choiceMade = true ;
            break;

       default:
            cout << "Invalid input" << endl ;
    }

    return choiceMade ;
}

bool ConsoleView::displayCustom()
{
    int typeOfCustom ;
    bool customMade = false;
    cout << "Custom Game menu :" << endl
         << "Type 1 to custom the number of lines and column." << endl
         << "Type 2 to custom the number of lines, columns and bombs." << endl
         << "Type 3 to custom the number of lines, columns and the density of bombs." << endl;

    bool menuChoiced = false ;
    while(!menuChoiced) {
            try {
                cin >> typeOfCustom;
                if (typeOfCustom < 0 || typeOfCustom>3)
                    menuChoiced = true;
                if (cin.fail())
                    throw "This is not a number.";
                if (typeOfCustom < 0 || typeOfCustom>3 )
                    throw "This is not a valid option in the menu.";
                cin.clear();
            }
            catch (char* error) {
                cout << error;
            }
        }

    int nbLines ;
    int nbColumns ;

    // TODO Add some protection when the user needs to enter parameters to prevent errors.

    cout << "Custom number of lines and columns choosen." << endl
         << "The number of lines you want :" ;
    cin >> nbLines ;
    cout << endl << "The number of columns you want :";
    cin >> nbColumns ;

    switch(typeOfCustom){
       case 1:
            v_controller.newGame(nbLines, nbColumns, -1, -1);
            customMade = true ;
            break;

       case 2:
            int nbBombs ;
            cout << "Type the number of bombs you want :" << endl ;
            cin >> nbBombs ;
            v_controller.newGame(nbLines, nbColumns, nbBombs, -1);
            customMade = true ;
            break;

       case 3:
            double densityBombs ;
            cout << "Type the density of bombs you want (max 0.95):" << endl ;
            cin >> densityBombs ;
            v_controller.newGame(nbLines, nbColumns, -1, densityBombs);
            customMade = true ;
            break;

       default:
            cout << "Invalid input" << endl ;
    }
    return customMade;
}

void ConsoleView::displayChrono()
{
    // Not any chrono yet
}

void ConsoleView::displayChoices()
{
    cout << "To mark a case type 'mark nline ncolumn'" <<endl
         << "To reveal a case type 'reveal nline ncolumn'" << endl ;
}



void ConsoleView::displayBoard()
{
    BoardPublic bp = v_controller.getBoard() ;

    const Case * c;
    const CasePublic * cp;
    int columnNumber = 0 ;

    cout << "   %d", columnNumber ;
    for(int col = 0; col < bp.getNbColumns(); col ++){
        cout << "  %d", columnNumber ;
        columnNumber ++ ;
    }
    cout << endl ;

    int lineNumber = 0 ;

    for(int line = 0; line < bp.getNbLines(); line ++){
        cout << "+";
        for(int col = 0; col < bp.getNbColumns(); col++){
            cout << "-----";
        }
        cout << "+" << endl;

        cout << "%d", lineNumber;
        for(int col = 0; col < bp.getNbColumns(); col++){
            cout << "  |" ;
            cp = bp.getCase({line, col});
            if (cp->getState() == dft){
                cout << " ";
            }else if(cp->getState()== marked){
                cout << "X";
            }else if(cp->getState() == revealed){
                cout << "%u", cp->getNbNearBombs();
            }
        }
    }
}





