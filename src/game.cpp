#include "game.h"

Game::Game()
{
    this->chessboard = Chessboard();
    this->whitePlayer = Player();
    this->blackPlayer = Player();
}

void Game::startNew()
{
    this->chessboard.replacePieces();
}

void Game::selectPieceForStep(int x, int y)
{

}

void Game::movePieceTo(int x, int y)
{

}
