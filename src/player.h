#ifndef PLAYER_H
#define PLAYER_H

#include "chesspiece.h"

class Chessboard;

class Player
{
private:
    Chesspiece *pieces[16];

public:
    Player();

    void discoverStepsForAll(Chessboard& chessboard);
};

#endif // PLAYER_H
