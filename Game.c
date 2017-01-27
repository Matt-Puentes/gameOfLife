#include"Life.h"
void gameLoop(unsigned int x,unsigned int y, char** board1, char** historyBoard1, char** historyBoard2){
	backupBoard(x, y, board1, historyBoard1, historyBoard2);
	updateBoard(x, y, board1);
	checkForRepeats();
}

void backupBoard(unsigned int x, unsigned int y, char** board1, char** historyBoard1, char** historyBoard2){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			historyBoard2[i][j] = historyBoard1[i][j];
			historyBoard1[i][j] = board1[i][j];
		}
	}
}

void updateBoard(unsigned int x,unsigned int y, char** board){
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){ //these two go through the array
			int counter = 0;//counting EMPTY cells around the main cell
			for(int a = 1; a >= -1; a--){
				for(int b = 1; b >= -1; b--){//these two go around the point
					if(!(a==0&&b==0)){
						if(i+a>=x||i+a<0||j+b>=y||j+b<0){
							counter++
						}
						if(board[i+a][j+b]!='X'){
							counter++;
						}
					}
				}
			}
			if(board[i][j]==0){
				if(counter==5){
					board[i][j]='x';
				}
			}
			else{
				if(!(counter==6||counter==5)){
					board[i][j]='o';
				}
			}
		}
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(board[i][j]=='x'){
				board[i][j]
			}
		}
	}
}
