
#ifndef EX2_KNIGHT_H
#define EX2_KNIGHT_H

#include "Piece.h"
#include "Board.h"

/**
 * Class that represent the Knight.
 */

class Knight : public Piece
{
public:

    /**
     * constructor.
     */
    Knight(string type, int color);


    /**
     * destructor.
     */
    ~Knight() override;


    /**
     * Checks if the move is legal.
     * @return true if it is, false otherwise.
     */
    bool isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player) override;


    /**
     * protecting mode setter:
     */
    void setProtectingMode(bool answer) override;

protected:
    string _type;
    int _color;

    // flag- for checking if this piece is protecting a
    // different piece with the same color.
    bool _protectingMode = false;
};


#endif //EX2_KNIGHT_H
