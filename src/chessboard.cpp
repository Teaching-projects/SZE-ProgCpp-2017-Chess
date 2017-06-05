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

        this->pieceFields[row][0] = new Rook(0, row, pieceColor);
        this->pieceFields[row][1] = new Knight(1, row, pieceColor);
        this->pieceFields[row][2] = new Bishop(2, row, pieceColor);
        this->pieceFields[row][3] = new Queen(3, row, pieceColor);
        this->pieceFields[row][4] = new King(4, row, pieceColor);
        this->pieceFields[row][5] = new Bishop(5, row, pieceColor);
        this->pieceFields[row][6] = new Knight(6, row, pieceColor);
        this->pieceFields[row][7] = new Rook(7, row, pieceColor);

        row = (i == 0) ? 1 : 6;

        for (int j = 0; j < 8; j++)
        {
            this->pieceFields[row][j] = new Pawn(j, row, pieceColor);
        }
    }
}

void Chessboard::addPiecesToPlayers(Player& whitePlayer, Player& blackPlayer)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int row;

            if (j == 0 || j == 1)
            {
                row = j;
                blackPlayer.addPiece(this->pieceFields[row][i]);
            }
            else
            {
                row = j == 2 ? 7 : 6;
                whitePlayer.addPiece(this->pieceFields[row][i]);
            }
        }
    }
}

bool Chessboard::selectPiece(int x, int y, Player& activePlayer)
{
    this->emptyDiscoveredSteps();

    this->selectedX = x;
    this->selectedY = y;
    this->selectedPiece = this->pieceFields[y][x];

    if (!activePlayer.hasPiece(this->selectedPiece))
    {
        return false;
    }

    if (this->selectedPiece != nullptr && !this->selectedPiece->isHit())
    {
        this->selectedPiece->discoverSteps(this->discoveredSteps);
        this->ruleDiscoveredSteps();

        return this->discoveredSteps.size() > 0;
    }

    return false;
}

bool Chessboard::changeSelection(int x, int y)
{
    return this->pieceFields[y][x] != nullptr &&
            this->pieceFields[y][x] != this->selectedPiece &&
            this->pieceFields[y][x]->getColor() == this->selectedPiece->getColor();
}

bool Chessboard::movePieceTo(int x, int y)
{
    // TODO checks, hit

    bool validStep = false;

    for (int i = 0; i < this->discoveredSteps.size(); i++)
    {
        if (this->discoveredSteps[i].getX() == x && this->discoveredSteps[i].getY() == y)
        {
            validStep = true;
            break;
        }
    }

    if (validStep)
    {
        if (this->pieceFields[y][x] != nullptr &&
            !this->pieceFields[y][x]->isHit() &&
            !dynamic_cast<King*>(this->pieceFields[y][x])) // TODO check king here???
        {
            this->pieceFields[y][x]->getHit();
        }

        this->selectedPiece->goTo(x, y);
        this->pieceFields[this->selectedY][this->selectedX] = nullptr;
        this->pieceFields[y][x] = this->selectedPiece;

        return true;
    }

    return false;
}

void Chessboard::getPieceNames(std::vector<std::string>& pieceNames)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->pieceFields[i][j] != nullptr && !this->pieceFields[i][j]->isHit())
            {
                std::string pieceColor = this->pieceFields[i][j]->getColor() == white ? "white" : "black";
                pieceNames.push_back(pieceColor + "_" + this->pieceFields[i][j]->getName());
            }
            else
            {
                pieceNames.push_back("");
            }
        }
    }
}

void Chessboard::ruleDiscoveredSteps()
{
    auto i = std::begin(this->discoveredSteps);

    while (i != std::end(this->discoveredSteps))
    {
        int index = std::distance(this->discoveredSteps.begin(), i);
        int x = this->discoveredSteps[index].getX();
        int y = this->discoveredSteps[index].getY();

        if (this->pieceFields[y][x] != nullptr &&
            (!this->pieceFields[y][x]->isHit() &&
            this->pieceFields[y][x]->getColor() == this->selectedPiece->getColor() ||
            dynamic_cast<King*>(this->pieceFields[y][x])))
        {
            i = this->discoveredSteps.erase(i);
        }
        else
        {
            i++;
        }
    }
}

std::vector<DiscoveredStep> Chessboard::getDiscoveredSteps()
{
    return this->discoveredSteps;
}
