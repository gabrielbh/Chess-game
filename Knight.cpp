
#include "Knight.h"

/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Knight::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
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

    return ((abs(destRow - srcRow) == 2) && (abs(destColumn - srcColumn) == 1))
           || ((abs(destRow - srcRow) == 1) && (abs(destColumn - srcColumn) == 2));
}


/**
 * constructor.
 */
Knight::Knight(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * protecting mode setter:
 */
void Knight::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
Knight::~Knight()
= default;
