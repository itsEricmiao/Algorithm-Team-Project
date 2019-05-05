#include <iostream>
#include <gamelauncher.h>
using namespace std;
int get_map_size();
int choose_mode();

int main()
{
    cout<<"Welcome to Connect-4 With AI"<<endl;
    //int map_size = get_map_size();
    GameLauncher launchaer = GameLauncher(8,8);
    int game_mode = choose_mode();
    if(game_mode == 1)
    {
        launchaer.set_two_Player_game();
    }
    else
    {
        launchaer.set_AI_Player_game();
    }
    launchaer.set_Players_tokens("|O|", "|X|");
    launchaer.start_game();
    return 0;
}

int get_map_size()
{
    cout<<"Please choose your map size: "<<endl;
    cout<<"S: small board    "<<"M: medium board    "<<"L: large board"<<endl;
    char option;
    cin >> option;
    int size;
    if(option == 'S')
    {
        size = 5;
    }else if(option == 'M')
    {
        size = 10;
    }else if (option == 'L')
    {
        size = 15;
    }
    return size;
}

int choose_mode()
{
    cout<<"Please choose your Game Mode:"<<endl;
    cout<<"1. Play with another player"<<endl;
    cout<<"2. Play with computer AI"<<endl;
    int option;
    cin >> option;
    return option;
}
