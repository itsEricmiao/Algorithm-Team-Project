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
    AI_view = GameBoard(row, col);
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

void GameLauncher::set_two_Player_game()
{
    string player_name1;
    string player_name2;
    cout<<"Player 1: Please type in your name: ";
    cin>>player_name1;
    cout<<"Player 2: Please type in your name: ";
    cin>>player_name2;
    set_Players_names(player_name2,player_name1);
}

void GameLauncher::set_AI_Player_game()
{
    string player_name1;
    string player_name2;
    cout<<"Player 1: Please type in your name: ";
    cin>>player_name1;
    cout<<"Player 2: Please type in your name: ";
    cin>>player_name2;
    set_Players_names(player_name2,player_name1);


}

void GameLauncher::my_game(){
    cout<<"Running my algorithm."<<endl;

    bool empty;

    int counter = 0;
    bool ifContinue = true;
    bool valid;
    theBoard.displayBoard();
    while(ifContinue)
    {
        if(counter % 2 == 1)
        {
            int option=think();
//            int option = rand() % 8 + 1;
            valid = theBoard.makeMove(player1, option);
            empty = AI_view.makeMove(player1, option);
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
            empty = AI_view.makeMove(player2, option);
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

int GameLauncher:: think(){

    int User[32];
    int AI[32];
    int rankAnswer [8];



    for(unsigned int z=1; z<1000;z++){

            bool ifContinue=true;
            AI_view=theBoard;

            for(int i=0;i<32;i++)
                User[i]=0;
            int counterOfUser=0;

            for(int i=0;i<32;i++)
                AI[i]=0;
            int counterOfAI=0;

            for(int i=0;i<9;i++){
                rankAnswer [i]=0;
            }

            int counter = 0;
            bool valid;

            while(ifContinue)
            {
                if(counter % 2 == 1)
                {
                    int option = rand() % 8 + 1;
                    valid = AI_view.makeMove(player1, option);
                    AI_view.displayBoard();
                    User[counter/2+ counter% 2]=option;
                    bool ifWin = AI_view.checkIfWin(player1);
                    if(ifWin)
                    {
                        cout<<"Congrats! Player ["<<player1.get_name()<<"] Wins!"<<endl;
                        rankAnswer[User[0]]--;
                        break;
                    }
                }else
                {
                    int option = rand() % 8 + 1;
                    valid = AI_view.makeMove(player2, option);
                    AI[counter/2 + counter%2]=option;
                    AI_view.displayBoard();
                    bool ifWin = AI_view.checkIfWin(player2);
                    if(ifWin)
                    {
                        cout<<"Congrates! Player ["<<player2.get_name()<<"] Wins!"<<endl;
                        rankAnswer[AI[0]]++;
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

    AI_view=theBoard;

    int max=rankAnswer[1];
    int answer=1;
    for(int i=1; i<9;i++){
        if(max < rankAnswer[i]){
            max=rankAnswer[i];
            answer=i;
        }
    }

    return  answer;
}
