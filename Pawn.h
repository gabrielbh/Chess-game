
#ifndef EX2_PAWN_H
#define EX2_PAWN_H

#include "Piece.h"
#include "Board.h"


/**
 * Class that represent the Pawn.
 */
class Pawn : public Piece
{
public:

    /**
     * constructor.
     */
    Pawn(string type, int color);


    /**
     * destructor.
     */
    ~Pawn() override;


    /**
     * Checks if the move is legal.
     * @return true if it is, false otherwise.
     */
    bool isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player) override;


    /**
     * true if a pawn should turn to queen.
     */
    bool pawnToQueenGetter() override;


    /**
     * protecting mode setter:
     */
    void setProtectingMode(bool answer) override;


protected:
    string _type;
    int _color;
    // boolean flag that answers if the Pawn should torn to a Queen.
    bool _turnToQueen = false;

    // flag- for checking if this piece is protecting a
    // different piece with the same color.
    bool _protectingMode = false;
};


#endif //EX2_PAWN_H
