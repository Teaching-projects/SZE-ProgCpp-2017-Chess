#ifndef ROOK_H
#define ROOK_H

#include "chesspiece.h"

class Rook : public Chesspiece
{
public:
    Rook(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const override;
    std::string getName();
};

#endif // ROOK_H
