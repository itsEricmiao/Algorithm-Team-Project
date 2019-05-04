#include "gameboard.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Default constructor for GameBoard
*/
GameBoard::GameBoard()
{
    vector<string> sampleRow;
    for(int i = 0; i < 10; i++)
    {
        sampleRow.push_back("| |");
    }

    for(int j = 0; j < 10; j++)
    {
        board.push_back(sampleRow);
    }
}

/*
    Constructor for a customized-size GameBoard
*/
GameBoard::GameBoard(int row, int col)
{
    vector<string> sampleRow;
    for(int i = 0; i < col; i++)
    {
        sampleRow.push_back("| |");
    }

    for(int j = 0; j < row; j++)
    {
        board.push_back(sampleRow);
    }

}

/*
    displayBoard function is for printing the game board
*/
void GameBoard::displayBoard()
{
    cout<<"Game Board: "<<endl;

    //Printing the row of the gameboard
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    //Printing the col of the gameboard
    for(int i = 0; i < board[0].size(); i++)
    {
        if(i < 9)
        {
            cout<<" "<<i+1<<" ";
        }else
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

int GameBoard::get_max_col()
{
    return board.size();
}

bool GameBoard::makeMove(Player player, int target)
{
    for(int i = board.size()-1; i >= 0; i--)
    {
        if(board[i][target-1] == "| |")
        {
            board[i][target-1] = player.get_token();
            return true;
        }
    }
    return false;
}

bool GameBoard::checkIfWin(Player player)
{
    bool checkH = checkHorizontalWin(player);
    bool checkV = checkVerticalWin(player);
    bool checkL = checkDiagnalLeftToRight(player);
    bool checkR = checkDiagnalRightToLeft(player);
    if(checkH || checkV || checkL || checkR)
    {
        return true;
    }
    return false;
}

//checks for a horizontal 4-match
bool GameBoard::checkHorizontalWin(Player player)
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == player.get_token() && board[i][j+1] == player.get_token()&&
                    board[i][j+2] == player.get_token() && board[i][j+3] == player.get_token())
            {
                return true;
            }
        }
    }
    return false;
}


//checks for a Vertical 4-match
bool GameBoard::checkVerticalWin(Player player)
{
    //loop through each column
    for(int i = 0; i < board[0].size(); i++)
    {
        for(int j = 0; j < board.size()-3; j++)
        {
            if(board[j][i] == player.get_token() && board[j+1][i] == player.get_token()&&
                    board[j+2][i] == player.get_token() && board[j+3][i] == player.get_token())
            {
                return true;
            }
        }
    }
    return false;
}

bool GameBoard::checkDiagnalLeftToRight(Player player)
{
    for (int i=3; i<board[0].size(); i++){
        for (int j=0; j<board.size()-3; j++){
            if (board[i][j] == player.get_token() && board[i-1][j+1] == player.get_token() &&
                    board[i-2][j+2] == player.get_token() && board[i-3][j+3] == player.get_token())
            {
                return true;
            }
        }
    }
    return false;
}


bool GameBoard::checkDiagnalRightToLeft(Player player)
{
    for (int i=3; i<board[0].size(); i++){
        for (int j=3; j<board.size(); j++){
            if (board[i][j] ==  player.get_token() && board[i-1][j-1] ==  player.get_token() &&
                    board[i-2][j-2] ==  player.get_token() && board[i-3][j-3] ==  player.get_token())
            {
                return true;
            }
        }
    }
    return false;
}
