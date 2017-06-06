#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "chesspiece.h"

class Chessboard;

class Player
{
    friend class Chessboard;

private:
    std::vector<Chesspiece*> pieces;
    PieceColor color;

public:
    Player();
    Player(PieceColor color);

    void addPiece(Chesspiece* piece);
    void removePiece(Chesspiece* piece);
    void emptyPieces();
    bool hasPiece(const Chesspiece* piece);
    PieceColor getColor();
};

#endif // PLAYER_H
