#CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tictactoe

tictactoe: tic-tac-toe.c tic-tac-toe.h
	$(CC) $(CFLAGS) tic-tac-toe.c -o tictactoe

clean:
	rm -f tictactoe