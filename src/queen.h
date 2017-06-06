#ifndef QUEEN_H
#define QUEEN_H

#include "chesspiece.h"

class Queen : public Chesspiece
{
public:
    Queen(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const override;
    std::string getName();
};

#endif // QUEEN_H
