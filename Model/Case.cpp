#include "Case.h"
#include "Util/GameException.h"


/**
 * @brief Case::Case
 * Is not a bomb by default,
 * has no near bombs by default,
 * is set in dft state.
 */
Case::Case(){} //everything is default (see attributes in case.h)

/**
 * @brief Case initializer
 * Default values are set to its attributes
 * (see Case::Case for further description)
 */
void Case::init(){
    isBomb_ = false;
    nbNearBombs_ = 0;
    state_ = CaseState::dft;
}

/**
 * @brief Public Case constructor
 * Public Case is linked to the given case
 * @param other the source case
*/
CasePublic::CasePublic(const Case * src):
    src_{src}
{}

/**
 * @brief isBomb getter
 * Returns true if it is a bomb.
 * @throws GameException if the state is not revealed
 */
bool CasePublic::isBomb() const{
    if(getState() != CaseState::revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return src_->isBomb();
}


/**
 * @brief nbNearBombs getter
 * Returns the number of bombs next to this case
 * @throws GameException if the state is not revealed
 */
unsigned CasePublic::getNbNearBombs() const{
    if(getState() != CaseState::revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return src_->getNbNearBombs();
}
