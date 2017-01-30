//Matthew Puentes, January 30
#include"Life.h"

char** initArray(unsigned int x, unsigned int y, char **arrayToInit) {
	int i;
	for (i = 0; i < x; i++) {
		arrayToInit[i] = malloc(y * sizeof(char));
	}
	return arrayToInit;
}

void fillArray(unsigned int x, unsigned int y, char** arrayToFill, char z) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arrayToFill[i][j] = z;
		}
	}
}

void fillArrayFromFile(unsigned int x, unsigned int y, char* fileName,
		char** arrayToFill) {
	FILE *input = fopen(fileName, "r");
	int lengthCounter = 0;
	int maxLengthCounter = 0;
	int heightCounter = 0;
	int readingFile = 1;
	char lastReadChar = 'a';
	char readChar = 'a';
	while (readingFile) {
		lastReadChar = readChar;
		readChar = getc(input);
		if (readChar != '\r') {
			if (readChar == '\n') {
				heightCounter = heightCounter + 1;
				if (lengthCounter > maxLengthCounter)
					maxLengthCounter = lengthCounter;
				lengthCounter = 0;

			} else if (readChar < 0) {
				if (lastReadChar != '\n')
					heightCounter = heightCounter + 1;
				readingFile = 0;
				if (lengthCounter > maxLengthCounter)
					maxLengthCounter = lengthCounter;

			} else
				lengthCounter = lengthCounter + 1;

		}

	}
	fclose(input);

	if(maxLengthCounter > x || heightCounter > y){
		printf("Your input file is too large for the specified dimensions.");
		exit(0);
	}

	FILE *input2 = fopen(fileName, "r");
	int xOffset = (x - maxLengthCounter) / 2;
	int yOffset = (y - heightCounter) / 2;

	int j = 0;
	int i = 0;
	lastReadChar = 'a';
	readChar = 'a';
	while (!(i > maxLengthCounter && j > heightCounter)) {
		lastReadChar = readChar;
		readChar = getc(input2);
		if (readChar != '\r') {
			if (readChar < 0) {
				if (lastReadChar == '\n')
					j--;
				break;
			} else if (readChar == '\n') {
				j = j + 1;
				i = 0 - 1;
			} else {
				arrayToFill[i + xOffset][j + yOffset] = readChar;
			}
			i++;
		}
	}
	fclose(input2);
}

int main(int argc, char *argv[]) {
	if (argc != 5 && argc != 7) {
		printf("Error: program expects 4 or 6 arguments\n");
		return 0;
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int gens = atoi(argv[3]);
	int print = 0;
	int pause = 0;
	if (argc == 7) {
		if (*argv[5] == 'y')
			print = 1;
		if (*argv[6] == 'y')
			pause = 1;
	}
	char** mainArray1 = malloc(x * sizeof(char*));
	char** mainArray2 = malloc(x * sizeof(char*));
	char** mainArray3 = malloc(x * sizeof(char*));

	mainArray1 = initArray(x, y, mainArray1);
	mainArray2 = initArray(x, y, mainArray2);
	mainArray3 = initArray(x, y, mainArray3);

	fillArray(x, y, mainArray1, 'o');
	fillArray(x, y, mainArray2, 'b');
	fillArray(x, y, mainArray3, 'c');

	fillArrayFromFile(x, y, argv[4], mainArray1);

	gameLoop(x, y, gens, print, pause, mainArray1, mainArray2, mainArray3);
}
