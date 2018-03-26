#include "Board.h"
#include "Case.h"
#include "stdbool.h"
#include "Game.h"
#include <vector>
#include "Util/Coordinates.h"

using namespace std;

int m_nbLines ;
int m_nbColumns ;
int m_nbBombs ;
bool m_firstClickOnBoard ;
Case m_cases ;

/**
 * @brief Board::Board
 * Basic constructor of board without args
 * Set the number of lines to 10
 * Set the number of columns to 10
 * Default density of bombs wich is 10%
 */
Board::Board()
{
    m_nbLines = 10 ;
    m_nbColumns = 10 ;
    m_nbBombs = 10 ;  /* 10 percent of 100 cases */
    m_firstClickOnBoard = false ;
    m_cases = Case[m_nbLines][m_nbColumns];

}

/**
 * @brief Board::Board
 * Constructor of board in wich you can choose the number of line and columns.
 * The density of bombs is the same than in the normal game.
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 *
 */
Board::Board(int nbLines, int nbColumns)
{
    m_nbLines = nbLines ;
    m_nbColumns = nbColumns ;
    m_nbBombs = (nbLines * nbColumns) * 0.1 ;
    m_firstClickOnBoard = true ;
    m_cases = Case[m_nbLines][m_nbColumns];
}

/**
 * @brief Board::Board
 * Constructor of board in wich you can choose the number of lines and columns
 * and the density of bombs
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 * @param densityBombs Pourcentage of density of bombs you want in your board
 *
 */
Board::Board(int nbLines, int nbColumns, double densityBombs)
{
    m_nbLines = nbLines ;
    m_nbColumns = nbColumns ;
    m_nbBombs = (nbLines * nbColumns) * densityBombs ;
    m_firstClickOnBoard = true ;
    m_cases = Case[m_nbLines][m_nbColumns];
}

/**
 * @brief Board::generateBombs
 * Generate Bombs on the board, it does not generate a bomb on a clicked case
 * @param line line of the clicked case
 * @param column column of the clicked case
 *
 */
void Board::generateBombs(Coordinates pos)
{
    int bombLine, bombColumn, clickedLine = pos.getLine(), clickedColumn = pos.getColumn();
    for(int bomb=0; bomb < m_nbBombs; bomb++){
        do {
            bombLine = rand() % m_nbLines ;
            bombColumn = rand() % m_nbColumns ;
        } while (bombLine==clickedLine && bombColumn==clickedColumn);
        m_cases[bombLine][bombColumn].setBomb();
    }

    m_firstClickOnBoard = false ;
}

/**
 * @brief Board::mark
 * Mark a case in the board. If the case is already marked, this function unmark it.
 * @param clickedLine int, line of the clicked case
 * @param clickedColumn int, column of the clicked case
 */
void Board::mark(int clickedLine, int clickedColumn)
{
    if(m_firstClickOnBoard){
        this->generateBombs(-1, -1); // -1 = Impossible value in the board
    }
    Case & tile {m_cases[clickedLine][clickedColumn]};
    tile.setState(tile.getState == marked ? dft : marked);
}

/**
 * @brief Board::reveal
 * Reveal cases as described in the rules of Démineur.
 * @param clickedLine int, clicked line in the board
 * @param clickedColumn int, clicked column in the board
 * @return true if it didn't reveal a bomb, false if it exploded
 */
bool Board::reveal(int clickedLine, int clickedColumn)
{
    if(m_firstClickOnBoard){
        this->generateBombs(clickedLine,clickedColumn);
    }
    Case & tile {m_cases[clickedLine][clickedColumn]};
    if(tile.isBomb()){
        tile.setState(revealed);
        return false;
    } else if(tile.getState() != revealed){
        if(tile.getNbNearBombs() != 0){
            tile.setState(revealed);
        } else {
            bool checked[m_nbLines][m_nbColumns];
            for (int i=0; i<m_nbLines; i++){
                for(int j=0; j<m_nbColumns; j++){
                    checked[i][j] = false ;
                }
            }
            return revealRec(clickedLine, clickedColumn, checked);
        }
    }
    return true;
}


bool Board::revealRec(Coordinates pos, bool checked[][]){
    Case & tile {m_cases[line][column]};
    checked[pos.getLine()][pos.getColumn()] = true ;
    tile.setState(revealed);
    if(tile.getNbNearBombs()==0){
        Coordinates neighbour ;
        Direction dir;
        pos = Coordinates(line, column);
        for(int dirInt =N ; dirInt != Last; dirInt++ ){
            dir = static_cast<Direction>(dirInt);
            neighbour = pos.move(dir);
            if(!checked[neighbour.getLine()][neighbour.getColumn()]){
                this->reveal(neighbour.getLine(), neighbour.getColumn);
            }
        }
    }
    return true;
}
