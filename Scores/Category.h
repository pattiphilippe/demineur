#ifndef CATEGORY_H
#define CATEGORY_H

#include "Score.h"
#include <array>
#include <string>

using namespace std;

class Category{

public:

    Category(unsigned boardSize, unsigned nbBombs);

    array<Score, 5> getScores() const;
    bool registerScore(Score score);

private:

    //TODO put a maximum of attributes const

    const string c_id ;
    const unsigned c_boardSize ;
    const unsigned c_nbBombs ;
    const array<Score, 5> c_scores ;
};


#endif // CATEGORY_H
