#include "gamelauncher.h"

GameLauncher::GameLauncher()
{

}

GameLauncher::GameLauncher(int row, int col)
{
    theBoard = GameBoard(row, col);
}


void GameLauncher::set_Players_tokens(string player1_token, string player2_token)
{
    player1.set_token(player1_token);
    player2.set_token(player2_token);
}


void GameLauncher:: start_game()
{
    theBoard.displayBoard();
}
