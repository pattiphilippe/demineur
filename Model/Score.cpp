#include "Score.h"

using namespace std;

double s_time;
string s_player;


/**
 * @brief Score::Score
 * Score of a player with a time and name of player
 * @param time, time of the score
 * @param player, the name of the player
 */
Score::Score(double time, string player)
{
    s_time = time ;
    s_player = player;

}


/**
 * @brief Score::getPlayer
 * Return the player who made this score
 */
Score::getPlayer()
{
    return s_player;
}

/**
 * @brief Score::getTime
 * Return the time of this score.
 */
Score::getTime()
{
    return s_time;
}
