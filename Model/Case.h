#ifndef CASE_H
#define CASE_H


/*
10: analyse
40: model et console
50: remise graphique 20 et examen 30
*/

/**
 * @brief Case state enum
 * Enum that describes the state of a case.
 * Case can be in dft, marked or revealed state.
 */
enum CaseState{
    dft,
    marked,
    revealed
};

/**
  * @brief Class Case
  * Represents a tile of the board.
*/
class Case{
private:
    int line_;
    int column_;
    int nbNearBombs_{0};
    bool isBomb_{false};
    CaseState state_{dft};

public:
    Case(int line, int column);
    void init(int line, int column);
    inline bool isBomb() const;
    inline void setBomb();
    inline int getNbNearBombs() const;
    inline void addNearBomb();
    inline CaseState getState() const;
    inline void setState(CaseState);
};

class CasePublic{
private:
    Case & case_;

public:
    CasePublic(Case other);
    bool isBomb() const;
    int getNbNearBombs() const;
    inline CaseState getState() const;
};

/**
 * @brief isBomb getter
 * Returns true is the case contains a bomb.
 */
bool Case::isBomb() const{
  return isBomb_;
}

/**
 * @brief isBomb setter
 * Puts a bomb in the case.
 */
void Case::setBomb(){
    isBomb_ = true;
}

/**
 * @brief nbNearBombs getter
 * Returns the nb of bombs in the adjacent cases.
 */
int Case::getNbNearBombs() const{
    return nbNearBombs_;
}

/**
 * @brief nbNearBombs setter
 * Adds a bomb to the counter of bombs next to this case.
 */
void Case::addNearBomb(){
    ++nbNearBombs_;
}

/**
 * @brief state getter
 * Returns the state of the case.
 */
CaseState Case::getState() const{
    return state_;
}

/**
 * @brief state setter
 * Sets the case into the given state.
 */
void Case::setState(CaseState newState){
    state_ = newState;
}

/**
 * @brief state getter
 * Returns the state of the case.
 */
CaseState CasePublic::getState() const{
    return case_.getState();
}

#endif // CASE_H
