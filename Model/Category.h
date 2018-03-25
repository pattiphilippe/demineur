#ifndef CATEGORY_H
#define CATEGORY_H
#include <vector>
#include "Score.h"
#include "stdbool.h"
#include <string>

#endif // CATEGORY_H


class Category{
public:

    Category(boardSize,nbBombs);
    ~Category();

    std::vector<std::Score> getScores();

    bool registerScore(Score score);


private:

    string c_id ;
    int c_BoardSize ;
    int c_nbBombs ;
    std::vector<std::Score> c_scores ;


}
