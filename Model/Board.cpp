#include "Board.h"
#include "Case.h"
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
    m_cases = new Case[m_nbLines][m_nbColumns];

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
    m_firstClickOnBoard = false ;
    m_cases = new Case[m_nbLines][m_nbColumns];
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
    m_firstClickOnBoard = false ;
    m_cases = new Case[m_nbLines][m_nbColumns];
}

/**
 * @brief Board::generateBombs
 * Generate Bombs on the board, it does not generate a bomb on a clicked case
 * @param line line of the clicked case
 * @param column column of the clicked case
 *
 */
Board::generateBombs(int clickedLine, int clickedColumn)
{
    int bombLine, bombColumn ;
    for(int bomb=0; bomb < m_nbBombs; bomb++){
        do {
            bombLine = rand() % m_nbLines ;
            bombColumn = rand() % m_nbColumns ;
        } while (bombLine==clickedLine && bombColumn==clickedColumn);
        m_cases[bombLine][bombColumn].setBomb();
    }

    m_firstClickOnBoard = true ;
}

/**
 * @brief Board::mark
 * Mark a case in the board. If the case is already marked, this function unmark it.
 * @param clickedLine int, line of the clicked case
 * @param clickedColumn int, column of the clicked case
 */
Board::mark(int clickedLine, int clickedColumn)
{
    if(!m_firstClickOnBoard){
        this->generateBombs(999,999); // 999 = Impossible value in the board
    }
    if(m_cases[clickedLine][clickedColumn].getState() == marked){
        m_cases[clickedLine][clickedColumn].setState(dft);
    }else{
        m_cases[clickedLine][clickedColumn].setState(marked);
    }
}

/**
 * @brief Board::reveal
 * Reveal cases as described in the rules of Démineur.
 * @param clickedLine int, clicked line in the board
 * @param clickedColumn int, clicked column in the board
 */
Board::reveal(int clickedLine, int clickedColumn)
{
    if(!m_firstClickOnBoard){
        this->generateBombs(999,999); // 999 = Impossible value in the board
    }
    bool checked[m_nbLines][m_nbColumns];
    for (int i=0; i<m_nbLines; i++){
        for(int j=0; j<m_nbColumns; j++){
            checked[i][j] = false ;
        }
    }


}

Board::RevealRec(int line, int column, bool checked[][]){
    Case tile ;
    tile = m_cases[line][column];
    checked[line][column] = true ;
    tile.setState(revealed);
    if (tile.isBomb()){
        game.setState(lost);  //MODIF A FAIRE CAR PAS CORRECT
    }else{
        if(tile.getNbNearBombs()==0){
            Coordinates pos, neighbour ;
            pos = new Coordinates(line, column);
            for(Direction dir : Direction.getValues()){ //Foreach pas correct non plus
                // à Continuer ici
            }
        }
    }
}

