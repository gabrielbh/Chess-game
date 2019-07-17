#ifndef EX2NEW_BOARD_H
#define EX2NEW_BOARD_H

#include "Block.h"
#include "Player.h"

//color white representation:
static const int WHITE = 37;

//color black representation:
static const int BLACK = 30;

//color green representation:
static const int GREEN = 42;

//color blue representation:
static const int BLUE = 46;

// the difference between the printed board part and num\letter part:
static const int DIFF = 2;

class Block;


/**
 * A class that represent the chess board.
 */
class Board
{

private:
    Block **_blocks;
    Player *_whitePlayer;
    Player *_blackPlayer;

public:

    /**
     * Board constructor.
     */
    Board(Player *whitePlayer, Player *blackPlayer);

    /**
     * Board destructor.
     */
    ~Board();


    /**
     * function that initialize the board to the beginning state.
     */
    void initializeBoard();


    /**
     * A function that initialize the 64 blocks of the chess board.
     */
    void initializeBlocks();


    /**
     * function that checks if a certain blck is occupied.
     * @return 0 if it is a free block, WHITE if there is a white piece there, BLACK othrwise.
     */
    int isOccupied(int row, int column);


    /**
     * a block getter.
     */
    Block getblock(int row, int column);


    /**
     * A function that print the whole board.
     */
    void printBoard();


    /**
     * prints board frame
     */
    void printFrame(int i, int j);


    /**
     * a Board getter.
     */
    Block **blockTable();

    /**
     * Checks if a given block is threatened
     */
    bool isBlockThreatened(Player *otherPlayer, Board *board, int row, int cul);


    /**
     * finds a colored piece type on the board
     */
    Block findType(int color, string type);

    /**
     * answers if a given piece is secured by a different piece from the same color.
     */
    bool isPieceSecured(Player *otherPlayer, Board *board, int row, int cul);
};


#endif //EX2NEW_BOARD_H
