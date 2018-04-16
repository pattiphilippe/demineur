#include "Board.h"
#include "Case.h"
#include "Util/Coordinates.h"
#include "Util/GameException.h"
#include <vector>
#include <cstdlib> // rand() in generateBombs()
#include <ctime> // for rand seed in generateBombs()

using namespace std;

/**
 * @brief Board::Board
 * Basic constructor of board without args
 * Set the number of lines to 10
 * Set the number of columns to 10
 * Default density of bombs wich is 10%
 */
Board::Board():
    Board(10, 10)
{}

/**
 * @brief Board::Board
 * Constructor of board in wich you can choose the number of line and columns.
 * The density of bombs is the same than in the normal game.
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 */
Board::Board(int nbLines, int nbColumns):
    Board(nbLines, nbColumns, 0.1)
{}

/**
 * @brief Board::Board
 * Constructor of board in wich you can choose the number of lines and columns
 * and the density of bombs
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 * @param densityBombs Pourcentage of density of bombs you want in your board
 *
 */
Board::Board(int nbLines, int nbColumns, double densityBombs):
    Board(nbLines, nbColumns, static_cast<unsigned>(nbLines * nbColumns * densityBombs))
{}

/**
 * @brief Board::Board
 * Creates a new board with the given parameters.
 * @param nbLines or 5 if it's inferior to 5
 * @param nbColumns or 5 if it's inferior to 5
 * @param nbBombs or validNbBombs (see private method validNbBombs)
 */
Board::Board(int nbLines, int nbColumns, unsigned nbBombs):
    b_nbLines{nbLines < 5 ? 5 : nbLines},
    b_nbColumns{nbColumns < 5 ? 5 : nbColumns},
    b_nbBombs{validNbBombs(nbBombs)},
    b_firstAction{true},
    b_cases{static_cast<unsigned>(b_nbLines)}
{
    for(int line = 0; line < b_nbLines; line++){
        for(int col = 0; col < b_nbColumns; col++){
            b_cases.at(line).push_back({});
        }
    }
}

/**
 * @brief Board::validNbBombs
 * Returns a valid nb of bombs related to the nbLines and columns.
 * Min amount is 5% of nbCases, and max amount is 95% of nbCases.
 * @param nbBombs
 */
unsigned Board::validNbBombs(unsigned nbBombs) const{
    unsigned minBombs = static_cast<unsigned>(b_nbLines * b_nbColumns * 0.05);
    unsigned maxBombs = static_cast<unsigned>(b_nbLines * b_nbColumns * 0.95);
    if(nbBombs < minBombs){
        nbBombs = minBombs;
    } else if (maxBombs < nbBombs){
        nbBombs = maxBombs;
    }
    return nbBombs;
}
/**
 * @brief BoardPublic::BoardPublic
 * Creates a new board public that englobes a board. Only gives access to the getters.
 * @param board the source board
 */
BoardPublic::BoardPublic(Board & board):
    board_{&board},
    cases_{static_cast<unsigned>(board_->getNbLines())}
{
    for(int line = 0; line < board_->getNbLines(); line++){
        for(int col = 0; col < board_->getNbColumns(); col++){
            cases_.at(line).push_back({board_->getCase({line, col})});
        }
    }
}

Board& Board::operator= (const Board& other){
    this->b_nbLines = other.b_nbLines;
    this->b_nbColumns = other.b_nbColumns;
    this->b_nbBombs = other.b_nbBombs;
    this->b_firstAction = other.b_firstAction;
    this->b_cases = other.b_cases;
    return *this;
}

BoardPublic& BoardPublic::operator =(const BoardPublic & other){
    this->board_ = other.board_;
    this->cases_ = other.cases_;
    return *this;
}

/**
 * @brief Board::generateBombs
 * Generate Bombs on the board, it does not generate a bomb on a clicked case
 * @param pos the coordinates where the first action is done
 * @param canBeBomb to true if the pos can be a bomb
 * @throws GameException if pos is not on board
 *
 */
