#include "Queen.h"


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Queen::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    if ((srcRow != destRow && srcColumn != destColumn) && (abs(srcRow - destRow) != (abs(srcColumn - destColumn))))
    {
        return false;
    }

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

    int steps;

    // Rook steps:
    if (srcRow == destRow && srcColumn != destColumn)
    {
        steps = destColumn - srcColumn;
        if (steps > 0)
        {
            for (int i = 1; i < steps; ++i)
            {
                if (board->isOccupied(srcRow, srcColumn + i))
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < -1 * steps; ++i)
            {
                if (player->getColor() == board->isOccupied(srcRow, srcColumn - i))
                {
                    return false;
                }
            }
        }
    }
    else if (srcRow != destRow && srcColumn == destColumn)
    {
        steps = destRow - srcRow;
        if (steps > 0)
        {
            for (int i = 1; i < steps; ++i)
            {
                if (board->isOccupied(srcRow + i, destColumn))
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < -1 * steps; ++i)
            {
                if (board->isOccupied(srcRow - i, destColumn))
                {
                    return false;
                }
            }
        }
    }

    // bishop steps:
    steps = abs(destRow - srcRow);
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
Queen::Queen(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * protecting mode setter:
 */
void Queen::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
Queen::~Queen()
= default;
