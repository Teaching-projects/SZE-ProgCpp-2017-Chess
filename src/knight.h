#ifndef KNIGHT_H
#define KNIGHT_H

#include "chesspiece.h"

class Knight : public Chesspiece
{
public:
    Knight(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps);
};

#endif // KNIGHT_H
