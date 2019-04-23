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

    bool makeMove(Player player, int target);
    void displayBoard();
    bool ifWin(string player);
    int get_max_col();

};

#endif // GAMEBOARD_H
