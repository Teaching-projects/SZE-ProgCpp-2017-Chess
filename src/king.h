#ifndef KING_H
#define KING_H

#include "chesspiece.h"

class King : public Chesspiece
{
public:
    King(int x, int y, PieceColor pieceColor);

    void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const override;
    std::string getName();
};

#endif // KING_H
