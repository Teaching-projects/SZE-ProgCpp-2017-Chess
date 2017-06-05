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
    PieceColor activePlayer;

public:
    Game();

    void startNew();
    bool selectPieceForStep(int x, int y);
    bool movePieceTo(int x, int y);
};

#endif // GAME_H
