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

    inline Case getCase(Coordinates pos) const;

    bool reveal(Coordinates);
    void mark(Coordinates);

private:

    int m_nbBombs ;
    int m_nbLines ;
    int m_nbColumns ;
    bool m_firstClickOnBoard;
    Case m_cases [m_nbLines][m_nbColumns];

    bool revealRec(Coordinates, bool checked[][]);
    void generateBombs(Coordinates);
};

class BoardPublic{
private :
    Board board_;

public :
    BoardPublic(Board);
    inline CasePublic getCase(Coordinates) const;
};

Case Board::getCase(Coordinates pos) const {
    return m_cases [pos.getLine()][pos.getColumn()];
}

CasePublic BoardPublic::getCase(Coordinates pos) const{
    //TODO optimiser
    return CasePublic(board_.getCase(pos));
}

#endif // BOARD_H
