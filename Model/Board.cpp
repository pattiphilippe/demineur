#include "Board.h"
#include "Case.h"
#include "stdbool.h"
#include "Game.h"
#include <vector>
#include "Util/Coordinates.h"

using namespace std;

/**
 * @brief Board::Board
 * Basic constructor of board without args
 * Set the number of lines to 10
 * Set the number of columns to 10
 * Default density of bombs wich is 10%
 */
Board::Board():
    b_nbLines{10},
    b_nbColumns{10},
    b_nbBombs{10}, /* 10% of 100 cases */
    b_firstClickOnBoard{true},
    b_cases{Case[b_nbLines][b_nbColumns]}
{}

/**
 * @brief Board::Board
 * Constructor of board in wich you can choose the number of line and columns.
 * The density of bombs is the same than in the normal game.
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 *
 */
Board::Board(int nbLines, int nbColumns):
    b_nbLines{nbLines},
    b_nbColumns{nbColumns},
    //TODO try to put 0.1 in defaultBombsPercentage var?
    b_nbBombs{static_cast<int>((nbLines * nbColumns) * 0.1 )}, /* 10% of 100 cases */
    //TODO délégation de constructeurs?
    b_firstClickOnBoard{true},
    //TODO travailler avec classe array?
    b_cases{Case[b_nbLines][b_nbColumns]}
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
    b_nbLines{nbLines},
    b_nbColumns{nbColumns},
    b_nbBombs{densityBombs},
    b_firstClickOnBoard{true},
    b_cases{Case[b_nbLines][b_nbColumns]}
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
    for(int bomb=0; bomb < b_nbBombs; bomb++){
        do {
            bombLine = rand() % b_nbLines ;
            bombColumn = rand() % b_nbColumns ;
        } while (!canBeBomb || (bombLine==line && bombColumn==col));
        b_cases[bombLine][bombColumn].setBomb();
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
    if(b_firstClickOnBoard){
        this->generateBombs(pos, false); // -1 = Impossible value in the board
    }
    Case & tile {b_cases[pos.getLine()][pos.getColumn()]};
    tile.setState(tile.getState() == marked ? dft : marked);
}

/**
 * @brief Board::reveal
 * Reveal cases as described in the rules of Démineur.
 * @param clickedLine int, clicked line in the board
 * @param clickedColumn int, clicked column in the board
 * @return true if it didn't reveal a bomb, false if it exploded
 */
bool Board::reveal(Coordinates pos)
{
    if(b_firstClickOnBoard){
        this->generateBombs(pos, true);
    }
    Case & tile {b_cases[pos.getLine()][pos.getColumn()]};
    if(tile.isBomb()){
        tile.setState(revealed);
        return false;
    } else if(tile.getState() != revealed){
        if(tile.getNbNearBombs() != 0){
            tile.setState(revealed);
        } else {
            bool checked [b_nbLines][b_nbColumns];
            for (int i=0; i<b_nbLines; i++){
                for(int j=0; j<b_nbColumns; j++){
                    checked[i][j] = false ;
                }
            }
            return revealRec(pos, checked);
        }
    }
    return true;
}


bool Board::revealRec(Coordinates pos, bool** checked){
    Case & tile {b_cases[pos.getLine()][pos.getColumn()]};
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
