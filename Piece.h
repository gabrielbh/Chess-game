#ifndef EX2NEW_PIECE_H
#define EX2NEW_PIECE_H

#include <iostream>
#include "Board.h"

using namespace std;

static const string PAWN = "265F";
static const string BISHOP = "265D";
static const string KNIGHT = "265E";
static const string ROOK = "265C";
static const string QUEEN = "265B";
static const string KING = "265A";

class Player;

class Board;


/**
 * A class that represents a Piese on the board.
 */
class Piece
{

protected:
    string _type;
    int _color;

    // flag- for checking if this piece is protecting a
    // different piece with the same color.
    bool _protectingMode = false;
public:
    /**
     * default constructor.
     */
    Piece();

    /**
     *  constructor.
     */
    Piece(string type, int color);


    /**
     * destructor
     */
    virtual ~Piece();

    /**
     * @return a new piece with the correct type (Pawn, Bishop etc.)
     */
    Piece *getNewPiece(string type);


    /**
     * piece color getter.
     * @return WHITE or BLACK.
     */
    virtual int getColor() const;


    /**
     * piece type getter.
     * @return string that represent the piece type.
     */
    virtual string getType() const;


    /**
     * Checks if the move is legal.
     * @return true if it is, false otherwise.
     */
    virtual bool isValidMove(int srcRow, int srcColumn, int destRow, int destColumn, Board *board, Player *player);


    /**
     * getter if we can castle or not.
     * @return
     */
    virtual bool canCastleGetter();


    /**
     * can castle setter:
     */
    virtual void canCastleSetter();


    /**
     * true if a pawn should turn to queen.
     */
    virtual bool pawnToQueenGetter();


    /**
     * protecting mode setter:
     */
    virtual void setProtectingMode(bool answer);
};

#endif //EX2NEW_PIECE_H
