#include "rook.h"

Rook::Rook(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Rook::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const
{
    for (int i = this->positionX + 1; i < 8; i++)
    {
        if (!this->addDiscoveredStep(discoveredSteps, i, this->positionY, fields))
        {
            break;
        }
    }

    for (int i = this->positionX - 1; i > -1; i--)
    {
        if (!this->addDiscoveredStep(discoveredSteps, i, this->positionY, fields))
        {
            break;
        }
    }

    for (int i = this->positionY + 1; i < 8; i++)
    {
        if (!this->addDiscoveredStep(discoveredSteps, this->positionX, i, fields))
        {
            break;
        }
    }

    for (int i = this->positionY - 1; i > -1; i--)
    {
        if (!this->addDiscoveredStep(discoveredSteps, this->positionX, i, fields))
        {
            break;
        }
    }
}

std::string Rook::getName()
{
    return "rook";
}
