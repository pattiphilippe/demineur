#include "Category.h"


Category::Category(int boardSize, unsigned nbBombs):
    c_boardSize {boardSize},
    c_nbBombs {nbBombs},
    c_scores {},
    c_id {to_string(boardSize) + to_string(nbBombs)}
{}

array<Score, 5> Category::getScores() const
{
    //TODO ifnotdone load scores in json for this category
    return c_scores ;
}

bool Category::registerScore(Score score)
{
    //TODO load scores in json ifnot done yet, compare score to others,
    //TODO and if better than at least one, put it in sorted
    //c_scores.push_back(score);
    bool hasBeenInserted {false};
    return hasBeenInserted;
}
