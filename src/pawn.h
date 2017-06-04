#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"

class Pawn : public Chesspiece
{
public:
    Pawn(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps);
};

#endif // PAWN_H
