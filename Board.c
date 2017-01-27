#include"Life.h"

void printBoard(unsigned int x, unsigned int y, char* arrayToPrint[]){
	for(int j = 0; j < y; j++){
		for(int i = 0; i < x; i++){
			printf("%c ", arrayToPrint[i][j]);
		}
		printf("\n");
	}
}

