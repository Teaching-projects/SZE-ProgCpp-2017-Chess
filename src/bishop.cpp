#include "bishop.h"

Bishop::Bishop(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Bishop::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps) const
{
    /*for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == i + (this->positionX - this->positionY) ||
                j == 8 - 1 - i - (8 - (this->positionX + this->positionY) - 1))
            {
                discoveredSteps.push_back(DiscoveredStep(j, i));
            }
        }
    }*/

    for (int i = this->positionY + 1; i < 8; i++)
    {
        // lower '\'
        for (int j = this->positionX + 1; j < 8; j++)
        {
            if (j == i + (this->positionX - this->positionY))
            {
                discoveredSteps.push_back(DiscoveredStep(j, i));
            }
        }

        // lower '/'
        for (int j = this->positionX - 1; j > -1; j--)
        {
            if (j == 8 - 1 - i - (8 - (this->positionX + this->positionY) - 1))
            {
                discoveredSteps.push_back(DiscoveredStep(j, i));
            }
        }
    }

    for (int i = this->positionY - 1; i > -1; i--)
    {
        // upper '\'
        for (int j = this->positionX - 1; j > -1; j--)
        {
            if (j == i + (this->positionX - this->positionY))
            {
                discoveredSteps.push_back(DiscoveredStep(j, i));
            }
        }

        // upper '/'
        for (int j = this->positionX + 1; j < 8; j++)
        {
            if (j == 8 - 1 - i - (8 - (this->positionX + this->positionY) - 1))
            {
                discoveredSteps.push_back(DiscoveredStep(j, i));
            }
        }
    }
}

std::string Bishop::getName()
{
    return "bishop";
}
