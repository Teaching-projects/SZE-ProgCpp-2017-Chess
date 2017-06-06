#include "queen.h"

Queen::Queen(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Queen::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const
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

    bool exitHelper1, exitHelper2 = true;

    for (int i = this->positionY + 1; i < 8 && (exitHelper1 || exitHelper2); i++)
    {
        // lower '\'
        for (int j = this->positionX + 1; j < 8 && exitHelper1; j++)
        {
            if (j == i + (this->positionX - this->positionY))
            {
                if (!this->addDiscoveredStep(discoveredSteps, j, i, fields))
                {
                    exitHelper1 = false;
                    break;
                }
            }
        }

        // lower '/'
        for (int j = this->positionX - 1; j > -1 && exitHelper2; j--)
        {
            if (j == 8 - 1 - i - (8 - (this->positionX + this->positionY) - 1))
            {
                if (!this->addDiscoveredStep(discoveredSteps, j, i, fields))
                {
                    exitHelper2 = false;
                    break;
                }
            }
        }
    }

     exitHelper1 = exitHelper2 = true;

    for (int i = this->positionY - 1; i > -1 && (exitHelper1 || exitHelper2); i--)
    {
        // upper '\'
        for (int j = this->positionX - 1; j > -1 && exitHelper1; j--)
        {
            if (j == i + (this->positionX - this->positionY))
            {
                if (!this->addDiscoveredStep(discoveredSteps, j, i, fields))
                {
                    exitHelper1 = false;
                    break;
                }
            }
        }

        // upper '/'
        for (int j = this->positionX + 1; j < 8 && exitHelper2; j++)
        {
            if (j == 8 - 1 - i - (8 - (this->positionX + this->positionY) - 1))
            {
                if (!this->addDiscoveredStep(discoveredSteps, j, i, fields))
                {
                    exitHelper2 = false;
                    break;
                }
            }
        }
    }
}

std::string Queen::getName()
{
    return "queen";
}
