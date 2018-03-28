#ifndef CATEGORY_H
#define CATEGORY_H

#include "Score.h"
#include <array>
#include <string>

using namespace std;

class Category{

public:

    Category(int boardSize, unsigned nbBombs);
    Category(int boardSize, unsigned nbBombs, array<Score, 5> scores);

    array<Score, 5> getScores() const;
    bool registerScore(Score score);

private:

    //TODO put a maximum of attributes const

    const string c_id ;
    const int c_boardSize ;
    const unsigned c_nbBombs ;
    const array<Score, 5> c_scores ;
};


#endif // CATEGORY_H
