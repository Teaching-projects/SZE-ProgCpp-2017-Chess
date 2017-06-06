#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <vector>
#include <string>
#include "piececolor.h"
#include "discoveredstep.h"

#ifndef ROW
#define ROW 8
#endif

#ifndef COL
#define COL 8
#endif

class Chesspiece
{
protected:
    int positionX;
    int positionY;
    PieceColor pieceColor;

    bool addDiscoveredStep(std::vector<DiscoveredStep>& discoveredSteps, int x, int y, Chesspiece *const fields[][COL]) const;

public:
    Chesspiece();
    Chesspiece(int x, int y, PieceColor pieceColor);
    virtual ~Chesspiece();

    void goTo(int x, int y);
    PieceColor getColor();

    virtual void discoverSteps(std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const fields[][COL]) const = 0;
    virtual std::string getName() = 0;
};

#endif // CHESSPIECE_H
