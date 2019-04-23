#include <iostream>
#include <gamelauncher.h>
using namespace std;

int main()
{
    GameLauncher launchaer = GameLauncher(10,10);
    launchaer.start_game();
    return 0;
}
