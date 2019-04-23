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
    for(int i = 0; i < row; i++)
    {
        sampleRow.push_back("| |");
    }

    for(int j = 0; j < col; j++)
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
        for(int i = 0; i < board.size(); i++)
        {
            if(i <9)
            {
                 cout<<" "<<i+1<<" ";
            }else
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
}


void GameBoard::makeMove(Player player)
{


}

