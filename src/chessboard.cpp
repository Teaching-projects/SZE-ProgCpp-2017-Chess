#include "chessboard.h"

Chessboard::Chessboard()
{
    this->selectedPiece = nullptr;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
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
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            delete this->pieceFields[i][j];
        }
    }
}

void Chessboard::emptyDiscoveredSteps()
{
    this->discoveredSteps.clear();
}

void Chessboard::copyPieceFields()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            this->tmpPieceFields[i][j] = this->pieceFields[i][j];
        }
    }
}

void Chessboard::replacePieces()
{
    this->selectedX = this->selectedY = -1;
    this->selectedPiece = nullptr;

    this->clearChessboard();

#ifdef DEBUG_STEPS

    this->pieceFields[7][0] = new King(0, 7, white);
    this->pieceFields[4][3] = new Queen(3, 4, black);
    this->pieceFields[5][4] = new Pawn(4, 5, white);
    this->pieceFields[4][7] = new Rook(7, 4, white);
    this->pieceFields[5][0] = new Rook(0, 5, white);

#else

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

        for (int j = 0; j < COL; j++)
        {
            this->pieceFields[row][j] = new Pawn(j, row, pieceColor);
        }
    }

#endif
}

void Chessboard::addPiecesToPlayers(Player& whitePlayer, Player& blackPlayer)
{
#ifdef DEBUG_STEPS

    whitePlayer.addPiece(this->pieceFields[7][0]);
    blackPlayer.addPiece(this->pieceFields[4][3]);
    whitePlayer.addPiece(this->pieceFields[5][4]);
    whitePlayer.addPiece(this->pieceFields[4][7]);
    whitePlayer.addPiece(this->pieceFields[5][0]);

#else

    for (int i = 0; i < COL; i++)
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

#endif
}

bool Chessboard::selectPiece(int x, int y, Player& activePlayer, Player& enemyPlayer)
{
    this->emptyDiscoveredSteps();

    this->selectedX = x;
    this->selectedY = y;
    this->selectedPiece = this->pieceFields[y][x];

    if (!activePlayer.hasPiece(this->selectedPiece))
    {
        return false;
    }

    if (this->selectedPiece != nullptr)
    {
        this->selectedPiece->discoverSteps(this->discoveredSteps, this->pieceFields);
        this->ruleDiscoveredSteps(enemyPlayer);

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

bool Chessboard::movePieceTo(int x, int y, Player& enemyPlayer)
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
        if (this->pieceFields[y][x] != nullptr)
        {
            enemyPlayer.removePiece(this->pieceFields[y][x]);
            delete this->pieceFields[y][x];
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
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (this->pieceFields[i][j] != nullptr)
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

void Chessboard::ruleDiscoveredSteps(Player& enemyPlayer)
{
    this->copyPieceFields();

    int prevX = this->selectedX;
    int prevY = this->selectedY;
    Chesspiece *prevPiece = nullptr;

    std::vector<DiscoveredStep> enemyDiscoveredSteps;

    auto i = std::begin(this->discoveredSteps);

    while (i != std::end(this->discoveredSteps))
    {
        int index = std::distance(this->discoveredSteps.begin(), i);
        int x = this->discoveredSteps[index].getX();
        int y = this->discoveredSteps[index].getY();

        if (prevPiece != nullptr)
        {
            this->tmpPieceFields[prevY][prevX] = prevPiece;
            prevPiece = nullptr;
        }
        else
        {
            this->tmpPieceFields[prevY][prevX] = nullptr;
        }

        if (this->tmpPieceFields[y][x] != nullptr)
        {
            prevPiece = this->tmpPieceFields[y][x];
        }

        this->tmpPieceFields[y][x] = this->selectedPiece;
        prevX = x;
        prevY = y;

        if (dynamic_cast<King*>(this->pieceFields[y][x]) || this->isEnemyInCheck(enemyPlayer, enemyDiscoveredSteps, this->tmpPieceFields))
        {
            i = this->discoveredSteps.erase(i);
        }
        else
        {
            i++;
        }
    }
}

bool Chessboard::isEnemyInCheck(Player& player)
{
    return this->isEnemyInCheck(player, this->discoveredSteps, this->pieceFields);
}

bool Chessboard::isEnemyInCheck(Player& player, std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const pieceFields[][COL])
{
    bool inCheck = false;

    for (int i = 0; i < player.pieces.size(); i++)
    {
        bool isInPieceFieldsMatrix = false;

        for (int j = 0; j < ROW && !isInPieceFieldsMatrix; j++)
        {
            for (int k = 0; k < COL && !isInPieceFieldsMatrix; k++)
            {
                if (pieceFields[j][k] == player.pieces[i])
                {
                    isInPieceFieldsMatrix = true;
                }
            }
        }

        if (isInPieceFieldsMatrix) // Only for step checks - 'would the king be in check'
        {
            discoveredSteps.clear();
            player.pieces[i]->discoverSteps(discoveredSteps, pieceFields);

            for (int j = 0; j < discoveredSteps.size(); j++)
            {
                int x = discoveredSteps[j].getX();
                int y = discoveredSteps[j].getY();

                if (pieceFields[y][x] != nullptr &&
                    pieceFields[y][x]->getColor() != player.getColor() &&
                    dynamic_cast<King*>(pieceFields[y][x]))
                {
                    inCheck = true;
                    // TODO add piece to list
                }
            }
        }
    }

    return inCheck;
}

std::vector<DiscoveredStep> Chessboard::getDiscoveredSteps()
{
    return this->discoveredSteps;
}
