#include "game.h"

using namespace std;

using namespace std::chrono;

/**
 * @brief Game::Game()
 * Creates a new game with the default board (see Board() for more infos).
*/
Game::Game():
    board_{},
    boardPublic_{board_},
    state_{GameState::INIT},
    startTime_{system_clock::now()}
{}

/**
 * @brief Game::Game
 * Creates a new game with custom sized board
 * @param nbLines number of lines of the customized board
 * @param nbColumns number of columns of the customized board
 */
Game::Game(int nbLines, int nbColumns):
    board_{nbLines, nbColumns},
    boardPublic_{board_},
    state_{INIT},
    startTime_{system_clock::now()}
{}

/**
 * @brief Game::Game
 * Creates a new game with custom sized board and a custom amount of bombs
 * @param nbLines number of lines of the customized board
 * @param nbColumns number of columns of the customized board
 * @param nbBombs number of bombs int the customized board
 */
Game::Game(int nbLines, int nbColumns, unsigned nbBombs):
    board_{nbLines, nbColumns, nbBombs},
    boardPublic_{board_},
    state_{INIT},
    startTime_{system_clock::now()}
{}

/**
 * @brief Game::Game
 * Creates a new game with custom sized board and a custom density of bombs
 * @param nbLines number of lines of the customized board
 * @param nbColumns number of column of the customized board
 * @param densityBombs density of bombs in the customized board
 */
Game::Game(int nbLines, int nbColumns, double densityBombs):
    board_{nbLines, nbColumns, densityBombs},
    boardPublic_{board_},
    state_{INIT},
    startTime_{system_clock::now()}
{}

Game & Game::operator=(const Game& other){
    this->board_ = other.board_;
    this->boardPublic_ = BoardPublic(board_);
    this->startTime_ = other.startTime_;
    this->state_ = other.state_;
    return *this;
}

/**
 * Marks or unmarks the given position on the board.
 * @param line
 * @param column
*/
void Game::mark(Coordinates pos){
    board_.mark(pos);
    notifyObservers();
}

/**
 * Reveals the given position on the board.
 * If the case is a bomb, the game will be over.
 * Otherwise, the tile and every tile without near bombs next to the src will be revealed.
 * @param line the src line
 * @param column the src column
*/
void Game::reveal(Coordinates pos){
    if(!board_.reveal(pos)){
        state_ = LOST;
        board_.revealAll();
    } else{
        hasWon();
    }
    notifyObservers();
}

void Game::hasWon() {
    int lines {board_.getNbLines()}, cols {board_.getNbColumns()};
    if((lines * cols - board_.getNbBombs() - board_.getNbRevealed()) == 0){
        state_ = WON;
    }
}

