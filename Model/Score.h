#ifndef SCORE_H
#define SCORE_H
#include <string>

#endif // SCORE_H

class Score{
public:

    Score(double time, string player);

    double getTime();
    double getPlayer();

private:

    double s_time;
    string s_player;
}
