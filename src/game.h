#ifndef GAME_H
#define GAME_H

#include "chessboard.h"
#include "player.h"

class Game
{
private:
    Chessboard chessboard;
    Player whitePlayer;
    Player blackPlayer;

public:
    Game();

    void startNew();
    void selectPieceForStep(int x, int y);
    void movePieceTo(int x, int y);
};

#endif // GAME_H
