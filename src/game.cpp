#include "game.h"

Game::Game()
{
    /*this->chessboard = Chessboard();
    this->whitePlayer = Player();
    this->blackPlayer = Player();*/

    this->startNew();
    this->activePlayer = white;
}

void Game::startNew()
{
    this->whitePlayer.emptyPieces();
    this->blackPlayer.emptyPieces();
    this->chessboard.replacePieces();
}

bool Game::selectPieceForStep(int x, int y)
{
    return this->chessboard.selectPiece(x, y);
}

bool Game::movePieceTo(int x, int y)
{
    return this->chessboard.movePieceTo(x, y);
}
