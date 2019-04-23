#include <iostream>
#include <gamelauncher.h>
using namespace std;

int main()
{
    GameLauncher launchaer = GameLauncher(9,7);
    launchaer.set_Players_names("Mark", "John");
    launchaer.set_Players_tokens("|O|", "|X|");
    launchaer.start_game();
    return 0;
}
