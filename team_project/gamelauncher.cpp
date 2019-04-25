#include "gamelauncher.h"

/*
    Default Constructor
*/
GameLauncher::GameLauncher()
{

}

/*
    Constructor
*/
GameLauncher::GameLauncher(int row, int col)
{
    theBoard = GameBoard(row, col);
}

/*
    Setter for Player's token 
*/
void GameLauncher::set_Players_tokens(string player1_token, string player2_token)
{
    player1.set_token(player1_token);
    player2.set_token(player2_token);
}


/*
    Setter for Player's name 
*/
void GameLauncher::set_Players_names(string player1_name, string player2_name)
{
    player1.set_name(player1_name);
    player2.set_name(player2_name);
}


/*
    Start the game from here
*/
void GameLauncher:: start_game()
{
    int counter = 0;
    bool ifContinue = true;
    bool valid;
    theBoard.displayBoard();
    while(ifContinue)
    {
        if(counter % 2 == 1)
        {
            int option = get_user_input(player1);
            valid = theBoard.makeMove(player1, option);
            theBoard.displayBoard();
            bool ifWin = theBoard.checkIfWin(player1);
            if(ifWin)
            {
                cout<<"Congrats! Player ["<<player1.get_name()<<"] Wins!"<<endl;
                break;
            }
        }else
        {
            int option = get_user_input(player2);
            valid = theBoard.makeMove(player2, option);
            theBoard.displayBoard();
            bool ifWin = theBoard.checkIfWin(player2);
            if(ifWin)
            {
                cout<<"Congrates! Player ["<<player2.get_name()<<"] Wins!"<<endl;
                break;
            }
        }
        if(!valid)
        {
           cout<<"The column is full, please select another one."<<endl;
        }else if (valid)
        {
            counter ++;
        }

    }
}

/*
    Getting user input
*/
int GameLauncher:: get_user_input(Player player)
{
    cout<<player.get_name()<<": Please make your choice: ";
    int input;
    cin >> input;
    return input;
}
