
#ifndef EX2_KING_H
#define EX2_KING_H

#include "Piece.h"
#include "Board.h"


/**
 * Class that represent the King.
 */
class King : public Piece
{
public:

    /**
     * constructor.
     */
    King(string basic_string, int i);

    /**
     * destructor.
     */
    ~King() override;


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
     * can castle setter:
     */
    void canCastleSetter() override;


    /**
     * protecting mode setter:
     */
    void setProtectingMode(bool answer) override;

protected:
    string _type;
    int _color;
    // boolean flag that answers if we can castle.
    bool _canCastle = true;

    // flag- for checking if this piece is protecting a
    // different piece with the same color.
    bool _protectingMode = false;
};


#endif //EX2_KING_H
