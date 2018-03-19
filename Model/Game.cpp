#include "game.h"

Game::Game():
    state_{init},
    board_{},
    boardPublic_{board_}
{}

void Game::mark(int line, int column){
    board_.mark(line, column);
}

vector<CasePublic> Game::reveal(int line, int column){
    return board_.reveal(line, column);
}

BoardPublic Game::getBoard(){
    return boardPublic_;
}
