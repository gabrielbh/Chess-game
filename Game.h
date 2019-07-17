#ifndef EX2NEW_GAME_H
#define EX2NEW_GAME_H

#include "Player.h"
#include "Board.h"
#include "Piece.h"

/**
 * A class that runs a game
 */
class Game
{
public:

    /**
     * distructore
     */
    ~Game();

    /**
     * board destructor. deletes all the pieces on the table and the blocks
     */
    void boardDestructor(Board *board);

    /**
     * function that runs a game.
     * @return 0 if everything went well, NOT 0 otherwise.
     */
    int runGame();

    /**
     * runs a single turn.
     * @return 0 if everything went well, NOT 0 otherwise.
     */
    int runTurn(Board *board, Player *player, Player *otherPlayer);


    /**
     * action for valid input.
     */
    int movePiece(Board *board, Player *player, Player *otherPlayer, int srcRow, int srcCul, int destRow, int destCul);


    /**
     * checks if the input is legal.
     * @return true if legal, false otherwise.
     */
    int isLegalInput(string basic_string, Board *board, Player *player, Player *otherPlayer);


    /**
     * function that does the casting.
     */
    void cast(int legalInput, Board *board);


    /**
     * checks if it is checkmate
     */
    bool isCheckmate(Player *player, Player *otherPlayer, Board *board, int kingsRow, int kingsCul);


private:
    Player * _whitePlayer;
    Player * _blackPlayer;
    Board* _board;
};


#endif //EX2NEW_GAME_H
