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
        if(board[i][target] == "| |")
        {
            cout<<"Place the token in ["<<i<<"]"<<endl;
            board[i][target-1] = player.get_token();
            return true;
        }
    }
    return false;
}

