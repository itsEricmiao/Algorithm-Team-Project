#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
    string player_name;
    string token;
    bool win;
public:
    Player();
    Player(string name, string icon);
    void set_name(string name);
    void set_token(string symbol);
    bool ifWin();
};

#endif // PLAYER_H
