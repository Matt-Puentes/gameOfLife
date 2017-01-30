//Matthew Puentes, Jan 30
#include"Life.h"
void printBoard(unsigned int x, unsigned int y, char* arrayToPrint[]){
	for (int j = 0; j < y; j++) { //these two for loops increment by one each time. j goes through the columns in the array and i goes through
		for (int i = 0; i < x; i++) { //the rows. they iterate until they reach the number of rows/columns respectively.
			if(arrayToPrint[i][j] == 'o')
				printf(" ");
			else
				printf("%c", arrayToPrint[i][j]);
		}
		printf("\n");
	}
}
