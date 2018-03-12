#include "game.h"

Game::Game():
    state_{inProgress},
    board_{}
{}

void Game::mark(int line, int column){
    board.mark(line, column);
}

vector<CasePublic> Game::reveal(int line, int column){
    return board.reveal(line, column);
}

BoardPublic Game::getBoard(){

}
