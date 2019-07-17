#ifndef EX2NEW_PLAYER_H
#define EX2NEW_PLAYER_H

#include <iostream>

using namespace std;


/**
 * A class that represents a player.
 */
class Player
{

private:
    int _color;
    string _name;
    bool _check = false;

public:

    /**
     *  constructor.
     */
    Player(int color, string name);


    /**
     * destructor.
     */
    ~Player();

    /**
     * player color getter.
     * @return WHITE or BLACK.
     */
    int getColor() const;


    /**
     * player name getter.
     * @return players name.
     */
    string getName() const;


    /**
     * getter for player is in check.
     */
    bool checkGetter();


    /**
     * setter for player is in check.
     */
    void checkSetter(bool yesOrNo);

};


#endif //EX2NEW_PLAYER_H
