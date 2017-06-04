#include "knight.h"

Knight::Knight(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Knight::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps)
{
    int possibleSteps[8][2] = {
        {-1, 2},
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1}
    };

    for (int i = 0; i < 8; i++)
    {
        int posX = this->positionX + possibleSteps[i][0];
        int posY = this->positionY + possibleSteps[i][1];

        if (posX < 8 && posX > -1 &&
            posY < 8 && posY > -1)
        {
            discoveredSteps.push_back(DiscoveredStep(posX, posY));
        }
    }
}
