#include "Game.h"

// difference between int and letter in ascii table.
int ASCII_TABLE_LETTER_DIFF = 64;
// difference between int and letter in ascii table.
int ASCII_TABLE_INT_DIFF = 48;

#define NOT_VALID 2
#define CHECK_MATE 1


/**
 * function that runs a game.
 * @return 0 if everything went well, NOT 0 otherwise.
 */
int Game::runGame()
{

    string whiteName;
    string blackName;
    cout << "Enter white curPlayer name:\n";
    cin >> whiteName;
    cout << "Enter black curPlayer name:\n";
    cin >> blackName;

    Player *_whitePlayer = new Player(WHITE, whiteName);
    Player *_blackPlayer = new Player(BLACK, blackName);
    Board *_board = new Board(_whitePlayer, _blackPlayer);
    Player *curPlayer = _whitePlayer;
    Player *otherPlayer = _blackPlayer;
    int checkMate = 0;
    while (!checkMate)
    {
        int output = runTurn(_board, curPlayer, otherPlayer);
        if (output == 1)
        {
            checkMate = true;
        }
        Player *standPlayer = curPlayer;
        curPlayer = otherPlayer;
        otherPlayer = standPlayer;
    }
    _board->printBoard();
    cout << otherPlayer->getName() << " won!\n";

    boardDestructor(_board);

    return 0;
}


/**
 * runs a single turn.
 * @return 0 if everything went well, NOT 0 otherwise.
 */
int Game::runTurn(Board *board, Player *player, Player *otherPlayer)
{
    string move;
    board->printBoard();
    if (player->checkGetter())
    {
        cout << player->getName() << "\33[37;41mCheck!\n\33[0m";
    }
    bool validMove = false;
    while (!validMove)
    {
        cout << player->getName() << ": Please enter your movePiece:\n";
        cin >> move;
        int legalInput = isLegalInput(move, board, player, otherPlayer);
        if (!legalInput)
        {
            validMove = false;
        }
        else if (legalInput != 1)
        {
            cast(legalInput, board);
            return 0;
        }

        else
        {
            int srcCul = move[0] - ASCII_TABLE_LETTER_DIFF - 1;
            int srcRow = move[1] - ASCII_TABLE_INT_DIFF - 1;
            int destCul = move[2] - ASCII_TABLE_LETTER_DIFF - 1;
            int destRow = move[3] - ASCII_TABLE_INT_DIFF - 1;
            if (!board->getblock(srcRow, srcCul).getPiece())
            {
                cout << "\33[37;41millegal movePiece\33[0m" << endl;
                validMove = false;
            }
            else
            {
                int moveOutcome = movePiece(board, player, otherPlayer, srcRow, srcCul, destRow, destCul);
                if (moveOutcome == 0)
                {
                    return 0;
                }
                else if (moveOutcome == 1)
                {
                    return 1;
                }
                else
                {
                    validMove = false;
                }
            }
        }
    }
    return 0;
}


/**
 * checks if the input is legal.
 * @return true if legal, false otherwise.
 */
int Game::isLegalInput(string move, Board *board, Player *player, Player *otherPlayer)
{
    // castle options:
    if (move == "o-o-o")
    {

        if (board->getblock(0, 0).getPiece()->canCastleGetter()
            && board->getblock(0, 4).getPiece()->canCastleGetter() &&
            board->getblock(0, 0).getPiece()->isValidMove(0, 0, 0, 3, board, player) &&
            player->getColor() == WHITE)
        {
            for (int blockCul = 2; blockCul < 5; ++blockCul)
            {
                if (board->isBlockThreatened(otherPlayer, board, 0, blockCul))
                {
                    return false;
                }
            }
            return 31;
        }

        else if (board->getblock(7, 0).getPiece()->canCastleGetter()
                 && board->getblock(7, 4).getPiece()->canCastleGetter() &&
                 board->getblock(7, 0).getPiece()->isValidMove(7, 0, 7, 3, board, player)
                 && player->getColor() == BLACK)
        {
            for (int blockCul = 2; blockCul < 5; ++blockCul)
            {
                if (board->isBlockThreatened(otherPlayer, board, 7, blockCul))
                {
                    return false;
                }
            }
            return 32;
        }

        return false;
    }
    else if (move == "o-o")
    {
        if (board->getblock(0, 7).getPiece()->canCastleGetter()
            && board->getblock(0, 4).getPiece()->canCastleGetter()
            && board->getblock(0, 7).getPiece()->isValidMove(0, 7, 0, 5, board, player)
            && player->getColor() == WHITE)
        {
            for (int blockCul = 6; blockCul > 3; --blockCul)
            {
                if (board->isBlockThreatened(otherPlayer, board, 0, blockCul))
                {
                    return false;
                }
                return 21;
            }
        }

        if (board->getblock(7, 7).getPiece()->canCastleGetter()
            && board->getblock(7, 4).getPiece()->canCastleGetter() &&
            board->getblock(7, 7).getPiece()->isValidMove(7, 7, 7, 5, board, player)
            && player->getColor() == BLACK)
        {
            for (int blockCul = 6; blockCul > 3; --blockCul)
            {
                if (board->isBlockThreatened(otherPlayer, board, 7, blockCul))
                {
                    return false;
                }
            }
            return 22;
        }

        return false;
    }

    else if (move.length() != 4
             || move[0] > 72 || move[0] < 65 || move[2] > 72 || move[2] < 65
             || move[1] > 56 || move[1] < 49 || move[3] > 56 || move[3] < 49)
    {
        return false;
    }

    return 1;
}


