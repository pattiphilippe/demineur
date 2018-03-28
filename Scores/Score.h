#ifndef SCORE_H
#define SCORE_H
#include <string>


class Score{
public:

    Score();
    Score(double time, std::string player);

    inline double getTime() const;
    inline std::string getPlayer() const ;

private:

    const double s_time;
    const std::string s_player;
};

//INLINE METHODS

/**
 * @brief Score::getTime
 * @return the time of this score
 */
double Score::getTime() const{
    return s_time;
}

/**
 * @brief Score::getPlayer
 * @return the username saved with this score
 */
std::string Score::getPlayer() const{
    return s_player;
}

#endif // SCORE_H