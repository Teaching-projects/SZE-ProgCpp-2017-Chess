#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>
#include "discoveredstep.h"
#include "chesspiece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"

class Player;

class Chessboard
{
    friend class Player;

private:
    Chesspiece *pieceFields[8][8];
    Chesspiece *selectedPiece;
    std::vector<DiscoveredStep> discoveredSteps;

    void clearChessboard();
    void emptyDiscoveredSteps();

public:
    Chessboard();
    ~Chessboard();

    void replacePieces();
};

#endif // CHESSBOARD_H
