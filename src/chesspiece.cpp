#include "chesspiece.h"

Chesspiece::Chesspiece() : Chesspiece(-1, -1, white) {}

Chesspiece::Chesspiece(int x, int y, PieceColor pieceColor)
{
    this->positionX = x;
    this->positionY = y;
    this->pieceColor = pieceColor;
    this->hasBeenHit = false;
}

Chesspiece::~Chesspiece() {}

void Chesspiece::goTo(int x, int y)
{
    this->positionX = x;
    this->positionY = y;
}

void Chesspiece::getHit()
{
    this->hasBeenHit = true;
}

bool Chesspiece::isHit()
{
    return this->hasBeenHit;
}

PieceColor Chesspiece::getColor()
{
    return this->pieceColor;
}
