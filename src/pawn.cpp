#include "pawn.h"

Pawn::Pawn(int x, int y, PieceColor pieceColor) : Chesspiece(x, y, pieceColor) {}

void Pawn::discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const
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
            switch (i)
            {
                case 0:
                case 2:
                    if (fields[posY][posX] != nullptr && fields[posY][posX]->getColor() != this->pieceColor)
                    {
                        this->addDiscoveredStep(discoveredSteps, posX, posY, fields);
                    }
                    break;
                case 1:
                    if (fields[posY][posX] == nullptr)
                    {
                       this->addDiscoveredStep(discoveredSteps, posX, posY, fields);
                    }
                    break;
            }
        }
    }
}

std::string Pawn::getName()
{
    return "pawn";
}
