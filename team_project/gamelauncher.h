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
    void set_Players_names(string player1_name, string player2_name);
    void start_game();
    void set_AI_Player_game();
    void set_two_Player_game();
    int get_user_input(Player player);
    bool checkIfWin(Player player);
};

#endif // GAMELAUNCHER_H
