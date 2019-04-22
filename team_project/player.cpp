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
Player::Player(string name)
{
    player_name = name;
}


/*
    Setter for player name
*/
void Player::set_name(string name)
{
    player_name = name;
}

/*
    Check and see if player wins
*/
bool Player::ifWin()
{
    return win;
}
