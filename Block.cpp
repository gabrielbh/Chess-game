#include "Block.h"

/**
 * default constructor.
 */
Block::Block()
{

}


/**
 * constructor.
 */
Block::Block(int color, int row, int column, Piece *piece)
{
    _color = color;
    _row = row;
    _column = column;
    _piece = piece;
}


/**
 * piece setter.
 */
void Block::setPiece(Piece *piece)
{
    _piece = piece;
}


/**
 * prints a single block.
 */

void Block::printBlock()
{
    if (_piece == nullptr)
    {
        cout << "\33[0;" << _color << "m \33[0m";
        return;
    }
    else if (_piece->getType() == "265A")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265A\33[0m";
    }
    else if (_piece->getType() == "265B")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265B\33[0m";
    }
    else if (_piece->getType() == "265C")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265C\33[0m";
    }
    else if (_piece->getType() == "265D")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265D\33[0m";
    }
    else if (_piece->getType() == "265E")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265E\33[0m";
    }
    else if (_piece->getType() == "265F")
    {
        cout << "\33[" << _piece->getColor() << ";" << _color << "m\u265F\33[0m";
    }
}


/**
 * piece getter.
 */
Piece *Block::getPiece() const
{
    return _piece;
}


/**
     * block color getter.
 */
int Block::getColor() const
{
    return _color;
}


/**
 * block row getter.
 */
int Block::getRow() const
{
    return _row;
}


/**
 * block column getter.
 */
int Block::getColumn() const
{
    return _column;
}

/**
 * destructor.
 */
Block::~Block()
= default;
