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

    inline Case getCase(Coordinates) const;

    bool reveal(Coordinates);
    void mark(Coordinates);

private:

    const unsigned b_nbLines ;
    const unsigned b_nbColumns ;
    const unsigned b_nbBombs ;
    bool b_firstClickOnBoard;
    const vector<vector<Case>> b_cases;

    bool revealRec(Coordinates, vector<vector<bool>> checked);
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
