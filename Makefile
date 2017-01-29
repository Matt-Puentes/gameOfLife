CFLAGS = -g -Wall

Life: Life.c Board.c Game.c
	gcc $(CFLAGS) Life.c Board.c Game.c -o Life
	
clean:
	rm -f Life
	
all: Life