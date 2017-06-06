#include "player.h"

Player::Player()
{

}

Player::Player(PieceColor color)
{
    this->color = color;
}

void Player::addPiece(Chesspiece* piece)
{
    this->pieces.push_back(piece);
}

void Player::removePiece(Chesspiece* piece)
{
    for (int i = 0; i < this->pieces.size(); i++)
    {
        if (this->pieces[i] == piece)
        {
            this->pieces.erase(this->pieces.begin() + i);
            break;
        }
    }
}

void Player::emptyPieces()
{
    this->pieces.clear();
}

bool Player::hasPiece(const Chesspiece* piece)
{
    for (int i = 0; i < this->pieces.size(); i++)
    {
        if (this->pieces[i] == piece)
        {
            return true;
        }
    }

    return false;
}

PieceColor Player::getColor()
{
    return this->color;
}
