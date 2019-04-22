#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
    string player_name;
    bool win;
public:
    Player();
    Player(string name);
    void set_name(string name);
    bool ifWin();
};

#endif // PLAYER_H
