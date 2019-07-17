#ifndef EX2NEW_ROOK_H
#define EX2NEW_ROOK_H

#include "Piece.h"
#include "Board.h"


/**
 * Class that represent the Rook.
 */
class Rook : public Piece
{
public:

    /**
     * constructor.
     */
        Rook(string type, int color);



    /**
     * destructor.
     */
    ~Rook() override;


    /**
     * Checks if the move is legal.
     * @return true if it is, false otherwise.
     */
    bool isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player) override;


    /**
     * getter if we can castle or not.
     */
    bool canCastleGetter() override;


    /**
     * protecting mode setter:
     */
    void setProtectingMode(bool answer) override;

protected:

    // flag- for checking if this piece is protecting a
    // different piece with the same color.
    bool _protectingMode = false;

    // boolean flag that answers if we can castle.
    bool _canCastle = true;
    string _type;
    int _color;
};


#endif //EX2NEW_ROOK_H
