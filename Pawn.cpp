#include "Pawn.h"


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Pawn::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    // white player:
    if (player->getColor() == WHITE)
    {
        if (!_protectingMode)
        {
            if (WHITE == board->isOccupied(destRow, destColumn))
            {
                return false;
            }
        }
        if (destColumn != srcColumn)
        {
            // Pawn killing options:
            if (abs(destColumn - srcColumn) == 1 && destRow - srcRow == 1
                && board->isOccupied(destRow, destColumn) == BLACK)
            {
                if (destRow == 7)
                {
                    _turnToQueen = true;
                }
                return true;
            }
        }
        else if (srcRow == 1 && destRow == 3)
        {
            return !(board->isOccupied(srcRow + 1, destColumn) || board->isOccupied(destRow, destColumn));
        }
        else if (destRow - srcRow == 1 && !board->isOccupied(destRow, destColumn))
        {
            if (destRow == 7)
            {
                _turnToQueen = true;
            }
            return true;
        }
    }


        // black player:
    else
    {
        if (!_protectingMode)
        {
            if (BLACK == board->isOccupied(destRow, destColumn))
            {
                return false;
            }
        }
        if (destColumn != srcColumn)
        {
            // Pawn killing options:
            if (abs(destColumn - srcColumn) == 1 && srcRow - destRow == 1
                && board->isOccupied(destRow, destColumn) == WHITE)
            {
                if (destRow == 0)
                {
                    _turnToQueen = true;
                }
                return true;
            }
        }
        else if (srcRow == 6 && destRow == 4)
        {
            return !(board->isOccupied(srcRow - 1, destColumn) || board->isOccupied(destRow, destColumn));
        }
        else if (srcRow - destRow == 1 && !board->isOccupied(destRow, destColumn))
        {
            if (destRow == 0)
            {
                _turnToQueen = true;
            }
            return true;
        }
    }
    return false;
}


/**
 * constructor.
 */
Pawn::Pawn(string type, int color) : Piece(type, color)
{
    _type = type;
    _color = color;
}


/**
 * true if a pawn should turn to queen.
 */
bool Pawn::pawnToQueenGetter()
{
    return _turnToQueen;
}


/**
 * protecting mode setter:
 */
void Pawn::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor.
 */
Pawn::~Pawn()
= default;


