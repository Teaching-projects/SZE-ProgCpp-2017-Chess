#include "game.h"

Game::Game()
{

}

void Game::startNew()
{
    this->whitePlayer.emptyPieces();
    this->blackPlayer.emptyPieces();
    this->chessboard.replacePieces();
    this->chessboard.addPiecesToPlayers(this->whitePlayer, this->blackPlayer);

    this->activePlayer = &this->whitePlayer;
}

bool Game::selectPieceForStep(int x, int y)
{
    return this->chessboard.selectPiece(x, y, *(this->activePlayer));
}

bool Game::changeSelection(int x, int y)
{
    return this->chessboard.changeSelection(x, y);
}

bool Game::movePieceTo(int x, int y)
{
    if (this->chessboard.movePieceTo(x, y))
    {
        // Change active player
        this->activePlayer = this->activePlayer == &this->whitePlayer ? &this->blackPlayer : &this->whitePlayer;

        return true;
    }
    else
    {
        return false;
    }
}

void Game::getChessPieces(std::vector<std::string>& pieceNames)
{
    this->chessboard.getPieceNames(pieceNames);
}

std::vector<DiscoveredStep> Game::getDiscoveredSteps()
{
    return this->chessboard.getDiscoveredSteps();
}
