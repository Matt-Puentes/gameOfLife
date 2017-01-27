//Matthew Puentes, January 24th

#include"Life.h"

char** initArray(unsigned int x, unsigned int y, char **arrayToInit){
	arrayToInit = malloc(x * sizeof(char*));
	int i;
	for(i = 0; i < x; i++){
		arrayToInit[i] = malloc(y * sizeof(char));
	}
	return arrayToInit;
}

void fillArray(unsigned int x, unsigned int y, char** arrayToFill, char z){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			arrayToFill[i][j] = z;
		}
	}
}

void fillArrayFromFile(unsigned int x, unsigned int y, char *fileName[], char** arrayToFill){
	FILE *input = fopen(fileName, "r");
	int lengthCounter = 0;
	int maxLengthCounter = 0;
	int heightCounter = 0;
	int readingFile = 1;
	while(readingFile){
		int recivedChar = getc(input);
		if(recivedChar == '\n'){
			heightCounter = heightCounter+1;
			if(lengthCounter > maxLengthCounter)
				maxLengthCounter = lengthCounter;
			lengthCounter = 0;
		}
		else if(recivedChar < 0){
			heightCounter = heightCounter+1;
			readingFile = 0;
		}
		else
			lengthCounter = lengthCounter+1;

	}
	fclose(input);

	FILE *input2 = fopen(fileName, "r");
	int xOffset = (x-maxLengthCounter)/2;
	int yOffset = (y-heightCounter)/2;

	int j = yOffset;
	for(int i = xOffset; i <= lengthCounter; i++){
		char q = getc(input2);
		if(q<0){
			break;
		}
		else if(q=='\n'){
			j=j+1;
			i=xOffset-1;
		}
		else{
			arrayToFill[i][j] = q;
			printf("char: %c",q);
		}
	}
	printf("Length: %d, Height: %d, xOff: %d, yOff %d\n", lengthCounter, heightCounter, xOffset, yOffset);
	printf("\n");
	fclose(input2);
}

int main(int argc, char *argv[]){
	/*
	if(argc<5){
		printf("please input at least 5 arguments");
		return 0;
	}*/
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int gens = atoi(argv[3]);
	char** mainArray1;
	char** mainArray2;
	char** mainArray3;

	mainArray1 = initArray(x, y, mainArray1);
	mainArray2 = initArray(x, y, mainArray2);
	mainArray3 = initArray(x, y, mainArray3);
	fillArray(x, y, mainArray1, '0');
	fillArray(x, y, mainArray2, 'b');
	fillArray(x, y, mainArray3, 'c');

	fillArrayFromFile(x, y, argv[4], mainArray1);

	printf("board 1 \n");
	printBoard(x,y,mainArray1);
	printf("\n");
	printf("board 2 \n");
	printBoard(x,y,mainArray2);
	printf("\n");
	printf("board 3 \n");
	printBoard(x,y,mainArray3);
	printf("\n");

	//Alright time
}
