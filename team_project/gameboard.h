#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include <player.h>
using namespace std;

class GameBoard
{
private:
    vector<vector<string>> board;

public:
    GameBoard();
    GameBoard(int row, int col);

    void makeMove(Player player);
    void displayBoard();
    bool ifWin(string player);

};

#endif // GAMEBOARD_H
