#include "Board.h"
#include "case.h"
#include "stdbool.h"

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

}

/**
 * @brief Board::Board
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 * Constructor of board in wich you can choose the number of line and columns.
 * The density of bombs is the same than in the normal game.
 */
Board::Board(int nbLines, int nbColumns)
{
    m_nbLines = nbLines ;
    m_nbColumns = nbColumns ;
    m_nbBombs = (nbLines * nbColumns) * 0.1 ;
    m_firstClickOnBoard = false ;

}

/**
 * @brief Board::Board
 * @param nbLines The number of line of the board
 * @param nbColumns The number of columns of the board
 * @param densityBombs Pourcentage of density of bombs you want in your board
 * Constructor of board in wich you can choose the number of lines and columns
 * and the density of bombs
 */
Board::Board(int nbLines, int nbColumns, double densityBombs)
{
    m_nbLines = nbLines ;
    m_nbColumns = nbColumns ;
    m_nbBombs = (nbLines * nbColumns) * densityBombs ;
    m_firstClickOnBoard = false ;

}

