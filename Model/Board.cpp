#include "Board.h"
#include "Case.h"
#include "Util/Coordinates.h"
#include "Util/GameException.h"
#include <vector>
#include <cstdlib> // rand() in generateBombs()

#include <iostream>

using namespace std;

//TODO recheck the doc, to be sure its up to date
//TODO use isOnBoard(Coordinates)
//TODO retirer iostream et les affichages

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
Board::Board(unsigned nbLines, unsigned nbColumns):
    //TODO min lines and min cols
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
Board::Board(unsigned nbLines, unsigned nbColumns, double densityBombs):
    //TODO min perc
    Board(nbLines, nbColumns, static_cast<unsigned>(nbLines * nbColumns * densityBombs))
{}

Board::Board(unsigned nbLines, unsigned nbColumns, unsigned nbBombs):
    //TODO minnbBombs
    b_nbLines{nbLines},
    b_nbColumns{nbColumns},
    b_nbBombs{nbBombs},
    b_firstClickOnBoard{true},
    b_cases{nbLines}
{
    for(unsigned line = 0; line < b_nbLines; line++){
        for(unsigned col = 0; col < b_nbColumns; col++){
            b_cases.at(line).push_back({});
        }
    }
}

//TODO check implementation BoardPublic(board)
//TODO * de board ds boardPublic
BoardPublic::BoardPublic(Board board):
    board_{board}
{}

/**
 * @brief Board::generateBombs
 * Generate Bombs on the board, it does not generate a bomb on a clicked case
 * @param line line of the clicked case
 * @param column column of the clicked case
 *
 */
void Board::generateBombs(Coordinates pos, bool canBeBomb)
{
    int bombLine, bombColumn, line = pos.getLine(), col = pos.getColumn();
    for(unsigned nbBombs=0; nbBombs < b_nbBombs; nbBombs++){
        do {
            bombLine = rand() % b_nbLines ;
            bombColumn = rand() % b_nbColumns ;
        } while (!canBeBomb && (bombLine==line && bombColumn==col));
        b_cases.at(bombLine).at(bombColumn).setBomb();
    }
    b_firstClickOnBoard = false ;
}

/**
 * @brief Board::mark
 * Mark a case in the board. If the case is already marked, this function unmark it.
 * @param clickedLine int, line of the clicked case
 * @param clickedColumn int, column of the clicked case
 */
void Board::mark(Coordinates pos)
{
    if(!isOnBoard(pos)){
        throw GameException("Coordinates not on board!");
    }
    if(b_firstClickOnBoard){
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
bool Board::reveal(Coordinates pos)
{
    if(!isOnBoard(pos)){
        throw GameException("Coordinates not on board!");
    }
    if(b_firstClickOnBoard){
        this->generateBombs(pos, false);
    }
    Case tile{b_cases.at(pos.getLine()).at(pos.getColumn())};
    if(tile.isBomb()){
        tile.setState(revealed);
        return false;
    } else if(tile.getState() != revealed){
        if(tile.getNbNearBombs() != 0){
            tile.setState(revealed);
        } else {
            vector<vector<bool>> checked;
            for(unsigned line = 0; line < b_nbLines; line++){
                for(unsigned col = 0; col < b_nbColumns; col++){
                    checked.at(line).push_back(false);
                }
            }
            return revealRec(pos, checked);
        }
    }
    return true;
}


bool Board::revealRec(Coordinates pos, vector<vector<bool>> checked){
    Case tile {b_cases[pos.getLine()][pos.getColumn()]};
    checked[pos.getLine()][pos.getColumn()] = true ;
    tile.setState(revealed);
    if(tile.getNbNearBombs()==0){
        Direction dir;
        for(int dirInt =N ; dirInt != Last; dirInt++ ){
            dir = static_cast<Direction>(dirInt);
            Coordinates neighbour = pos.move(dir);
            if(!checked[neighbour.getLine()][neighbour.getColumn()]){
                this->reveal(neighbour);
            }
        }
    }
    return true;
}
