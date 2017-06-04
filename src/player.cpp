#include "player.h"

Player::Player()
{

}

void Player::discoverStepsForAll(Chessboard& chessboard)
{
    for (int i = 0; i < sizeof(this->pieces) / sizeof(this->pieces[0]); i++)
    {
        //this->pieces[i]->discoverSteps();

        // do something
    }
}
