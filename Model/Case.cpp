#include "Case.h"
#include "gameexception.h"

Case::Case(int line, int column):
    line_{line},
    column_{column}
{}

void Case::init(int line, int column){
    line_ = line;
    column_ = column;
    isBomb_ = false;
    nbNearBombs_ = 0;
    state_ = dft;
}

CasePublic::CasePublic(Case other):
    case_{other}
{}

bool CasePublic::isBomb() const{
    if(getState() != revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return case_.isBomb();
}

int CasePublic::getNbNearBombs() const{
    if(getState() != revealed){
        throw GameException("Wrong state, can't see details of the case!");
    }
    return case_.getNbNearBombs();
}
