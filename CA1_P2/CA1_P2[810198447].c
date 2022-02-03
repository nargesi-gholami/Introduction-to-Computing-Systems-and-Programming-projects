#include <stdio.h>
#include <conio.h>
#define true 1
#define _win 1
int turn; /*turn*/
int win = 0;/* when the person wins this number changes to 1*/
int again;/*for start a new game*/
char x, o;/*enterred number*/
char PlayGame1 (char choose[9] );//for player 1
char PlayGame2 (char choose[9]);//for player 2
char WinCheck(char choose[9]);
char print_board(char choose[9]);
char choose[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; /* a[0]=1,a[1]=2,a[2]=3,a[3]=4,a[4]=5,a[5]=6,a[6]=7,a[7]=8,a[8]=9 */
int main() {
	printf("guide:\n");
	printf("\n we have two player,player number 1 & player number 2,Each time it was player 1's(or 2's) turn press a number that he(or she)want to put his(or her) mark\n start");
	printf("\n   |   |   \n 1 | 2 | 3 \n___|___|___\n   |   |   \n 4 | 5 | 6 \n___|___|___\n   |   |   \n 7 | 8 | 9 \n   |   |   \n ");/*guide*/
	while (true) {
		for (turn = 1; turn < 10; turn++) {
			if (turn % 2 == 1)/*odd number for X*/ {
				PlayGame1(choose);
				WinCheck(choose);
				print_board(choose);
				if (win == _win )
					break;
			}
			else if (turn % 2 == 0) /*even number for O*/ {
				PlayGame2(choose);
				WinCheck(choose);
				print_board(choose);
				if (win == _win)
					break;
			}
		}
		printf("\n press 1 if yot want to start a new game.otherwisw press 2\n");/*for start a new game*/
		scanf_s("%d", &again);
		getchar();
			if (again == 1) {
				turn = 1;//for start 
				win = 0;
				choose[0] = ' '; choose[1] = ' '; choose[2] = ' '; choose[3] = ' '; choose[4] = ' '; choose[5] = ' '; choose[6] = ' '; choose[7] = ' '; choose[8] = ' ';
				continue;	
			}
			else if(again==2)
				break;
		}
		_getch();
		return 0;
	}
char PlayGame1(char choose[9]) {
	while (true) {
		printf("\n player one's turn\n");
		scanf_s("%c", &x);
		getchar();
		x -= 48;
		x =(x - 1);//for exasmple choose 1 means choose[0] 
		if (choose[x] ==' ') {
			choose[x] = 'X';
			break;
		}
		else {
			printf("please enter another number");
			continue;
		}
	}
}
char PlayGame2( char choose[9]) {
	while (true){
		printf("\n player two's turn\n ");
		scanf_s("%c", &o);
		getchar();
		o -= 48;
		o = (o - 1);//for exasmple choose 1 means choose[0]
		if (choose[o] ==' ') {
		choose[o] = 'O';
			break;
		}
		else {
			printf("please enter another number");
			continue;
		}
	}
}
char WinCheck(char choose[9]) {
	if
		((choose[0] == 'X'&& choose[1] == 'X'&& choose[2] == 'X') || (choose[3] == 'X'&& choose[4] == 'X'&& choose[5] == 'X') || (choose[6] == 'X'&& choose[7] == 'X'&& choose[8] == 'X') || (choose[0] == 'X'&& choose[3] == 'X'&& choose[6] == 'X') || (choose[1] == 'X'&&choose[4] == 'X'&&choose[7] == 'X') || (choose[2] == 'X'&&choose[5] == 'X'&&choose[8] == 'X') || (choose[0] == 'X'&&choose[4] == 'X'&&choose[8] == 'X') || (choose[2] == 'X'&& choose[4] == 'X'&& choose[6] == 'X')) {
		printf("congratulation!player 1 has won the game");
		win = _win ;
	}
	else if
		((choose[0] == 'O'&& choose[1] == 'O'&& choose[2] == 'O') || (choose[3] == 'O'&& choose[4] == 'O'&& choose[5] == 'O') || (choose[6] == 'O'&& choose[7] == 'O'&& choose[8] == 'O') || (choose[0] == 'O'&& choose[3] == 'O'&& choose[6] == 'O') || (choose[1] == 'O'&&choose[4] == 'O'&&choose[7] == 'O') || (choose[2] == 'O'&&choose[5] == 'O'&&choose[8] == 'O') || (choose[0] == 'O'&&choose[4] == 'O'&&choose[8] == 'O') || (choose[2] == 'O'&& choose[4] == 'O'&& choose[6] == 'O')) {
		printf("congratulation!player 2 has won the game");
		win = _win ;
	}
	else if (win != _win && turn == 9) {
		printf("no one has won the game");
	}
}
char print_board(char choose[9]) {
	{
		printf("\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n   |   |   \n"
			, choose[0], choose[1], choose[2], choose[3], choose[4], choose[5], choose[6], choose[7], choose[8]);}
}

