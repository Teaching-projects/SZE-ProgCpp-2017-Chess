#ifndef BISHOP_H
#define BISHOP_H

#include "chesspiece.h"

class Bishop : public Chesspiece
{
public:
    Bishop(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps);
};

#endif // BISHOP_H
