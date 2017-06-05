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

//class Player;
#include "player.h"

class Chessboard
{
    friend class Player;

private:
    Chesspiece *pieceFields[8][8];
    Chesspiece *selectedPiece;
    std::vector<DiscoveredStep> discoveredSteps;

    int selectedX;
    int selectedY;

    void clearChessboard();
    void emptyDiscoveredSteps();

public:
    Chessboard();
    ~Chessboard();

    void replacePieces();
    void addPiecesToPlayers(Player& whitePlayer, Player& blackPlayer);
    bool selectPiece(int x, int y);
    bool movePieceTo(int x, int y);
};

#endif // CHESSBOARD_H
