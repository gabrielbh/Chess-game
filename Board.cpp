#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

#define ROW_FACTOR 11

/**
 * Board constructor.
 */
Board::Board(Player *whitePlayer, Player *blackPlayer)
{
    _whitePlayer = whitePlayer;
    _blackPlayer = blackPlayer;
    initializeBlocks();
    initializeBoard();
}


/**
 * function that initialize the board to the beginning state.
 */
void Board::initializeBoard()
{

    for (int col = 0; col < 8; col++)
    {
        _blocks[1][col].setPiece(new Pawn(PAWN, WHITE)); // Black Pawns
        _blocks[6][col].setPiece(new Pawn(PAWN, BLACK)); // White pawns
    }

    _blocks[0][0].setPiece(new Rook(ROOK, WHITE));
    _blocks[0][1].setPiece(new Knight(KNIGHT, WHITE));
    _blocks[0][2].setPiece(new Bishop(BISHOP, WHITE));
    _blocks[0][3].setPiece(new Queen(QUEEN, WHITE));
    _blocks[0][4].setPiece(new King(KING, WHITE));
    _blocks[0][5].setPiece(new Bishop(BISHOP, WHITE));
    _blocks[0][6].setPiece(new Knight(KNIGHT, WHITE));
    _blocks[0][7].setPiece(new Rook(ROOK, WHITE));

    _blocks[7][0].setPiece(new Rook(ROOK, BLACK));
    _blocks[7][1].setPiece(new Knight(KNIGHT, BLACK));
    _blocks[7][2].setPiece(new Bishop(BISHOP, BLACK));
    _blocks[7][3].setPiece(new Queen(QUEEN, BLACK));
    _blocks[7][4].setPiece(new King(KING, BLACK));
    _blocks[7][5].setPiece(new Bishop(BISHOP, BLACK));
    _blocks[7][6].setPiece(new Knight(KNIGHT, BLACK));
    _blocks[7][7].setPiece(new Rook(ROOK, BLACK));
}


/**
 * A function that print the whole board.
 */
void Board::printBoard()
{
    for (int i = 0; i < 12; ++i)
    {
        cout << "\n";
        for (int j = 0; j < 12; ++j)
        {

            if ((i > 1) && (i < 10) && (j > 1) && (j < 10))
            {
                _blocks[ROW_FACTOR - i - DIFF][j - DIFF].printBlock();
            }
            else
            {
                printFrame(i, j);
            }
        }
    }
}


/**
 * A function that initialize the 64 blocks of the chess board.
 */
void Board::initializeBlocks()
{
    _blocks = new Block *[8];
    for (int col = 0; col < 8; col++)
    {
        _blocks[col] = new Block[8];
    }

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((row + col) % 2)
            {
                _blocks[row][col] = Block(BLUE, row, col);
            }
            else
            {
                _blocks[row][col] = Block(GREEN, row, col);
            }
        }
    }
}


/**
 * function that checks if a certain block is occupied.
 * @return 0 if it is a free block, WHITE if there is a white piece there, BLACK othrwise.
 */
int Board::isOccupied(int row, int column)
{
    Piece *piece = _blocks[row][column].getPiece();
    if (piece == nullptr)
    {
        return 0;
    }
    return piece->getColor();
}


/**
 * a block getter.
 */
Block Board::getblock(int row, int column)
{
    return _blocks[row][column];
}


/**
 * a Board getter.
 */
Block **Board::blockTable()
{
    return _blocks;
}


/**
 * Checks if a given block is threatened
 */
bool Board::isBlockThreatened(Player *otherPlayer, Board *board, int row, int cul)
{
    for (int boardRow = 0; boardRow < 8; ++boardRow)
    {
        for (int boardCul = 0; boardCul < 8; ++boardCul)
        {
            if (blockTable()[boardRow][boardCul].getPiece()
                && blockTable()[boardRow][boardCul].getPiece()->getColor() == otherPlayer->getColor())
            {
                if (blockTable()[boardRow][boardCul].getPiece()
                    && blockTable()[boardRow][boardCul].getPiece()->isValidMove
                    (boardRow, boardCul, row, cul, board, otherPlayer))
                {
                    return true;
                }
            }
        }
    }
    return false;
}


/**
 * finds a colored piece type on the board
 */
Block Board::findType(int color, string type)
{
    Block block;
    for (int boardRow = 0; boardRow < 8; ++boardRow)
    {
        for (int boardCul = 0; boardCul < 8; ++boardCul)
        {
            if (blockTable()[boardRow][boardCul].getPiece()
                && blockTable()[boardRow][boardCul].getPiece()->getColor() == color
                && blockTable()[boardRow][boardCul].getPiece()->getType() == type)
            {
                block = blockTable()[boardRow][boardCul];
                return block;
            }
        }
    }
    return block;
}


/**
 * answers if a given piece is secured by a different piece from the same color.
 */
bool Board::isPieceSecured(Player *otherPlayer, Board *board, int row, int cul)
{
    for (int boardRow = 0; boardRow < 8; ++boardRow)
    {
        for (int boardCul = 0; boardCul < 8; ++boardCul)
        {
            if (blockTable()[boardRow][boardCul].getPiece()
                && blockTable()[boardRow][boardCul].getPiece()->getColor() == otherPlayer->getColor())
            {
                blockTable()[boardRow][boardCul].getPiece()->setProtectingMode(true);
                if (blockTable()[boardRow][boardCul].getPiece()
                    && blockTable()[boardRow][boardCul].getPiece()->isValidMove
                    (boardRow, boardCul, row, cul, board, otherPlayer))
                {
                    blockTable()[boardRow][boardCul].getPiece()->setProtectingMode(false);
                    return true;
                }
                blockTable()[boardRow][boardCul].getPiece()->setProtectingMode(false);
            }
        }
    }
    return false;
}


/**
 * Board destructor.
 */
Board::~Board()
{
    for (int row = 0; row < 8; ++row)
    {
        for (int cul = 0; cul < 8; ++cul)
        {
            if (_blocks[row][cul].getPiece() != nullptr)
            {
                delete (_blocks[row][cul].getPiece());
            }
            delete (&_blocks[row][cul]);
        }
    }
}


/**
 * prints board frame
 */
void Board::printFrame(int i, int j)
{
    if (i == 0 || i == 11)
    {
        if (j < 2 || j > 9)
        {
            cout << " ";
        }
        else if (j > 1 && j < 10)
        {
            //PRINT LETTERS
            if (j == 2)
            {
                cout << "A";
            }
            else if (j == 3)
            {
                cout << "B";
            }
            else if (j == 4)
            {
                cout << "C";
            }
            else if (j == 5)
            {
                cout << "D";
            }
            else if (j == 6)
            {
                cout << "E";
            }
            else if (j == 7)
            {
                cout << "F";
            }
            else if (j == 8)
            {
                cout << "G";
            }
            else if (j == 9)
            {
                cout << "H";
            }
        }
    }
    else if (i == 1 || i == 10 || j == 1 || j == 10)
    {
        cout << " ";
    }
    else if (j == 0 || j == 11)
    {
        // print numbers

        if (i == 2)
        {
            cout << "8";
        }
        else if (i == 3)
        {
            cout << "7";
        }
        else if (i == 4)
        {
            cout << "6";
        }
        else if (i == 5)
        {
            cout << "5";
        }
        else if (i == 6)
        {
            cout << "4";
        }
        else if (i == 7)
        {
            cout << "3";
        }
        else if (i == 8)
        {
            cout << "2";
        }
        else if (i == 9)
        {
            cout << "1";
        }
    }
}
