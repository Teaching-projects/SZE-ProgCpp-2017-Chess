#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "discoveredstep.h"
#include "chesspiece.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "player.h"

//#define DEBUG_STEPS

#ifndef ROW
#define ROW 8
#endif

#ifndef COL
#define COL 8
#endif

class Chessboard
{
    friend class Player;

private:
    Chesspiece *pieceFields[ROW][COL];
    Chesspiece *tmpPieceFields[ROW][COL];
    Chesspiece *selectedPiece;
    std::vector<DiscoveredStep> discoveredSteps;

    int selectedX;
    int selectedY;

    void clearChessboard();
    void emptyDiscoveredSteps();
    void copyPieceFields();

public:
    Chessboard();
    ~Chessboard();

    void replacePieces();
    void addPiecesToPlayers(Player& whitePlayer, Player& blackPlayer);
    bool selectPiece(int x, int y, Player& activePlayer, Player& enemyPlayer);
    bool changeSelection(int x, int y);
    bool movePieceTo(int x, int y, Player& enemyPlayer);
    void getPieceNames(std::vector<std::string>& pieceNames);
    void ruleDiscoveredSteps(Player& enemyPlayer);
    bool isEnemyInCheck(Player& player);
    bool isEnemyInCheck(Player& player, std::vector<DiscoveredStep>& discoveredSteps, Chesspiece *const pieceFields[][COL]);
    bool isCheckmate(Player& activePlayer, Player& enemyPlayer);
    std::vector<DiscoveredStep> getDiscoveredSteps();
};

#endif // CHESSBOARD_H
