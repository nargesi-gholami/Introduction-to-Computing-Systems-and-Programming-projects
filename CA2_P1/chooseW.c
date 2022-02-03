#include <stdio.h> 

#define white 1
#define black -1
#define true 5
#define size 8
#define valid 2


void chooseW(int play[8][8]) {
	int row, col;
	while (true) {
		printf("white's turn\n please enter a number between 1 to 8 for column\n and a number between 1 to 8 for row \n like this :2 4\n");
		scanf_s("%d %d", &row, &col);
		row = --row;
		col = --col;
		if ((col < 9 && col>=0) && (row < 9 && row>=0)) {
			if ((play[row][col] == 0)) {
				if ( allowed(white, play,row,col)== valid) {
					play[row][col] = white;
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

