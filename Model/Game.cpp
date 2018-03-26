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
        setGameState(lose);
    }
    //TODO checker si game gagné
}

