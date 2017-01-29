#include"Life.h"
#include<unistd.h>

int getNeighbors(unsigned int x, unsigned int y, unsigned int i, unsigned int j,
		char** board) {
	int counter = 0;
	for (int a = 1; a >= -1; a--) {
		for (int b = 1; b >= -1; b--) { //these two go around the point
			if (!(a == 0 && b == 0)) {
				if (!(i + a >= x || i + a < 0 || j + b >= y || j + b < 0)) {
					if (board[i + a][j + b] == 'x'
							|| board[i + a][j + b] == 'X') {
						counter++;
					}
				}
			}
		}
	}
	return counter;
}

void updateBoard(unsigned int x, unsigned int y, char** board) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) { //these two go through the array
			//printf("array step %d %d \n",i,j);
			int counter = getNeighbors(x, y, i, j, board); //counting EMPTY cells around the main cell
			if (board[i][j] == 'x' || board[i][j] == 'X') {
				if (counter < 2 || counter > 3) {
					board[i][j] = 'X';
				}
			} else {
				if (counter == 3) {
					board[i][j] = 'O';
				}
			}
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (board[i][j] == 'O') {
				board[i][j] = 'x';
			}
			if (board[i][j] == 'X') {
				board[i][j] = 'o';
			}
		}
	}
}

void backupBoard(unsigned int x, unsigned int y, char** board,
		char** historyBoard1, char** historyBoard2) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			historyBoard2[i][j] = historyBoard1[i][j];
			historyBoard1[i][j] = board[i][j];
		}
	}
}

void checkRepeats(unsigned int x, unsigned int y, int print, char** board1,
		char** historyBoard1, char** historyBoard2) {
	int singleFrameRepeat = 1;
	int doubleFrameRepeat = 1;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (board1[i][j] != historyBoard1[i][j]) {
				singleFrameRepeat = 0;
			}
			if (board1[i][j] != historyBoard2[i][j]) {
				doubleFrameRepeat = 0;
			}
		}
	}
	if (singleFrameRepeat) {
		if(print)
			printf("Repeat from last generation!\n");
		exit(0);
	}
	if (doubleFrameRepeat) {
		if(print)
			printf("Repeat from two generations ago!\n");
		exit(0);
	}
}

void gameLoop(unsigned int x, unsigned int y, unsigned int gens, int print,
		int pause, char** board1, char** historyBoard1, char** historyBoard2) {
	for (int i = 0; i <= gens; i++) {
		if(print){
			printf("\ngen %d\n", i);
			printBoard(x, y, board1);
		}

		updateBoard(x, y, board1);

		checkRepeats(x, y, print, board1, historyBoard1, historyBoard2);

		backupBoard(x, y, board1, historyBoard1, historyBoard2);

		if(print){
			if (i < gens){
				if(pause)
					printf("\033[%dA", (y + 3));
				else
					printf("\033[%dA", (y + 2));
			}
		}
		if(print){
			if(pause){
				getchar();
			}
			else{
				usleep(500000);
			}
		}
	}

}
