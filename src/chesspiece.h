#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <vector>
#include "piececolor.h"
#include "discoveredstep.h"

class Chesspiece
{
protected:
    int positionX;
    int positionY;
    PieceColor pieceColor;
    bool hasBeenHit;

public:
    Chesspiece();
    Chesspiece(int x, int y, PieceColor pieceColor);
    virtual ~Chesspiece();

    void goTo(int x, int y);
    void getHit();
    bool isHit();
    PieceColor getColor();

    virtual void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps) = 0;
};

#endif // CHESSPIECE_H
