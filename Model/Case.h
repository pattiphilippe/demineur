#ifndef CASE_H
#define CASE_H

using namespace std;

/**
 * @brief Case state enum
 * Enum that describes the state of a case.
 * Case can be in dft, marked or revealed state.
 */
enum CaseState {
    dft,
    marked,
    revealed
};

/**
  * @brief Class Case
  * Represents a tile of the board.
*/
class Case{
private:
    //TODO check if everything unsigned or int
    unsigned nbNearBombs_{0};
    bool isBomb_{false};
    CaseState state_{CaseState::dft};

public:
    Case();
    void init();
    inline bool isBomb() const;
    inline void setBomb();
    inline unsigned getNbNearBombs() const;
    inline void addNearBomb();
    inline CaseState getState() const;
    inline void setState(CaseState);
};

/**
  * @brief Class Public Case
  * Class that includes a case and gives info about a specific case,
  * but without any modifier.
  * Only gives the infos available with the current tile state.
*/
class CasePublic{
private:
    const Case * src_;

public:
    CasePublic(const Case * src);
    bool isBomb() const;
    unsigned getNbNearBombs() const;
    inline CaseState getState() const;
};

/**
 * @brief isBomb getter
 * Returns true is the case contains a bomb.
 */
bool Case::isBomb() const{
  return isBomb_;
}

/**
 * @brief isBomb setter
 * Puts a bomb in the case.
 */
void Case::setBomb(){
    isBomb_ = true;
}

/**
 * @brief nbNearBombs getter
 * Returns the nb of bombs in the adjacent cases.
 */
unsigned Case::getNbNearBombs() const{
    return nbNearBombs_;
}

/**
 * @brief nbNearBombs setter
 * Adds a bomb to the counter of bombs next to this case.
 */
void Case::addNearBomb(){
    ++nbNearBombs_;
}

/**
 * @brief state getter
 * Returns the state of the case.
 */
CaseState Case::getState() const{
    return state_;
}

/**
 * @brief state setter
 * Sets the case into the given state.
 */
void Case::setState(CaseState newState){
    state_ = newState;
}

/**
 * @brief state getter
 * Returns the state of the case.
 */
CaseState CasePublic::getState() const{
    return src_->getState();
}

#endif // CASE_H