/**
 * function that does the casting.
 */
void Game::cast(int legalInput, Board *board)
{
    // white player long casting.
    if (legalInput == 31)
    {
        // set Rook:
        board->blockTable()[0][3].setPiece
                (Piece(board->getblock(0, 0).getPiece()->getType(), WHITE)
                         .getNewPiece(ROOK));
        delete (board->blockTable()[0][0].getPiece());
        board->blockTable()[0][0].setPiece(nullptr);

        // set King
        board->blockTable()[0][2].setPiece
                (Piece(board->getblock(0, 4).getPiece()->getType(), WHITE)
                         .getNewPiece(KING));
        delete (board->blockTable()[0][4].getPiece());
        board->blockTable()[0][4].setPiece(nullptr);
        board->getblock(0, 2).getPiece()->canCastleSetter();


    }

        // black player long casting.
    else if (legalInput == 32)
    {
        // set Rook:
        board->blockTable()[7][3].setPiece
                (Piece(board->getblock(7, 0).getPiece()->getType(), BLACK)
                         .getNewPiece(ROOK));
        delete (board->blockTable()[7][0].getPiece());
        board->blockTable()[7][0].setPiece(nullptr);

        // set King
        board->blockTable()[7][2].setPiece
                (Piece(board->getblock(7, 4).getPiece()->getType(), BLACK)
                         .getNewPiece(KING));
        delete (board->blockTable()[7][4].getPiece());
        board->blockTable()[7][4].setPiece(nullptr);
        board->getblock(7, 2).getPiece()->canCastleSetter();

    }

        // white player short casting.
    else if (legalInput == 21)
    {
        // set Rook:
        board->blockTable()[0][5].setPiece
                (Piece(board->getblock(0, 7).getPiece()->getType(), WHITE)
                         .getNewPiece(ROOK));
        delete (board->blockTable()[0][7].getPiece());
        board->blockTable()[0][7].setPiece(nullptr);

        // set King
        board->blockTable()[0][6].setPiece
                (Piece(board->getblock(0, 4).getPiece()->getType(), WHITE)
                         .getNewPiece(KING));
        delete (board->blockTable()[0][4].getPiece());
        board->blockTable()[0][4].setPiece(nullptr);
        board->getblock(0, 6).getPiece()->canCastleSetter();

    }
        // black player short casting.
    else
    {
        // set Rook:
        board->blockTable()[7][5].setPiece
                (Piece(board->getblock(7, 7).getPiece()->getType(), BLACK)
                         .getNewPiece(ROOK));
        delete (board->blockTable()[7][7].getPiece());
        board->blockTable()[7][7].setPiece(nullptr);

        // set King
        board->blockTable()[7][6].setPiece
                (Piece(board->getblock(7, 4).getPiece()->getType(), BLACK)
                         .getNewPiece(KING));
        delete (board->blockTable()[7][4].getPiece());
        board->blockTable()[7][4].setPiece(nullptr);
        board->getblock(7, 6).getPiece()->canCastleSetter();

    }
}


/**
 * checks if it is checkmate
 */
