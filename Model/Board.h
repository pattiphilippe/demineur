#ifndef BOARD_H
#define BOARD_H

#include "Case.h"
#include "Util/Coordinates.h"
#include <vector>

using namespace std;

class Board{
public:

    Board();
    Board(unsigned nbLines, unsigned nbColumns);
    Board(unsigned nbLines, unsigned nbColumns, unsigned nbBombs);
    Board(unsigned nbLines, unsigned nbColumns, double densityBombs);

    inline unsigned getNbLines() const;
    inline unsigned getNbColumns() const;
    inline unsigned getNbBombs() const;
    inline const Case * getCase(Coordinates) const;

    //TODO add restart method
    void mark(Coordinates);
    bool reveal(Coordinates);

private:

    unsigned b_nbLines ;
    unsigned b_nbColumns ;
    unsigned b_nbBombs ;
    bool b_firstClickOnBoard;
    vector<vector<Case>> b_cases;

    bool revealRec(Coordinates, vector<vector<bool>> checked);
    void generateBombs(Coordinates, bool canBeBomb);
    inline bool isOnBoard(Coordinates) const;
};

class BoardPublic{
private :
    Board board_;

public :
    BoardPublic(Board);
    inline CasePublic getCase(Coordinates) const;
};


//Inline methods

/**
 * @brief Board::getNbLines
 */
unsigned Board::getNbLines() const {
    return b_nbLines;
}

/**
 * @brief Board::getNbColumns
 */
unsigned Board::getNbColumns() const {
    return b_nbColumns;
}

/**
 * @brief Board::getNbBombs
 */
unsigned Board::getNbBombs() const {
    return b_nbBombs;
}

/**
 * @brief Board::getCase
 * @param pos
 * @return a pointer to the case
 */
const Case * Board::getCase(Coordinates pos) const {
    return &(b_cases.at(pos.getLine()).at(pos.getColumn()));
}

CasePublic BoardPublic::getCase(Coordinates pos) const{
    //TODO optimiser
    return CasePublic(board_.getCase(pos));
}

bool Board::isOnBoard(Coordinates pos) const{
    if(0 > pos.getLine() && 0 > pos.getColumn()){
        return false;
    } else {
        unsigned line = static_cast<unsigned>(pos.getLine()),
                col = static_cast<unsigned>(pos.getColumn());
        return line < b_nbLines && col < b_nbColumns;
    }
}

#endif // BOARD_H
