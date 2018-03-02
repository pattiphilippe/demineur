#include "case.h"

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
