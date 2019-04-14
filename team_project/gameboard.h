#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
using namespace std;

class GameBoard
{
private:
    vector<vector<string>> board;
public:
    GameBoard();
    void makeMove();
    void displayBoard();
    bool ifWin(string player);

};

#endif // GAMEBOARD_H
