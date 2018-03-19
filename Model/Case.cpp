#include "Case.h"
#include "gameexception.h"


/**
 * @brief Case::Case
 * Creates a new case with the given coordinates.
 * Is not a bomb by default,
 * has no near bombs by default,
 * is set in dft state.
 */
Case::Case(int line, int column):
    line_{line},
    column_{column}
{}

/**
 * @brief Case initializer
 * Sets the case to the given coordinates
 * Default values are set to its attributes
 * (see Case::Case for further description)
 */
void Case::init(int line, int column){
    line_ = line;
    column_ = column;
    isBomb_ = false;
    nbNearBombs_ = 0;
    state_ = dft;
}

/**
 * @brief Public Case constructor
 * Public Case is linked to the given case
 * @param other the source case
*/
CasePublic::CasePublic(Case src):
    case_{src}
{}

/**
 * @brief isBomb getter
 * Returns true if it is a bomb.
 * @throws GameException if the state is not revealed
 */
bool CasePublic::isBomb() const{
    if(getState() != revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return case_.isBomb();
}


/**
 * @brief nbNearBombs getter
 * Returns the number of bombs next to this case
 * @throws GameException if the state is not revealed
 */
int CasePublic::getNbNearBombs() const{
    if(getState() != revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return case_.getNbNearBombs();
}
