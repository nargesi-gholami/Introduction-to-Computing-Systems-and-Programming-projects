#include <stdio.h> 

#define black -1
#define white 1
#define empty 0
#define size 8



void printboard(int play[8][8]){
	char temp[8][8];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (play[i][j] == black)
				temp[i][j] = 'B';
			if (play[i][j] == white)
				temp[i][j] = 'W';
			if (play[i][j] == empty)
				temp[i][j] = ' ';
		}
	}
	

	printf("	  1     2     3     4     5     6     7     8   \n");
	printf("	 _____ _____ _____ _____ _____ _____ _____ _____ \n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  1	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[0][0], temp[0][1], temp[0][2], temp[0][3], temp[0][4], temp[0][5], temp[0][6], temp[0][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  2	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[1][0], temp[1][1], temp[1][2], temp[1][3], temp[1][4], temp[1][5], temp[1][6], temp[1][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  3	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[2][0], temp[2][1], temp[2][2], temp[2][3], temp[2][4], temp[2][5], temp[2][6], temp[2][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  4	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[3][0], temp[3][1], temp[3][2], temp[3][3], temp[3][4], temp[3][5], temp[3][6], temp[3][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  5	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[4][0], temp[4][1], temp[4][2], temp[4][3], temp[4][4], temp[4][5], temp[4][6], temp[4][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  6	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[5][0], temp[5][1], temp[5][2], temp[5][3], temp[5][4], temp[5][5], temp[5][6], temp[5][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  7	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[6][0], temp[6][1], temp[6][2], temp[6][3], temp[6][4], temp[6][5], temp[6][6], temp[6][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____|\n");
	printf("	|     |     |     |     |     |     |     |     |\n");
	printf("  8	|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", temp[7][0], temp[7][1], temp[7][2], temp[7][3], temp[7][4], temp[7][5], temp[7][6], temp[7][7]);
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____| \n");
}