void Board::generateBombs(Coordinates& pos, bool canBeBomb)
{
    if(!isOnBoard(pos)){
        throw GameException("Coordinates not on board!");
    }
    srand(time(NULL));
    int bombLine, bombColumn, line = pos.getLine(), col = pos.getColumn();
    for(unsigned nbBombs=0; nbBombs < b_nbBombs; nbBombs++){
        do {
            bombLine = rand() % b_nbLines ;
            bombColumn = rand() % b_nbColumns ;
        } while (!canBeBomb && (bombLine==line && bombColumn==col) && this->getCase({bombLine, bombColumn})->isBomb());
        setBomb({bombLine, bombColumn});
    }
    b_firstAction = false ;
}

/**
 * @brief Board::setBomb
 * Setter of bomb from board to keep the integrity of the nbNearBombs
 * @param pos where to plant the bomb
 */
void Board::setBomb(Coordinates && pos){
    Case & c = b_cases.at(pos.getLine()).at(pos.getColumn());
    c.setBomb();
    Direction dir;
    for(int dirInt =N ; dirInt != Last; dirInt++ ){
        dir = static_cast<Direction>(dirInt);
        Coordinates neighbour = pos.move(dir);
        if(isOnBoard(neighbour)){
            b_cases.at(neighbour.getLine()).at(neighbour.getColumn()).addNearBomb();
        }
    }
}

/**
 * @brief Board::mark
 * Mark a case in the board. If the case is already marked, this function unmark it.
 * @param pos the coordinates that should be marked
 * @throws GameException if pos is not on board
 */
void Board::mark(Coordinates pos)
{
    if(!isOnBoard(pos)){
        throw GameException("Coordinates not on board!");
    }
    if(b_firstAction){
        this->generateBombs(pos, true); // -1 = Impossible value in the board
    }
    Case & tile {b_cases.at(pos.getLine()).at(pos.getColumn())};
    tile.setState(tile.getState() == marked ? dft : marked);
}

/**
 * @brief Board::reveal
 * Reveal cases as described in the rules of Démineur.
 * @param pos the coordinates that should be revealed
 * @return true if it didn't reveal a bomb, false if it exploded
 * @throws GameException if pos is not on board
 */
bool Board::reveal(Coordinates& pos)
{
    if(!isOnBoard(pos)){
        throw GameException("Coordinates not on board!");
    }
    if(b_firstAction){
        this->generateBombs(pos, false);
    }
    Case * tile{&b_cases.at(pos.getLine()).at(pos.getColumn())};
    if(tile->isBomb()){
        tile->setState(revealed);
        return false;
    } else if(tile->getState() != revealed){
        tile->setState(revealed);
        if(tile->getNbNearBombs() == 0){
            vector<vector<bool>> checked{static_cast<unsigned>(b_nbLines)};
            for(int line = 0; line < b_nbLines; line++){
                for(int col = 0; col < b_nbColumns; col++){
                    checked.at(line).push_back(false);
                }
            }
            return revealRec(pos, checked);
        }
    }
    return true;
}


#include <iostream>
using namespace std;
bool Board::revealRec(Coordinates& pos, vector<vector<bool>> & checked){
    Case * tile {&b_cases[pos.getLine()][pos.getColumn()]};
    cout << "revealRec  {" << pos.getLine() << ", " << pos.getColumn() << "}" << endl;
    checked[pos.getLine()][pos.getColumn()] = true ;
    tile->setState(revealed);
    if(tile->getNbNearBombs()==0){
        Direction dir;
        for(int dirInt =N ; dirInt != Last; dirInt++ ){
            //TODO change coordinates move : when north, -1 col
            dir = static_cast<Direction>(dirInt);
            Coordinates neighbour = pos.move(dir);
            if(isOnBoard(neighbour) && !checked[neighbour.getLine()][neighbour.getColumn()]){
                this->revealRec(neighbour, checked);
            }
        }
    }
    return true;
}
