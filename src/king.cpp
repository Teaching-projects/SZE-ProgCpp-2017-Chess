#include "king.h"

King::King(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void King::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const
{
    int possibleSteps[8][2] = {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}
    };

    for (int i = 0; i < 8; i++)
    {
        int posX = this->positionX + possibleSteps[i][0];
        int posY = this->positionY + possibleSteps[i][1];

        if (posX < 8 && posX > -1 &&
            posY < 8 && posY > -1)
        {
            this->addDiscoveredStep(discoveredSteps, posX, posY, fields);
        }
    }
}

std::string King::getName()
{
    return "king";
}
