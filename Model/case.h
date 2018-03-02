#ifndef CASE_H
#define CASE_H


/*
10: analyse
40: model et console
50: remise graphique 20 et examen 30
*/

enum CaseState{
    dft,
    marked,
    revealed
};

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

bool Case::isBomb() const{
    return isBomb_;
}

void Case::setBomb(){
    isBomb_ = true;
}

int Case::getNbNearBombs() const{
    return nbNearBombs_;
}

void Case::addNearBomb(){
    ++nbNearBombs_;
}

CaseState Case::getState() const{
    return state_;
}

void Case::setState(CaseState newState){
    state_ = newState;
}

#endif // CASE_H
