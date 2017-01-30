//Matthew Puentes, Jan 30
#include"Life.h"
#include<unistd.h>

int getNeighbors(unsigned int x, unsigned int y, unsigned int i, unsigned int j,
		char** board) {
	int counter = 0;
	for (int a = 1; a >= -1; a--) {//These two loops are used to go "around" a point in a 2D array. a and b both iterate from 1 to -1, going
		for (int b = 1; b >= -1; b--) {//down by one each loop. The loop terminates when both variables get to -1.
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
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
		for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
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
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
		for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
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
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
		for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
			historyBoard2[i][j] = historyBoard1[i][j];
			historyBoard1[i][j] = board[i][j];
		}
	}
}

void checkRepeats(unsigned int x, unsigned int y, int print, char** board1,
		char** historyBoard1, char** historyBoard2) {
	int singleFrameRepeat = 1;
	int doubleFrameRepeat = 1;
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
		for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
			if (board1[i][j] != historyBoard1[i][j]) {
				singleFrameRepeat = 0;
			}
			if (board1[i][j] != historyBoard2[i][j]) {
				doubleFrameRepeat = 0;
			}
		}
	}
	if (singleFrameRepeat) {
		if (print)
			printf("Terminated due to a repeat from last generation!\n");
		exit(0);
	}
	if (doubleFrameRepeat) {
		if (print)
			printf("Terminated due to a repeat from two generations ago!\n");
		exit(0);
	}
}

void checkDead(unsigned int x, unsigned int y, int print, char** board1) {
	for (int i = 0; i < x; i++) { //these two for loops increment by one each time. i goes through the columns in the array and j goes through
		for (int j = 0; j < y; j++) { //the rows. they iterate until they reach the number of rows/columns respectively.
			if (board1[i][j] != 'o') {

			}
		}
	}
}

void gameLoop(unsigned int x, unsigned int y, unsigned int gens, int print,
		int pause, char** board1, char** historyBoard1, char** historyBoard2) {
	if (print) {
		printf("\ngen 0\n");
		printBoard(x, y, board1);
		if (pause)
			printf("\033[%dA", (y + 3));
		else
			printf("\033[%dA", (y + 2));
	}
	if (print) {
		if (pause) {
			getchar();
		} else {
			usleep(500000);
		}
	}
	backupBoard(x, y, board1, historyBoard1, historyBoard2);
	for (int i = 0; i < gens; i++) { //this loop iterates i to the number of generations it is supposed to run. i increments at the end of the loop.

		updateBoard(x, y, board1);

		if (print) {
			printf("\ngen %d\n", i + 1);
			printBoard(x, y, board1);
		}

		checkRepeats(x, y, print, board1, historyBoard1, historyBoard2);

		checkDead(x, y, print, board1);

		backupBoard(x, y, board1, historyBoard1, historyBoard2);

		if (print) {
			if (i < gens-1) {
				if (pause)
					printf("\033[%dA", (y + 3));
				else
					printf("\033[%dA", (y + 2));
			}
		}
		if (print) {
			if (pause) {
				getchar();
			} else {
				usleep(500000);
			}
		}
	}
	printf("Terminated due to all generations being run\n");

}
