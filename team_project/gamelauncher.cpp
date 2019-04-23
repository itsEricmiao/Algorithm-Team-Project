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



void GameLauncher::set_Players_names(string player1_name, string player2_name)
{
    player1.set_name(player1_name);
    player2.set_name(player2_name);
}

void GameLauncher:: start_game()
{
    int counter = 0;
    while(true)
    {
        theBoard.displayBoard();
        if(counter % 2 == 1)
        {
            int option = get_user_input(player1);
            theBoard.makeMove(player1, option);
        }else
        {
            int option = get_user_input(player2);
            theBoard.makeMove(player2, option);
        }
        counter ++;


    }

}

int GameLauncher:: get_user_input(Player player)
{
    cout<<player.get_name()<<": Please make your choice: ";
    int input;
    cin >> input;
    return input;
}
