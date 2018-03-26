#include "game.h"

/**
 * @brief Game::Game()
 * Creates a new game with the default board (see Board() for more infos).
*/
Game::Game():
    state_{init},
    board_{},
    boardPublic_{board_}
{}

/**
 * Marks or unmarks the given position on the board.
 * @param line
 * @param column
*/
void Game::mark(int line, int column){
    board_.mark(line, column);
}

/**
 * Reveals the given position on the board.
 * If the case is a bomb, the game will be over.
 * Otherwise, the tile and every tile without near bombs next to the src will be revealed.
 * @param line the src line
 * @param column the src column
*/
void Game::reveal(int line, int column){
    if(!board_.reveal(line, column)){
        setGameState(lose);
    }
}

/**
 * @brief public board getter
 * Returns the public version of the board,
 * so that you can get the infos you need to show the board,
 * but can't modify the data.
 * @return the public version of the board
*/
BoardPublic Game::getBoard(){
    return boardPublic_;
}
