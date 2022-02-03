#include <stdio.h> 

#define black -1
#define white 1
#define true 5
#define size 8
#define valid 2
#define max 9
#define min 0

void chooseB(int play[8][8]) {
	int row, col;
	while (true) {
		printf("black's turn\nplease enter a number between 1 to 8 for column\n and a number between 1 to 8 for row \n like this :2 4\n");
		scanf_s("%d %d", &row, &col);
		row = --row;
		col = --col;
		if ((col < max && col>= min) && (row < max && row >= min ) ) {
		if(play[row][col] == 0) {
			if (allowed(0 , play,row,col) == valid) {
				play[row][col] = black;
				break;
			}
			}
		}
		else {
			printf("please enter another number for cloumn and row\n");
			row = 0; col = 0;
			continue;
		}
	}
	}

