#include "pawn.h"

Pawn::Pawn(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Pawn::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps) const
{
    int possibleSteps[3][2] = {
        {-1, 0}, // only when hitting enemy
        {0, 0},
        {1, 0} // only when hitting enemy
    };

    for (int i = 0; i < 3; i++)
    {
        possibleSteps[i][1] = this->pieceColor == white ? -1 : 1;
    }

    for (int i = 0; i < 3; i++)
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

std::string Pawn::getName()
{
    return "pawn";
}
