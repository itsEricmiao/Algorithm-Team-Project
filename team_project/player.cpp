#include "player.h"

/*
    Default Constrcutor
*/
Player::Player()
{

}

/*
    Constrcutor
*/
Player::Player(string name, string icon)
{
    player_name = name;
    token = icon;
}


/*
    Setter for player name
*/
void Player::set_name(string name)
{
    player_name = name;
}


void Player::set_token(string icon)
{
    token = icon;
}


string Player::get_name()
{
    return player_name;
}

string Player::get_token()
{
    return token;
}

/*
    Check and see if player wins
*/
bool Player::ifWin()
{
    return win;
}
