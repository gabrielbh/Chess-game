#include "Bishop.h"


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Bishop::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    if (this->getColor() != player->getColor() || abs(srcRow - destRow) != (abs(srcColumn - destColumn)))
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

    int steps = abs(destRow - srcRow);
    if ((destRow - srcRow > 0) && (destColumn - srcColumn > 0))
    {
        for (int i = 1; i < steps; ++i)
        {
            if (board->isOccupied(srcRow + i, srcColumn + i))
            {
                return false;
            }
        }
    }
    else if ((destRow - srcRow > 0) && (destColumn - srcColumn < 0))
    {
        for (int i = 1; i < steps; ++i)
        {
            if (board->isOccupied(srcRow + i, srcColumn - i))
            {
                return false;
            }
        }
    }
    else if ((destRow - srcRow < 0) && (destColumn - srcColumn > 0))
    {
        for (int i = 1; i < steps; ++i)
        {
            if (board->isOccupied(srcRow - i, srcColumn + i))
            {
                return false;
            }
        }
    }
    else if ((destRow - srcRow < 0) && (destColumn - srcColumn < 0))
    {
        for (int i = 1; i < steps; ++i)
        {
            if (board->isOccupied(srcRow - i, srcColumn - i))
            {
                return false;
            }
        }
    }

    return true;
}


/**
 * constructor.
 */
Bishop::Bishop(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * protecting mode setter:
 */
void Bishop::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
Bishop::~Bishop()
= default;

