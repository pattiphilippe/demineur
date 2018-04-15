#include "ConsoleView.h"
#include "ConsoleRead.h"
#include "Libraries/observer/subject.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * @brief ConsoleView::ConsoleView
 * Default constructor of ConsoleView
 * Initialize a view for the game Demineur
 */
ConsoleView::ConsoleView(Game & game):
    game_{&game}
{
    game_->registerObserver(this);
}

void ConsoleView::update(const nvs::Subject *subject){
    if(subject == game_){
        this->displayChrono();
        this->displayBoard();
    }
}

ConsoleView::~ConsoleView(){
    game_->unregisterObserver(this);
}

void ConsoleView::setModel(Game & game){
    game_ = &game;
    cout << endl << "New game started, good luck!" << endl;
    update(game_);
}


void ConsoleView::displayStart(){
    cout << "  ___  ____  " << endl
         << "  |  \\/  (_)                                                  " << endl
         << "  | .  . |_ _ __   ___  _____      _____  ___ _ __   ___ _ __ " << endl
         << "  | |\\/| | | '_ \\ / _ \\/ __\\ \\ /\\ / / _ \\/ _ \\ '_ \\ / _ \\ '__|" << endl
         << "  | |  | | | | | |  __/\\__ \\\\ V  V /  __/  __/ |_) |  __/ |   " << endl
         << "  \\_|  |_/_|_| |_|\\___||___/ \\_/\\_/ \\___|\\___| .__/ \\___|_|   " << endl
         << "                                             | |              " << endl
         << "                                             |_|              " << endl <<endl <<endl;
    displayCommands();
    //Commandes suivantes mises en commentaire. La partie n'a pas commencé donc afficher un board et un chrono à ce moment n'a pas de sens.
    //displayChrono();
    //displayBoard();
}

void ConsoleView::displayError(){
    cout << "Wrong input, try again" << endl ;
}

void ConsoleView::displayExit()
{
    cout << "You exited the game, bye !" << endl;
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


void ConsoleView::displayChrono(){
    int score = static_cast<int>(game_->getScore().count());
    cout << endl << "Score : " << endl
         << setw(2) << setfill('0') << score/3600 << " : "
         << setw(2) << setfill('0') << score/60 << " : "
         << setw(2) << setfill('0') << score % 60 << endl;
}


/**
 * @brief ConsoleView::displayBoard
 * Display the board of Demineur
 */
void ConsoleView::displayBoard()
{
    //TODO corriger bug affichage board : lancer custom puis start et bug...
    const BoardPublic * bp = &game_->getBoard() ;

    const CasePublic * cp;

    // COUT COL NBS
    cout << endl << endl << "  ";
    for(int col = 0; col < bp->getNbColumns(); col ++){
        cout << "   " << col;
    }
    cout << endl;
    cout << "   +";
    for(int col = 0; col < bp->getNbColumns() -1; col++){
        cout << "----";
    }
    cout << "---+" << endl;

    // COUT LINES
    for(int line = 0; line < bp->getNbLines(); line ++){

        // COUT LINE WITH TILES
        cout << line << "  | ";
        for(int col = 0; col < bp->getNbColumns(); col++){
            cp = bp->getCase({line, col});
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
        for(int col = 0; col < bp->getNbColumns() -1; col++){
            cout << "----";
        }
        cout << "---+" << endl;
    }
    cout << endl << endl;
}

