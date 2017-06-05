#include "player.h"

Player::Player()
{

}

void Player::discoverStepsForAll(Chessboard& chessboard)
{
    for (int i = 0; i < this->pieces.size(); i++)
    {
        //this->pieces[i]->discoverSteps();

        // do something
    }
}

void Player::addPiece(Chesspiece* piece)
{
    this->pieces.push_back(piece);
}

void Player::emptyPieces()
{
    this->pieces.clear();
}
