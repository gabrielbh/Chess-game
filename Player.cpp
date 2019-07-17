#include "Player.h"


/**
 *  constructor.
 */
Player::Player(int color, string name)
{
    _color = color;
    _name = name;
}


/**
 * player color getter.
 * @return WHITE or BLACK.
 */
int Player::getColor() const
{
    return _color;
}


/**
 * player name getter.
 * @return players name.
 */
string Player::getName() const
{
    return _name;
}


/**
 * getter for player is in check.
 */
bool Player::checkGetter()
{
    return _check;
}


/**
 * setter for player is in check.
 */
void Player::checkSetter(bool yesOrNo)
{
    _check = yesOrNo;
}


/**
 * destructor.
 */
Player::~Player()
= default;

