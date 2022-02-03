#include <stdio.h>
#include <conio.h>

#include "function.h"
#include "graphics.h"

#define black -1
#define white 1
#define empty 0
#define true 5
#define size 8
#define FAIL 0
#define Start 1
#define BLACK 0

int main() {

	int play[size][size];
	int EndGame = Start;
	int turn;

	init_board(play);//Initialization board
	print_g(play);//draw graphic board

	for (turn = 0; turn < 60; turn++) {
		if (turn % 2 == BLACK)//even turn for black
		{
			printboard(play);
			if (EndGame == FAIL)
			break;//not valid to put any place
			choose(turn, play);
			printboard(play);
			EndGame = endgame(play, turn, EndGame);
			count(turn, play, EndGame);
		}
		else {
			printboard(play);
			if (EndGame ==FAIL)
			break;//not valid to put any place
			choose(turn, play);
			printboard(play);
			EndGame = endgame(play, turn, EndGame);
			count(turn, play, EndGame);
		}
	}
	count(turn, play, EndGame);
	_getch();
	return 0;
}