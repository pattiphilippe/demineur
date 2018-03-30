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



    bool menuChoiced = false ;
    while(!menuChoiced) {
            try {
                cin >> choice ;
                if (cin.fail())
                    throw "This is not a number.";
                //TODO CORRECT ERROR
                //if (typeOfCustom < 0 || typeOfCustom>3 )
                    throw "This is not a valid option in the menu.";
                cin.clear();
            }
            catch (char* error) {
                cout << error;
            }
    }

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
        //TODO CORRECT ERROR
            //this->displayScores();
            choiceMade = true ;
            break;

       default:
            cout << "Invalid input" << endl ;
    }

    return choiceMade ;
}

/**
 * @brief ConsoleView::displayCustom
 * Display a menu where the user can custom the game.
 * @return Boolean , true if the choice is the user didn't make input errors
 */
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


/**
 * @brief ConsoleView::displayChrono
 * Displays the chrono of the current game.
 */
void ConsoleView::displayChrono()
{
    // Not any chrono yet
}

/**
 * @brief ConsoleView::displayChoices
 * Display different choices during the game.
 */
void ConsoleView::displayChoices()
{
    cout << "To mark a case type 'mark'" <<endl
         << "To reveal a case type 'reveal'" << endl ;
    string choice ;

    //TODO CORRECT ERROR
    cin >> choice ;
    if(choice == "mark" || choice == "reveal"){
        this->action(choice);
    }else{
        cout << "Wrong choice" << endl ;
    }

}


/**
 * @brief ConsoleView::action
 * Interact with the user to reveal and mark cases
 * @param action mark or reveal , set the mode to mark or reveal a case.
 */
void ConsoleView::action(string action){
    unsigned line,column;
    cout << "Type the line of the case you want to mark :";
    bool correctLine = false ;
    bool correctColumn = false ;
    try {
        cin >> line;
        if (line <= v_controller.getBoard().getNbLines() || line >= 0)
             correctLine = true;
        if (cin.fail())
            throw "This is not a number.";
        if (line < 0 || line > v_controller.getBoard().getNbLines() )
            throw "Out of the game";
        cin.clear();
     }
     catch (char* error) {
       cout << error;
     }

    cout <<endl << "Type the column of the case you want to mark:";

    try {
        cin >> column;
        if (column <= v_controller.getBoard().getNbColumns())
             correctColumn = true;
        if (cin.fail())
            throw "This is not a number.";
        if (column > v_controller.getBoard().getNbColumns() )
            throw "Out of the game";
        cin.clear();
     }
     catch (char* error) {
       cout << error;
     }

    if(correctColumn && correctLine){
        if(action == "mark"){
            v_controller.mark(line,column);
        }else{
            v_controller.reveal(line, column);
        }
    }
}


/**
 * @brief ConsoleView::displayBoard
 * Display the board of Demineur
 */
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





