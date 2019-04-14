#include "gameboard.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
GameBoard::GameBoard()
{
    vector<string> sampleRow;
    for(int i = 0; i < 10; i++)
    {
        sampleRow.push_back("- ");
    }

    for(int j = 0; j < 10; j++)
    {
        board.push_back(sampleRow);
    }

}

void GameBoard::displayBoard()
{
    cout<<"=====Game Board====="<<endl;

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
        cout<<"1 2 3 4 5 6 7 8 9 10"<<endl;
}




