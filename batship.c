//Author: Adella Todd
//Program: Final Project - Half a battleship game
//Date: 07/26/24

#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
#define FILE_NAME "ships.txt"

void displayBoard(int rows, int cols, char board[][cols]);
void clearBoard(int rows, int cols, char board[][cols]);
void getMove(int rows, int cols, char board[][cols]);
int scoreCalc(int counter, int ships);
_Bool checkWin(int rows, int cols, char board[][cols]);
void loadShips(FILE* ships_fp, int rows, int cols, char board[][cols]);

int main(){
	char hit = 'X', miss = 'O';
	char board[MAX_ROWS][MAX_COLS];
	char cols, keepPlaying;
	int rows, ship, counter, colNumber;
	
	
	
	printf("*****LET'S PLAY BATSHIP*****\n");
	FILE* ships_fp;
	//while(keepPlaying != 0){
	//if(checkWin(MAX_ROWS, MAX_COLS, board) == 1){
	//	printf("You win!");
	//} 
	//else{
	while(keepPlaying != 'N'){
		
		while(checkWin(MAX_ROWS, MAX_COLS, board) == 0){
		
		displayBoard(MAX_ROWS, MAX_COLS, board);
		loadShips(ships_fp, MAX_ROWS, MAX_COLS, board);
		printf("\n          FIRE AWAY!\n(enter a spot in the grid like A1) ");
		
		scanf("%c%d", &cols, &rows);
		switch(cols){
			case 'A':
				colNumber = 1;
				break;
			case 'B':
				colNumber = 2;
				break;
			case 'C':
				colNumber = 3;
				break;
			case 'D':
				colNumber = 4;
				break;
			case 'E':
				colNumber = 5;
				break;
			case 'F':
				colNumber = 6;
				break;
			case 'G':
				colNumber = 7;
				break;
			case 'H':
				colNumber = 8;
				break;
			case 'I':
				colNumber = 9;
				break;
			case 'J':
				colNumber = 10;
				break;
		}
		
		
		getMove(rows, colNumber, board);
		
		
		counter++;
		printf("\n");
		}
		while(checkWin(MAX_ROWS, MAX_COLS, board) == 1){
			int score = 100 - (counter - 31);
			printf("You sunk all 31 ships! Your score is: %d\n", score);
			printf("Would you Like to play again? Y/N: ");
			scanf("%c", &keepPlaying);
			fclose(ships_fp);
		}
	}
	
//	}
//	}
	return 0;
}

//DONE
void displayBoard(int rows, int cols, char board[][cols]){
	
	int label = 1;
	printf("\n   A B C D E F G H I J\n");
	for(int rI = 0; rI < rows; rI++){
		if(label <= 9){
			printf("\n%d  ", label);
		}
		else{
			printf("\n%d ", label);
		}
		for(int cI = 0; cI < cols; cI++){
			printf(" ");
		}
		label++;
	}
	
}
//DONE??
void getMove(int rows, int cols, char board[][cols]){
	
	
	if(board[rows][cols] == 'S'){
		board[rows][cols] = 'X';
		printf("%c", board[rows][cols]);
	}
	else if(board[rows][cols] == ' '){
		board[rows][cols] = 'O';
		printf("%c", board[rows][cols]);
	}
}

//DONE
void clearBoard(int rows, int cols, char board[][cols]){
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			board[r][c] = ' ';
		}
	}
}
//MAYBE DONE
int scoreCalc(int counter, int ships){
	int score = 100 - (counter-ships);
	return score;
}
//MAYBE DONE
_Bool checkWin(int rows, int cols, char board[][cols]){
	int counter = 0;
	for(int rI = 0; rI < rows; rI++){
		for(int cI = 0; cI < cols; cI++){
			if(board[rI][cI] == 'S'){
				//counter++;
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}

void loadShips(FILE* ships_fp, int rows, int cols, char board[][cols]){
	ships_fp = fopen("ships.txt", "r");
	int size = rows*cols;
	if(ships_fp == NULL){
		printf("Failed to open file");
	}
	else{
		for(int rI = 0; rI < rows; rI++){
			for(int cI = 0; cI < cols; cI++){	
				while(fscanf(ships_fp, "%c", &board[rI][cI]) == 1){	
				

				}
			}			
		}
		//fclose(ships_fp);
	}
}
