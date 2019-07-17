#ifndef EX2NEW_BLOCK_H
#define EX2NEW_BLOCK_H

#include "Piece.h"

class Piece;

/**
 * A class that represent a single chess block on the board.
 */
class Block
{
private:
    int _color;
    int _row;
    int _column;
    Piece *_piece;

public:

    /**
     * default constructor.
     */
    Block();


    /**
     * destructor.
     */
    ~Block();

    /**
     * constructor.
     */
    Block(int color, int row, int column, Piece *piece = nullptr);

    /**
     * block color getter.
     */
    int getColor() const;

    /**
     * block row getter.
     */
    int getRow() const;

    /**
     * block column getter.
     */
    int getColumn() const;

    /**
     * piece getter.
     */
    Piece *getPiece() const;

    /**
     * piece setter.
     */
    void setPiece(Piece *piece);


    /**
     * prints a single block.
     */
    void printBlock();

};


#endif //EX2NEW_BLOCK_H
