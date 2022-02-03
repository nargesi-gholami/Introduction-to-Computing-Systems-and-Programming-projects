#include <stdio.h>

#define black -1
#define white  1
#define empty  0
#define size   8
#define end 0


int count(int turn, int play[8][8], int EndGame) {

	int black_num = empty;
	int white_num = empty;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 8; j++) {
			if (play[i][j] == black)
			black_num++;
			if (play[i][j] == white)
			white_num++;
		}
	}
	printf("\n black's score is %d\n", black_num);
	printf("white's score is %d\n", white_num);
	if ((turn == 63) || (EndGame == end))
	{
		if (black_num > white_num)
			printf("\n Congratulations,Black has won the game");
		else if (black_num < white_num)
			printf("\n Congratulations,White has won the game");
		else if (black_num = white_num)
			printf("\n Oh!,No one has won the game");

	}

	return end;
}