#include "Score.h"

using namespace std;

/**
 * @brief Score::Score
 * Creates an empty score
 */
Score::Score(): Score(0, ""){}




/**
 * @brief Score::Score
 * Score of a player with a time and name of player
 * @param time, time of the score
 * @param player, the name of the player
 */
Score::Score(double time, string player):
    s_time {time},
    s_player {player}
{}

