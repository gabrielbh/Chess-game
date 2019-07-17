
CC= g++
CFLAGS=   -Wvla -c -std=c++17 -Wextra -g -Wall
all: chess

tar:
	tar -cvf ex2.tar Bishop.cpp Bishop.h Block.cpp Block.h Board.cpp Board.h chess.cpp \
	Game.cpp Game.h King.cpp King.h Knight.cpp Knight.h Makefile Pawn.cpp Pawn.h Piece.cpp \
	Piece.h Player.cpp Player.h Queen.cpp Queen.h README Rook.cpp Rook.h

#Executeable

chess: chess.o King.o Rook.o Game.o Queen.o Pawn.o Knight.o Board.o Block.o Piece.o Bishop.o Player.o
	$(CC) chess.o King.o Rook.o Game.o Queen.o Pawn.o Knight.o Board.o Block.o Piece.o Bishop.o Player.o -o chess


#Obj File

chess.o: chess.cpp Game.h Player.h Board.h Block.h Piece.h
	$(CC) $(CFLAGS) chess.cpp -o chess.o

Rook.o: Rook.cpp Rook.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) Rook.cpp -o Rook.o


Queen.o: Queen.cpp Queen.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) Queen.cpp -o Queen.o


Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp -o Player.o


Piece.o: Piece.cpp Piece.h Board.h Block.h Player.h Pawn.h Bishop.h \
 Rook.h Knight.h Queen.h King.h
	$(CC) $(CFLAGS) Piece.cpp -o Piece.o


Pawn.o: Pawn.cpp Pawn.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) Pawn.cpp -o Pawn.o


Knight.o: Knight.cpp Knight.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) Knight.cpp -o Knight.o




King.o: King.cpp King.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) King.cpp -o King.o


Game.o: Game.cpp Game.h Player.h Board.h Block.h Piece.h
	$(CC) $(CFLAGS) Game.cpp -o Game.o



Board.o: Board.cpp Board.h Block.h Piece.h Player.h Pawn.h King.h Queen.h \
 Rook.h Knight.h Bishop.h
	$(CC) $(CFLAGS) Board.cpp -o Board.o



Block.o: Block.cpp Block.h Piece.h Board.h Player.h
	$(CC) $(CFLAGS) Block.cpp -o Block.o



Bishop.o: Bishop.cpp Bishop.h Piece.h Board.h Block.h Player.h
	$(CC) $(CFLAGS) Bishop.cpp -o Bishop.o

#Targets

clean:
	$(RM) -f *.o
	$(RM) chess


.PHONY: clean

