#include "Rook.h"


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Rook::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    if (this->getColor() != player->getColor() || (srcRow != destRow && srcColumn != destColumn))
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
    _canCastle = false;
    return true;
}


/**
 * constructor.
 */
Rook::Rook(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * getter if we can castle or not.
 */
bool Rook::canCastleGetter()
{
    return _canCastle;
}


/**
 * protecting mode setter:
 */
void Rook::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
Rook::~Rook()
= default;
