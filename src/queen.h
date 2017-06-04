#ifndef QUEEN_H
#define QUEEN_H

#include "chesspiece.h"

class Queen : public Chesspiece
{
public:
    Queen(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps);
};

#endif // QUEEN_H
