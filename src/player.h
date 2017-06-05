#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "chesspiece.h"

class Chessboard;

class Player
{
private:
    std::vector<Chesspiece*> pieces;

public:
    Player();

    void discoverStepsForAll(Chessboard& chessboard);
    void addPiece(Chesspiece* piece);
    void emptyPieces();
    bool hasPiece(const Chesspiece* piece);
};

#endif // PLAYER_H
