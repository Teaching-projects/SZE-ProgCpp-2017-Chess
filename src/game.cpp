#include "game.h"

Game::Game()
{
    this->whitePlayer = Player(white);
    this->blackPlayer = Player(black);
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
    return this->chessboard.selectPiece(x, y, *this->activePlayer,
                                        this->activePlayer == &this->whitePlayer ? this->blackPlayer : this->whitePlayer);
}

bool Game::changeSelection(int x, int y)
{
    return this->chessboard.changeSelection(x, y);
}

bool Game::movePieceTo(int x, int y)
{
    Player *enemyPlayer = this->activePlayer == &this->whitePlayer ? &this->blackPlayer : &this->whitePlayer;

    if (this->chessboard.movePieceTo(x, y, *enemyPlayer))
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

bool Game::isEnemyInCheck()
{
    // Player's already changed
    return this->chessboard.isEnemyInCheck(this->activePlayer == &this->whitePlayer ? this->blackPlayer : this->whitePlayer);
}

bool Game::isCheckmate()
{
    // Player's already changed
    return this->chessboard.isCheckmate(this->activePlayer == &this->whitePlayer ? this->blackPlayer : this->whitePlayer,
                                        this->activePlayer == &this->whitePlayer ? this->whitePlayer : this->blackPlayer);
}

void Game::getChessPieces(std::vector<std::string>& pieceNames)
{
    this->chessboard.getPieceNames(pieceNames);
}

std::vector<DiscoveredStep> Game::getDiscoveredSteps()
{
    return this->chessboard.getDiscoveredSteps();
}
