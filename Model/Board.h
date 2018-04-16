#ifndef BOARD_H
#define BOARD_H

#include "Case.h"
#include "Util/Coordinates.h"
#include "Util/GameException.h"
#include <vector>

//TODO retirer les using namespace si non nécessaire
using namespace std;

class Board{
public:

    Board();
    Board(int nbLines, int nbColumns);
    Board(int nbLines, int nbColumns, unsigned nbBombs);
    Board(int nbLines, int nbColumns, double densityBombs);

    inline int getNbLines() const;
    inline int getNbColumns() const;
    inline unsigned getNbBombs() const;
    inline int getNbRevealed() const;
    inline const Case * getCase(Coordinates) const;

    //TODO add restart method
    void mark(Coordinates);
    bool reveal(Coordinates&);
    inline void revealAll();
    inline void setFirstAction(bool);
    void setBomb(Coordinates&&);
    Board& operator= (const Board& other);

private:

    int b_nbLines ;
    int b_nbColumns ;
    unsigned b_nbBombs ;
    int b_nbRevealed;
    bool b_firstAction;
    vector<vector<Case>> b_cases;

    unsigned validNbBombs(unsigned) const;
    bool revealRec(Coordinates&, vector<vector<bool>> & checked);
    void generateBombs(Coordinates&, bool canBeBomb);
    inline bool isOnBoard(Coordinates&) const;
};

class BoardPublic{
private :
    Board * board_;
    vector<vector<CasePublic>> cases_;

public :
    BoardPublic(Board &);
    inline int getNbLines() const;
    inline int getNbColumns() const;
    inline unsigned getNbBombs() const;
    inline const CasePublic * getCase(Coordinates) const;
    BoardPublic& operator = (const BoardPublic& other);
};


/////////////////////////Inline methods/////////////////////////////////

/**
 * @brief Board::getNbLines
 */
int Board::getNbLines() const {
    return b_nbLines;
}

/**
 * @brief BoardPublic::getNbLines
 */
int BoardPublic::getNbLines() const {
    return board_->getNbLines();
}

/**
 * @brief Board::getNbColumns
 */
int Board::getNbColumns() const {
    return b_nbColumns;
}


/**
 * @brief BoardPublic::getNbColumns
 */
int BoardPublic::getNbColumns() const {
    return board_->getNbColumns();
}

/**
 * @brief Board::getNbBombs
 */
unsigned Board::getNbBombs() const {
    return b_nbBombs;
}

/**
 * @brief BoardPublic::getNbBombs
 */
unsigned BoardPublic::getNbBombs() const {
    return board_->getNbBombs();
}

/**
 * @brief getNbRevealed
 * @return the number of tiles revealed since the start of the game
 */
int Board::getNbRevealed() const{
    return b_nbRevealed;
}

void Board::revealAll(){
    for(vector<Case> & lines : b_cases){
        for(Case & c : lines){
            c.setState(revealed);
        }
    }
}

/**
 * @brief Board::getCase
 * @param pos
 * @return a pointer to the case
 */
const Case * Board::getCase(Coordinates pos) const {
    if(!isOnBoard(pos)){
        throw GameException("Pos not on board");
    }
    return &(b_cases.at(pos.getLine()).at(pos.getColumn()));
}

/**
 * @brief BoardPublic::getCase
 * Returns a Case Public linked to the case in the given pos.
 * @param pos
 * @return
 */
const CasePublic * BoardPublic::getCase(Coordinates pos) const{
    //TODO optimiser
    return &cases_.at(pos.getLine()).at(pos.getColumn());
}

/**
 * @brief Board::isOnBoard
 * Checks if the given pos is on the board.
 * @param pos
 * @return
 */
bool Board::isOnBoard(Coordinates& pos) const{
    int line {pos.getLine()}, col {pos.getColumn()};
    return line >= 0 && col >= 0 && line < b_nbLines && col < b_nbColumns;
}

/**
 * @brief Board::setFirstAction
 * Setter of First Action. Should be used only for testing.
 * @param isFirstAction
 */
void Board::setFirstAction(bool isFirstAction){
    b_firstAction = isFirstAction;
}

#endif // BOARD_H
