#include "Category.h"

using namespace std;

int c_BoardSize ;
int c_nbBombs ;
string c_id ;
std::vector<std::Score> c_scores ;


Category::Category(int boardSize, int nbBombs)
{
    c_BoardSize = boardSize ;
    c_nbBombs = nbBombs ;
    string boardString = to_string(boardSize);
    string nbBombsString = to_string(nbBombs);
    c_id = boardString + nbBombsString ;
}

Category::getScores()
{
    return c_scores ;
}

Category::registerScore(Score score)
{
    c_scores.push_back(score);
}
