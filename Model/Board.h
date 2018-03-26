#ifndef BOARD_H
#define BOARD_H

#include "Case.h"
#include "Util/Coordinates.h"

class Board{
public:

    Board();
    Board(int nbLines, int nbColumns);
    Board(int nbLines, int nbColumns, int nbBombs);
    Board(int nbLines, int nbColumns, double densityBombs);

    inline Case getCase(Coordinates) const;

    bool reveal(Coordinates);
    void mark(Coordinates);

private:

    const int b_nbBombs ;
    const int b_nbLines ;
    const int b_nbColumns ;
    bool b_firstClickOnBoard;
    const Case** b_cases;

    bool revealRec(Coordinates, bool** checked);
    void generateBombs(Coordinates, bool canBeBomb);
};

class BoardPublic{
private :
    Board board_;

public :
    BoardPublic(Board);
    inline CasePublic getCase(Coordinates) const;
};


//Inline methods

Case Board::getCase(Coordinates pos) const {
    return b_cases [pos.getLine()][pos.getColumn()];
}

CasePublic BoardPublic::getCase(Coordinates pos) const{
    //TODO optimiser
    return CasePublic(board_.getCase(pos));
}

#endif // BOARD_H
