#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "chessboard.h"
#include "player.h"

class Game
{
private:
    Chessboard chessboard;
    Player whitePlayer;
    Player blackPlayer;
    Player *activePlayer;

public:
    Game();

    void startNew();
    bool selectPieceForStep(int x, int y);
    bool changeSelection(int x, int y);
    bool movePieceTo(int x, int y);
    bool isEnemyInCheck();
    void getChessPieces(std::vector<std::string>& pieceNames);
    std::vector<DiscoveredStep> getDiscoveredSteps();
};

#endif // GAME_H
