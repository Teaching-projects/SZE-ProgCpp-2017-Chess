#include "rook.h"

Rook::Rook(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Rook::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps) const
{
    for (int i = this->positionX + 1; i < 8; i++)
    {
        discoveredSteps.push_back(DiscoveredStep(i, this->positionY));
    }

    for (int i = this->positionX - 1; i > -1; i--)
    {
        discoveredSteps.push_back(DiscoveredStep(i, this->positionY));
    }

    for (int i = this->positionY + 1; i < 8; i++)
    {
        discoveredSteps.push_back(DiscoveredStep(this->positionX, i));
    }

    for (int i = this->positionY - 1; i > -1; i--)
    {
        discoveredSteps.push_back(DiscoveredStep(this->positionX, i));
    }
}

std::string Rook::getName()
{
    return "rook";
}
