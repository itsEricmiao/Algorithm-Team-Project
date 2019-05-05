#include <iostream>
#include <gamelauncher.h>
using namespace std;

int main()
{
    string player_name1;
    string player_name2;
    cout<<"Welcome to Connect-4 With AI"<<endl;
    cout<<"Player 1: Please type in your name: ";
    cin>>player_name1;
    cout<<"Player 2: Please type in your name: ";
    cin>>player_name2;
    GameLauncher launchaer = GameLauncher(10,10);
    launchaer.set_Players_names(player_name1,player_name2);
    //launchaer.set_Players_names("Eric", "John");
    launchaer.set_Players_tokens("|O|", "|X|");
    launchaer.start_game();
    return 0;
}
