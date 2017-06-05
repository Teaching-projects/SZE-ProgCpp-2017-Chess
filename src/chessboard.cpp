#include "chessboard.h"

Chessboard::Chessboard()
{
    this->selectedPiece = nullptr;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            this->pieceFields[i][j] = nullptr;
        }
    }
}

Chessboard::~Chessboard()
{
    this->clearChessboard();
}

void Chessboard::clearChessboard()
{
    // TODO error when closing app

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete this->pieceFields[i][j];
        }
    }
}

void Chessboard::emptyDiscoveredSteps()
{
    this->discoveredSteps.clear();
}

void Chessboard::replacePieces()
{
    this->selectedX = this->selectedY = -1;
    this->selectedPiece = nullptr;

    this->clearChessboard();

    for (int i = 0; i < 2; i++)
    {
        int row = (i == 0) ? 0 : 7;
        PieceColor pieceColor = (i == 0) ? black : white;

        this->pieceFields[row][0] = new Rook(row, 0, pieceColor);
        this->pieceFields[row][1] = new Knight(row, 1, pieceColor);
        this->pieceFields[row][2] = new Bishop(row, 2, pieceColor);
        this->pieceFields[row][3] = new Queen(row, 3, pieceColor);
        this->pieceFields[row][4] = new King(row, 4, pieceColor);
        this->pieceFields[row][5] = new Bishop(row, 5, pieceColor);
        this->pieceFields[row][6] = new Knight(row, 6, pieceColor);
        this->pieceFields[row][7] = new Rook(row, 7, pieceColor);

        row = (i == 0) ? 1 : 6;

        for (int j = 0; j < 8; j++)
        {
            this->pieceFields[row][j] = new Pawn(row, j, pieceColor);
        }
    }
}

void Chessboard::addPiecesToPlayers(Player& whitePlayer, Player& blackPlayer)
{
    for (int i = 0; i < 8; i++)
    {
        //whitePlayer.addPiece();
    }
}

bool Chessboard::selectPiece(int x, int y)
{
    this->selectedX = x;
    this->selectedY = y;
    this->selectedPiece = this->pieceFields[y][x];

    return this->selectedPiece == nullptr; // TODO own piece
}

bool Chessboard::movePieceTo(int x, int y)
{
    // TODO checks, hit

    this->selectedPiece->goTo(x, y);
    this->pieceFields[this->selectedY][this->selectedX] = nullptr;
    this->pieceFields[y][x] = this->selectedPiece;

    return true;
}
