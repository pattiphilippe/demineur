#include "game.h"

/**
 * @brief Game::Game()
 * Creates a new game with the default board (see Board() for more infos).
*/
Game::Game():
    board_{},
    boardPublic_{board_},
    state_{init}
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
    state_{init}
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
    state_{init}
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
    state_{init}
{}

/**
 * Marks or unmarks the given position on the board.
 * @param line
 * @param column
*/
void Game::mark(Coordinates pos){
    board_.mark(pos);
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
        state_ = lose;
    }
}

void Game::hasWon() {
    unsigned nbRevealed{};
    for(int line = 0; line < board_.getNbLines(); line++){
        for(int col = 0; col < board_.getNbColumns(); col++){
            if(board_.getCase({line, col})->getState() == revealed){
                nbRevealed++;
            }
        }
    }
    if(nbRevealed == board_.getNbBombs()){
        state_ = win;
    }
}

