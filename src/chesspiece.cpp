#include "chesspiece.h"

Chesspiece::Chesspiece() : Chesspiece(-1, -1, white) {}

Chesspiece::Chesspiece(int x, int y, PieceColor pieceColor)
{
    this->positionX = x;
    this->positionY = y;
    this->pieceColor = pieceColor;
}

Chesspiece::~Chesspiece()
{

}

bool Chesspiece::addDiscoveredStep(std::vector<DiscoveredStep>& discoveredSteps, int x, int y, Chesspiece *const fields[][COL]) const
{
    if (fields[y][x] != nullptr)
    {
        if (fields[y][x]->getColor() == this->pieceColor) // TODO check king here?
        {
            return false;
        }
        else
        {
            discoveredSteps.push_back(DiscoveredStep(x, y));

            return false;
        }
    }
    else
    {
        discoveredSteps.push_back(DiscoveredStep(x, y));

        return true;
    }
}

void Chesspiece::goTo(int x, int y)
{
    this->positionX = x;
    this->positionY = y;
}

PieceColor Chesspiece::getColor()
{
    return this->pieceColor;
}
