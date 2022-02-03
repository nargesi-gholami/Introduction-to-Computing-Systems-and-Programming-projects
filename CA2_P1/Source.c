#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "printboard.h"
#include "count.h"
#include "Allowed.h"
#include "chooseW.h"
#include "chooseB.h"

#define black -1
#define white 1
#define empty 0
#define true 5
#define size 8
#define fail 0
#define Start 1

int main() {

	int play[size][size] ;
	int turn;
	int EndGame = Start;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			play[i][j] = empty ;
		}//make empty
	}
	play[3][3] = white;
	play[3][4] = black;
	play[4][4] = white;
	play[4][3] = black;


	for (turn = 0; turn < 64; turn++) {
		if (turn % 2 == 0 )//even turn for black
		{
			printboard(play);
			if (EndGame == fail)
				break;
			chooseB(play);
			system("cls");
			printboard(play);
			count(turn, play,EndGame);
			EndGame = endgame(play, turn, EndGame);
		}
		else {
			printboard(play);
			if (EndGame == fail)
				break;
			chooseW(play);
			system("cls");
			printboard(play);
			count(turn, play,EndGame);
			EndGame = endgame(play, turn, EndGame);
		}
		}
	
	_getch();
	return 0;
}