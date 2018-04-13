#include "ConsoleView.h"
#include "ConsoleRead.h"
#include "Libraries/observer/subject.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief ConsoleView::ConsoleView
 * Default constructor of ConsoleView
 * Initialize a view for the game Demineur
 */
ConsoleView::ConsoleView(Game & game):
    game_{game}
{
    game_.registerObserver(this);
    //update(game_);
}

void ConsoleView::update(const nvs::Subject *subject){
    //TODO add verif if(subject!=game_) return;
    this->displayBoard();
}

ConsoleView::~ConsoleView(){
    game_.unregisterObserver(this);
}

/**
 * @brief ConsoleView::displayStart
 * Display message at the start of the game.
 */
/*
void ConsoleView::start()
{
    v_controller.newGame(-1, -1, -1, -1);
    cout << "Normal game created, Good Luck & Have Fun !" << endl ;
}

/**
 * @brief ConsoleView::displayCustom
 * Display a menu where the user can custom the game.
 */
/*
bool ConsoleView::custom()
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
                if (cin.fail()){
                    throw "This is not a number.";
                } else if (typeOfCustom < 0 || typeOfCustom>3 ){
                    throw "This is not a valid option in the menu.";
                } else {
                    menuChoiced = true;
                }
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
/*
void ConsoleView::displayChrono()
{
    // Not any chrono yet
}

/**
 * @brief ConsoleView::displayChoices
 * Display different choices during the game.
 */
/*
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
/*
void ConsoleView::action(string action){
    int line,column;
    cout << "Type the line of the case you want to "<<action<<":" << endl ;
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

    cout <<endl << "Type the column of the case you want to "<<action<<":" << endl ;

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
}*/


void ConsoleView::displayStart(){
    //TODO display game starting
    cout<< "Game started " << endl;
    displayBoard();
}
void ConsoleView::displayCustom(){
    //TODO display custom game starting
}


/**
 * @brief ConsoleView::displayBoard
 * Display the board of Demineur
 */
void ConsoleView::displayBoard()
{
    const BoardPublic bp = game_.getBoard() ;

    const CasePublic * cp;

    // COUT COL NBS
    cout << endl << endl << "  ";
    for(int col = 0; col < bp.getNbColumns(); col ++){
        cout << "   " << col;
    }
    cout << endl;
    cout << "   +";
    for(int col = 0; col < bp.getNbColumns() -1; col++){
        cout << "----";
    }
    cout << "---+" << endl;

    // COUT LINES
    for(int line = 0; line < bp.getNbLines(); line ++){

        // COUT LINE WITH TILES
        cout << line << "  | ";
        for(int col = 0; col < bp.getNbColumns(); col++){
            cp = bp.getCase({line, col});
            if (cp->getState() == dft){
                cout << " ";
            } else if (cp->getState()== marked){
                cout << "X";
            } else if (cp->getState() == revealed){
                cout <<  cp->getNbNearBombs();
            }
            cout << " | ";
        }

        // COUT SEPARATION LINE
        cout << endl << "   +";
        for(int col = 0; col < bp.getNbColumns() -1; col++){
            cout << "----";
        }
        cout << "---+" << endl;
    }
    cout << endl << endl;
}

void ConsoleView::displayScores(int lines, int cols, unsigned nbBombs, vector<Score> scores){
    //TODO show scores of asked category
    /*
    const BoardPublic & b = game_.getBoard();
    int lines = b.getNbLines(), cols = b.getNbColumns();
    unsigned nbBombs = b.getNbBombs();
    */
    cout << "Scores for "
         << lines << " lines, "
         << cols<< " columns and "
         << nbBombs << " bombs : " << endl;
    for(auto & s : scores){
        cout << " " << s.getPlayer() << " :  " << s.getTime() << " seconds" << endl;
    }
    cout << endl;
}

void ConsoleView::displayCommands()
{
    cout  << "Type 'start' to start a normal game (10x10 Board with 10 bombs)" << endl
          << "Type 'custom' to start a custom game" << endl
          << "Type 'scores' to see the best scores" << endl
          << "Type 'reveal' to reveal a case" << endl
          << "Type 'mark' to mark a case" << endl
          << "Type 'help' to see the available commands" << endl
          << "Type 'exit' to exit the game" << endl
          << endl;
}
/*
void ConsoleView::helpMenu()
{
    cout  << "Type 'start' to start a normal game (10x10 Board with 10 bombs)" << endl
          << "Type 'custom' to start a custom game" << endl
          << "Type 'scores' to see the best scores" << endl
          << "Type 'exit' to exit the game" << endl ;
}*/

void ConsoleView::displayError(){
    cout << "Wrong input, try again" << endl ;
}

void ConsoleView::displayExit()
{
    cout << "You exited the game, bye !" << endl;
}
/*
bool ConsoleView::commandCheck(Command cmd)
{
    bool isCorrect = false ;
        cmd = readCommand();
        switch(cmd){
            case START:
                this->start();
                isCorrect = true ;
                break;
            case CUSTOM:
                isCorrect = this->custom();
                break;
            case SCORES:
                this->scores();
                isCorrect = true ;
                break;
            default:
                this->displayError();
                this->help();
                isCorrect = true ;
                break;
        }
    return isCorrect ;
}
*/




