#ifndef BOARD_H
#define BOARD_H

#endif // BOARD_H

#inculde "case.h"


#endif // BOARD_H

/**
 * @brief Direction enum
 * Describe the eight principal direction in a board
 */
enum Direction{
    N, NE, E, SE, S, SO, O, NO
};

class Board{
public:

    Board();
    ~Board();
    Board(int nbLines, int nbColumns);
    Board(int nbLines, int nbColumns, int nbBombs);
    Board(int nbLines, int nbColumns, double densityBombs);

    void generateBombs(int line, int column);

    bool reveal(int line, int column);
    bool mark(int line, int column);

    Case getCase(int line, int column);


private:

    int m_nbBombs ;
    int m_nbLines ;
    int m_nbColumns ;
    bool m_firstClickOnBoard;
    Case m_cases [nbLines][nbColumns];
}
