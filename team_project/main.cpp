#include <iostream>
#include <gamelauncher.h>
using namespace std;

int main()
{
    GameLauncher launchaer = GameLauncher(10,10);
    launchaer.set_Players_names("Eric", "John");
    launchaer.set_Players_tokens("|O|", "|X|");
    launchaer.start_game();
    return 0;
}
