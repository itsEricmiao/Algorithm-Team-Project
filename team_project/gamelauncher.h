#ifndef GAMELAUNCHER_H
#define GAMELAUNCHER_H

#include <gameboard.h>
#include <player.h>
using namespace std;

class GameLauncher
{
private:
    GameBoard theBoard;
    Player player1;
    Player player2;
public:
    GameLauncher();
    GameLauncher(int row, int col);
    void set_Players_tokens(string player1_token, string player2_token);
    void start_game();
};

#endif // GAMELAUNCHER_H
