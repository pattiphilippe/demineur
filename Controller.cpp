#include "Controller.h"
#include "Model/Game.h"
#include "Util/GameException.h"
#include "View/ConsoleRead.h"

#include <iostream>

using namespace std;

/**
 * @brief Controller::Controller
 * Init a game with default board
 */
Controller::Controller(Game & game, ConsoleView & view):
    game_{game},
    view_{view}
{}


void Controller::run(){
    view_.displayStart();
    Command cmd;
    do {
        cmd = readCommand();
        switch(cmd){
            case START:
                start();
                break;
            case CUSTOM:
                custom();
                break;
            case SCORES:
                scores();
                view_.displayChrono();
                view_.displayBoard();
                break;
            case MARK:
                if(game_.getGameState() == INIT || game_.getGameState() == IN_PROGRESS){
                    mark();
                }else{
                    view_.displayError();
                }
                break;
            case REVEAL:
                if(game_.getGameState() == INIT || game_.getGameState() == IN_PROGRESS){
                    reveal();
                    endGame();
                }else{
                    view_.displayError();
                }

                break;
            case EXIT:
                view_.displayExit();
                break;
            case HELP:
                view_.displayCommands();
                break;
            default:
                view_.displayError();
                view_.displayCommands();
                break;
        }
    } while(cmd != EXIT);
}

void Controller::start(){
    string confirmMsg = "Are you sure you want to start a new game(Y or N)";
    bool confirmed = readBoolean(confirmMsg);
    if(confirmed){
        game_ = Game();
        view_.setModel(game_);
    }
}

void Controller::custom(){
    TypeOfCustom customType ;
    customType = readCustom();

    string linesMsg = "The number of lines you want :";
    string colsMsg = "The number of columns you want :";
    int nbLines = readInt(linesMsg);
    int nbCols = readInt(colsMsg);

    switch(customType){

        case LINESANDCOLUMNS:
            {
                game_ = Game(nbLines, nbCols);
                break;
            }

        case NBBOMBS:
            {
                string bombsMsg = "The number of bombs you want :";
                unsigned nbBombs = readInt(bombsMsg);
                game_ = Game(nbLines, nbCols, nbBombs);
                break;
            }

        case DENSITYBOMBS:
            {
            string densityMsg = "The density of bombs you want (between 5% and 95%) :";
            int densityInt = readInt(densityMsg);
            double densityBombs = densityInt * 0.01 ;
            game_ = Game(nbLines, nbCols, densityBombs);
            break;
            }

        default:
            view_.displayError();
        break;
    }

    view_.setModel(game_);

}

void Controller::scores(){
    //TODO read category and not by default
    string linesMsg = "Enter the nb of lines in the wanted category";
    string colsMsg = "Enter the nb of columns in the wanted category";
    string bombsMsg = "Enter the nb of bombs in the wanted category";
    int nbLines = readInt(linesMsg), nbCols = readInt(colsMsg);
    unsigned nbBombs = readUnsigned(bombsMsg);
    view_.displayScores(nbLines, nbCols, nbBombs, getScores(nbLines, nbCols, nbBombs));
}


/**
 * @brief Controller::reveal
 * Reads and reveals a case in the game
 */
void Controller::reveal(){
    string lineMsg = "Type the line of the case you want to reveal";
    string colMsg = "Type the column of the case you want to reveal";
    int line = readIntBetween(1, game_.getBoard().getNbLines(), lineMsg) -1;
    int col = readIntBetween(1, game_.getBoard().getNbColumns(), colMsg) -1;
    try{
        game_.reveal(Coordinates(line, col));
    } catch(GameException e){
        view_.displayError();
    }
}
/**
 * @brief Controller::mark
 * Reads and marks a case in the game
 */
void Controller::mark(){
    string lineMsg = "Type the line of the case you want to mark";
    string colMsg = "Type the column of the case you want to mark";
    int line = readIntBetween(1, game_.getBoard().getNbLines(), lineMsg) -1;
    int col = readIntBetween(1, game_.getBoard().getNbColumns(), colMsg) -1;
    try{
        game_.mark(Coordinates(line, col));
    } catch(GameException e){
        view_.displayError();
    }
}

void Controller::endGame(){
    if(game_.getGameState() != IN_PROGRESS){
        view_.displayEndGame(game_.getGameState());
        const BoardPublic & b = game_.getBoard();
        int lines = b.getNbLines(), cols = b.getNbColumns();
        unsigned nbBombs = b.getNbBombs();
        vector<Score> scores {};
        if(game_.getGameState() == WON){
            string username = readString("Enter your username");
            scores = saveScore(Score(game_.getScore().count(), username), lines, cols, nbBombs);
        } else {
            scores = getScores(lines, cols, nbBombs);
        }
        view_.displayScores(lines, cols, nbBombs, scores);
    }
}




