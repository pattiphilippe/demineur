#ifndef SCORE_H
#define SCORE_H
#include <string>
#include <vector>


class Score{
public:

    Score();
    Score(double time, std::string player);
    Score(const Score & other) = default;

    inline double getTime() const;
    inline std::string getPlayer() const ;
    inline bool operator< (const Score & other) const;

private:

    const double s_time;
    const std::string s_player;
};

//PROTOTYPES
std::vector<Score> saveScore(Score, int, int, unsigned) ;
std::vector<Score> getScores(int, int, unsigned) ;

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

bool Score::operator< (const Score & other) const{
    if(s_time == other.s_time || s_time == 0){
        return false;
    } else if(other.s_time == 0){
        return true;
    }
    return s_time < other.s_time;
}

#endif // SCORE_H