bool Game::isCheckmate(Player *player, Player *otherPlayer, Board *board, int kingsRow, int kingsCul)
{
    for (int rowDiff = -1; rowDiff < 2; ++rowDiff)
    {
        for (int culDiff = -1; culDiff < 2; ++culDiff)
        {
            if ((kingsRow + rowDiff >= 0) && (kingsRow + rowDiff < 8) && (kingsCul + culDiff >= 0) &&
                (kingsCul + culDiff < 8))
            {
                if (board->getblock(kingsRow, kingsCul).getPiece()
                    && board->getblock(kingsRow, kingsCul).getPiece()->isValidMove
                    (kingsRow, kingsCul, kingsRow + rowDiff, kingsCul + culDiff, board, otherPlayer)
                    && (!board->isBlockThreatened(player, board, kingsRow + rowDiff, kingsCul + culDiff))
                    && (!board->isPieceSecured(player, board, kingsRow + rowDiff, kingsCul + culDiff)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}


/**
 * board destructor. deletes all the pieces on the table and the blocks
 */
void Game::boardDestructor(Board *board)
{
    for (int row = 0; row < 8; ++row)
    {
        for (int cul = 0; cul < 8; ++cul)
        {
            if (board->blockTable()[row][cul].getPiece() != nullptr)
            {
                delete (board->blockTable()[row][cul].getPiece());
            }
            delete (&board->blockTable()[row][cul]);
        }
    }
}

/**
 * destructor.
 */
Game::~Game()
{
    delete (_whitePlayer);
    delete (_blackPlayer);
    delete (_board);
}


/**
 * action for valid input.
 */
int Game::movePiece(Board *board, Player *player, Player *otherPlayer, int srcRow, int srcCul, int destRow, int destCul)
{
    bool moveValidation = board->getblock(srcRow, srcCul).getPiece()->isValidMove
            (srcRow, srcCul, destRow, destCul, board, player);
    if (moveValidation)
    {
        if (board->blockTable()[destRow][destCul].getPiece() != nullptr)
        {
            delete (board->blockTable()[destRow][destCul].getPiece());
            board->blockTable()[destRow][destCul].setPiece(nullptr);
        }

        //turn pawn to queen:
        if (board->getblock(srcRow, srcCul).getPiece()->pawnToQueenGetter())
        {
            board->blockTable()[destRow][destCul].setPiece
                    (Piece(board->getblock(srcRow, srcCul).getPiece()->getType(), player->getColor())
                             .getNewPiece(QUEEN));
            delete (board->blockTable()[srcRow][srcCul].getPiece());
            board->blockTable()[srcRow][srcCul].setPiece(nullptr);
            return 0;
        }

        // set piece in place:
        board->blockTable()[destRow][destCul].setPiece
                (Piece(board->getblock(srcRow, srcCul).getPiece()->getType(), player->getColor())
                         .getNewPiece(board->getblock(srcRow, srcCul).getPiece()->getType()));
        delete (board->blockTable()[srcRow][srcCul].getPiece());
        board->blockTable()[srcRow][srcCul].setPiece(nullptr);

        //check for checks:
        Block myKingLocation = board->findType(player->getColor(), KING);
        bool isMyKingThreatened = board->isBlockThreatened
                (otherPlayer, board, myKingLocation.getRow(), myKingLocation.getColumn());
        if (!isMyKingThreatened)
        {
            player->checkSetter(false);
            Block otherPlayerKingLocation = board->findType(otherPlayer->getColor(), KING);
            bool hisKingThreatened = board->isBlockThreatened
                    (player, board, otherPlayerKingLocation.getRow(),
                     otherPlayerKingLocation.getColumn());
            if (hisKingThreatened)
            {
                otherPlayer->checkSetter(true);
                bool checkMate = isCheckmate(player, otherPlayer, board, otherPlayerKingLocation.getRow(),
                                             otherPlayerKingLocation.getColumn());
                if (checkMate)
                {
                    return CHECK_MATE;
                }
            }
            return 0;
        }
        else
        {
            board->blockTable()[srcRow][srcCul].setPiece
                    (Piece(board->getblock(destRow, destCul).getPiece()->getType(), player->getColor())
                             .getNewPiece(board->getblock(destRow, destCul).getPiece()->getType()));
            delete (board->blockTable()[destRow][destCul].getPiece());
            board->blockTable()[destRow][destCul].setPiece(nullptr);
            cout << "\33[37;41millegal movePiece\33[0m" << endl;
            return NOT_VALID;
        }
    }

    cout << "\33[37;41millegal movePiece\33[0m" << endl;
    return NOT_VALID;
}
