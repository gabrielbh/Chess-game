#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"


/**
 * default constructor.
 */
Piece::Piece()
{

}


/**
 *  constructor.
 */
Piece::Piece(string type, int color)
{
    _type = type;
    _color = color;
}


/**
 * piece color getter.
 * @return WHITE or BLACK.
 */
int Piece::getColor() const
{
    return _color;
}


/**
 * piece type getter.
 * @return string that represent the piece type.
 */
string Piece::getType() const
{
    return _type;
}


/**
 * Checks if the move is legal.
 * @return true if it is, false otherwise.
 */
bool Piece::isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player)
{
    // this function in Piece is ment to be override. therfore it will never be used.
    if (srcRow < 9 && srcColumn < 9 && destRow < 9 && destColumn < 9 && board == nullptr && player == nullptr)
    {
        return false;
    }
    return false;
}


/**
 * @return a new piece with the correct type (Pawn, Bishop etc.)
 */
Piece *Piece::getNewPiece(string type)
{
    if (type == PAWN)
    {
        return new Pawn(PAWN, _color);
    }
    else if (type == BISHOP)
    {
        return new Bishop(BISHOP, _color);
    }
    else if (type == ROOK)
    {
        return new Rook(ROOK, _color);
    }
    else if (type == KNIGHT)
    {
        return new Knight(KNIGHT, _color);
    }
    else if (type == QUEEN)
    {
        return new Queen(QUEEN, _color);
    }
    else if (type == KING)
    {
        return new King(KING, _color);
    }
    return nullptr;
}


/**
 * getter if we can castle or not.
 */
bool Piece::canCastleGetter()
{
    return false;
}


/**
 * can castle setter:
 */
void Piece::canCastleSetter()
{
    return;
}


/**
 * true if a pawn should turn to queen.
 */
bool Piece::pawnToQueenGetter()
{
    return false;
}


/**
 * protecting mode setter:
 */
void Piece::setProtectingMode(bool answer)
{
    _protectingMode = answer;
}


/**
 * destructor
*/
Piece::~Piece()
= default;
