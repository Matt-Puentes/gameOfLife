#ifndef LIFE_H_
#define LIFE_H_

#include <stdio.h>
#include <stdlib.h>

//void printBoard(unsigned int x, unsigned int y, char* arrayToPrint[]);

void printBoard(unsigned int x, unsigned int y, char* arrayToPrint[]);

void gameLoop(unsigned int x, unsigned int y, unsigned int gens, int print,
		int pause, char** board1, char** historyBoard1, char** historyBoard2);

#endif/* LIFE_H_ */
