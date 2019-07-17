#include "King.h"


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool King::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    if (this->getColor() != player->getColor())
    {
        return false;
    }
    if (!_protectingMode)
    {
        if (player->getColor() == board->isOccupied(destRow, destColumn))
        {
            return false;
        }
    }
    if ((abs(destRow - srcRow) > 1) || (abs(destColumn - srcColumn > 1)))
    {
        return false;
    }
    _canCastle = false;
    return true;
}

/**
 * constructor.
 */
King::King(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * getter if we can castle or not.
 */
bool King::canCastleGetter()
{
    return _canCastle;
}


/**
 * can castle setter:
 */
void King::canCastleSetter()
{
    _canCastle = false;
}


/**
 * protecting mode setter:
 */
void King::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
King::~King()
= default;

