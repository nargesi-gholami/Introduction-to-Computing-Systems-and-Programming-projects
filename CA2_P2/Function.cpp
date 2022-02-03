#include <stdio.h> 
#include "function.h"
#include "graphics.h"

#define black -1
#define white 1
#define empty 0
#define size 8
#define end 0
#define max 9
#define min 0
#define TRUE 1

void init_board(int play[8][8]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			play[i][j] = empty;
		}//make empty
	}
	play[3][3] = white;
	play[3][4] = black;
	play[4][4] = white;
	play[4][3] = black;

}

void print_g(int play[8][8]) {
	int i, j;
	initwindow(610, 630, "othello");//create window
	setfillstyle(SOLID_FILL, CYAN);//color of window
	floodfill(0, 0, CYAN);//start to coloring
	for (i = 20, j = 20; i <= 580 && j <= 580; i += 70, j += 70) {
		line(i, 20, j, 580);//draw board
	}
	for (i = 20, j = 20; i <= 580 && j <= 580; i += 70, j += 70) {
		line(20, i, 580, j);//draw board
	}
	setbkcolor(CYAN);
	outtextxy(5, 50, "1");
	outtextxy(5, 120, "2");
	outtextxy(5, 190, "3");
	outtextxy(5, 260, "4");
	outtextxy(5, 330, "5");
	outtextxy(5, 400, "6");
	outtextxy(5, 470, "7");
	outtextxy(5, 540, "8");//write number of the column

	outtextxy(50, 2, "1");
	outtextxy(120, 2, "2");
	outtextxy(190, 2, "3");
	outtextxy(260, 2, "4");
	outtextxy(330, 2, "5");
	outtextxy(400, 2, "6");
	outtextxy(470, 2, "7");
	outtextxy(540, 2, "8");//write number of the  row
}

void printboard(int play[8][8]) {
	int i, j;


	for ( i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (play[i][j] == black) {
				setcolor(BLACK);
				circle(j*70 + 20 + 35, i*70 + 20 + 35, 32);
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(j* 70 + 20 + 35, i * 70 + 20 + 35, BLACK);
			}
			if (play[i][j] == white) {
				setcolor(WHITE);
				circle(j*70+20+35 , i*70 +20+35 , 32);
				setfillstyle(SOLID_FILL, WHITE);
				floodfill(j * 70 + 20 + 35, i * 70 + 20 + 35, WHITE);
		}
		}
	}//draw graphic board

	/*char temp[8][8];

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
	printf("	|_____|_____|_____|_____|_____|_____|_____|_____| \n");*/
}

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
	}//counting black score and white score
	printf("\n black's score is %d\n", black_num);
	printf("white's score is %d\n", white_num);//print black and white score 
	if ((turn == 59) || (EndGame == end))
	{
		if (black_num > white_num) {
			printf("\n Congratulations,Black has won the game");
			outtextxy(120, 590, "Congratulations,Black has won the game");
		}
		else if (black_num < white_num) {
			printf("\n Congratulations,White has won the game");
			outtextxy(120, 590, "Congratulations,White has won the game");
		}
		else if (black_num == white_num) {
			printf("\n Oh!,No one has won the game");
			outtextxy(120, 590, "Oh!,No one has won the game");
		}

	}

	return end;
}

void choose(int turn, int play[8][8]) {
	int i = 0, j = 0;//i for row and j for col

	setcolor(COLOR(3, 248, 223));
	int x1 = 45, y1 = 45, x2 = 65, y2 = 65;
	rectangle(x1, y1, x2, y2);
	setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
	floodfill(x1 + 2, y1 + 2, COLOR(3, 248, 223));
	x1 -= 2;
	y1 -= 2;
	char rec;
	//printboard(play);

	int row, col;

	if (turn % 2 == white) {
			i = 0; j = 0;
		while (TRUE) {
			setbkcolor(CYAN);
			outtextxy(20, 590, "white's turn");
			printf("White's turn\n please enter a number between 1 to 8 for column\n and a number between 1 to 8 for row \n like this :2 4\n");
			//while ((rec = getch()) != ' ') {//going to left,right,Top,Down until space
				while ((rec = getchar()) != ' ') {
				if (rec == 'w') {
					--i;
					if (i >= 0) {
						if (play[i + 1][j] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i + 1][j] == black) {//Filling last play[][] with black
							setcolor(BLACK);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i + 1][j] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							x1 -= 2;
							y1 -= 2;
						}

						y1 = y1 - 70;//drawing new play[][]
						y2 = y2 - 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;
					}
					else {
						i++;
						continue;
					}
				}
				if (rec == 'a') {
					--j;
					if (j >= 0) {
						if (play[i][j + 1] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						if (play[i][j + 1] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						if (play[i][j + 1] == white) {//Filling last play[][] with White
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}
						x1 = x1 - 70;
						x2 = x2 - 70;//drawing new play[][]
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						y1 -= 2;
						x1 -= 2;
					}
					else {
						j++;
						continue;
					}
				}
				if (rec == 'd') {
					++j;
					if (j <= 7) {
						if (play[i][j - 1] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						if (play[i][j - 1] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						if (play[i][j - 1] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}
						x1 = x1 + 70;
						x2 = x2 + 70;//drawing new play[][]
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;
					}
					else {
						--j;
						continue;
					}

				}
				if (rec == 's') {
					++i;
					if (i <= 7) {
						if (play[i-1][j] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i-1][j ] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						else if (play[i-1][j ] == white) {//Filling last play[][] with White
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}
						
						y1 = y1 + 70;//drawing new play[][]
						y2 = y2 + 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;

					}
					else {
						--i;
						continue;
					}
				}
				row = i;
				col = j;
			}
			row = i;
			col = j;
			if (( col < max && col >= min) && (row < max && row >=min)) {
				if ((play[row][col] == empty)) {
					outtextxy(120, 590, "                                                       ");
					if (allowed(white, play, row, col) == 2) {
						play[row][col] = white;
						break;
					}
					else {
						setbkcolor(RED);
						outtextxy(120, 590, "please go to another place");
					}
				}
			}
			else {
				printf("please enter another number for cloumn and row\n");
				setbkcolor(RED);
				outtextxy(120, 590, "please go to another place");
				row = 0; col = 0;
				continue;
			}
		}
	}

	else {
			i = 0; j = 0;
		while (TRUE) {

			setbkcolor(CYAN);
			outtextxy(20, 590, "Black's turn");
			//printf("black's turn\nplease enter a number between 1 to 8 for column\n and a number between 1 to 8 for row \n like this :2 4\n");
 		//	while ((rec = getch()) != ' ') {
			while ((rec = getchar()) != ' ') {
      				if (rec == 'w') {
					--i;
					if (i >= 0) {
						if (play[i + 1][j] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i + 1][j] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i + 1][j] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							x1 -= 2;
							y1 -= 2;
						}

						y1 = y1 - 70;//drawing new play[][]
						y2 = y2 - 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;
					}
					else {
						i++;
						continue;
					}
				}
				if (rec == 'a') {
					--j;
					if (j >= 0) {

						if (play[i][j + 1] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i][j + 1] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						else if (play[i][j + 1] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}

						x1 = x1 - 70;//drawing new play[][]
						x2 = x2 - 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						y1 -= 2;
						x1 -= 2;
					}
					else {
						j++;
						continue;
					}
				}
				if (rec == 'd') {
					++j;
					if (j <= 7) {
						if (play[i][j - 1] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i][j - 1] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						else if (play[i][j - 1] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}
						x1 = x1 + 70;//drawing new play[][]
						x2 = x2 + 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;
					}
					else {
						--j;
						continue;
					}

				}
				if (rec == 's') {
					++i;
					if (i <= 7) {
						if (play[i-1][j] == empty) {//Filling last play[][] with color of board
							setcolor(CYAN);
							rectangle(x1, y1, x2, y2);
							setfillstyle(SOLID_FILL, CYAN);
							floodfill(x1 += 2, y1 += 2, CYAN);
							x1 -= 2;
							y1 -= 2;
						}
						else if (play[i-1][j] == black) {//Filling last play[][] with Black
							setcolor(BLACK);
							setfillstyle(SOLID_FILL, BLACK);
							floodfill(x1 += 2, y1 += 2, BLACK);
							y1 -= 2;
							x1 -= 2;
						}
						else if (play[i-1][j] == white) {//Filling last play[][] with white
							setcolor(WHITE);
							setfillstyle(SOLID_FILL, WHITE);
							floodfill(x1 += 2, y1 += 2, WHITE);
							y1 -= 2;
							x1 -= 2;
						}
						y1 = y1 + 70;//drawing new play[][]
						y2 = y2 + 70;
						setcolor(COLOR(3, 248, 223));
						rectangle(x1, y1, x2, y2);
						setfillstyle(SOLID_FILL, COLOR(3, 248, 223));
						floodfill(x1 += 2, y1 += 2, COLOR(3, 248, 223));
						x1 -= 2;
						y1 -= 2;
					}
					else {
						--i;
						continue;
					}
				}
				row = i;
				col = j;
			}
			
			///////////////////////////////////////////////////////////////////////////
			row = i;
			col = j;
			setbkcolor(CYAN);
			if ((col < max && col >= min) && (row < max && row >= min)) {
				if (play[row][col] == 0) {
					outtextxy(120, 590, "                                                 ");
					if (allowed(0, play, row, col) == 2) {
						play[row][col] = black;
						break;
					}
					else {
						setbkcolor(RED);
						outtextxy(120, 590, "please go to another place");
					}
				}
			}
			else {
				//printf("please enter another number for cloumn and row\n");
				setbkcolor(RED);
				outtextxy(120, 590, "please go to another place");
				row = 0; col = 0;
				continue;
			}
		}
	}
}

int allowed(int turn, int play[8][8], int row, int col) {
	int move_j, move_i;
	int change_i, change_j;
	int i, j;// i for row and j for column
	int valid = 0;
	int valid2=0;
	if (turn % 2 == 0) {
		if (play[row - 1][col - 1] == white) //black's turn
		{
			move_i = row - 1;
			for ((move_j = col - 1); (move_i >= 0 && move_j >= 0); (move_i-- && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
						if ((play[change_i][change_j] == white) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else{
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
							play[change_i][change_j] = black;
							play[row - 1][col - 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;//new
				}
			}
		}//correct
		
		 //left row up col
		if (play[row + 1][col - 1] == white) {
			move_i = row + 1;
			for ((move_j = col - 1); (move_i < 8 && move_j >= 0); (move_i++ && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i - 1; change_i > row && change_j < col ; change_i-- && change_j++) {
						if ((play[change_i][change_j] == white) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
							play[change_i][change_j] = black;
							play[row + 1][col - 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;//new
				}

			}//left row down col

		}
	
		if (play[row - 1][col + 1] == white) {
			move_i = row - 1;
			for ((move_j = col + 1); (move_i >= 0 && move_j < 8); (move_i-- && move_j++)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						if ((play[change_i][change_j] == white) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
							play[change_i][change_j] = black;
							play[row - 1][col + 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//left row down col
	
		if (play[row + 1][col + 1] == white) {
			move_i = row + 1;
			for ((move_j = col + 1); (move_i < 8 && move_j < 8); (move_i++ && move_j++)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j - 1;
					for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
						if ((play[change_i][change_j] == white) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
							play[change_i][change_j] = black;
							play[row + 1][col + 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//right row down col

		if (play[row + 1][col] == white) {
			for ((move_i = row + 1); (move_i < 8); (move_i++)) {
				if (play[move_i][col] == black) {
					for (int change_i = move_i - 1; change_i > row; change_i--) {
						if ((play[change_i][col] == white) && (play[change_i][col] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i - 1; change_i > row; change_i--) {
							play[change_i][col] = black;
							play[row + 1][col] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//down col

		if (play[row - 1][col] == white) {
			for ((move_i = row - 1); (move_i >= 0); (move_i--)) {
				if (play[move_i][col] == black) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						if ((play[change_i][col] == white) && (play[change_i][col] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i + 1; change_i < row; change_i++) {
							play[change_i][col] = black;
							play[row - 1][col] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//up col

		if (play[row][col - 1] == white) {
			for ((move_j = col - 1); (move_j >= 0); (move_j--)) {
				if (play[row][move_j] == black) {
					for (change_j = move_j + 1; change_j < col; change_j++) {
						if ((play[row][change_j] == white) && (play[row][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_j = move_j + 1; change_j < col; change_j++) {
							play[row][change_j] = black;
							play[row][col - 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//left row

		if (play[row][col + 1] == white) {
			for ((move_j = col + 1); (move_j < 8); (move_j++)) {
				if (play[row][move_j] == black) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						if ((play[row][change_j] == white) && (play[row][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}

					if (valid == 2) {
						for (change_j = move_j - 1; change_j > col; change_j--) {
							play[row][change_j] = black;
							play[row][col + 1] = black;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//right row
	}

	//////////////////////////////////////////////////////////////////


	else if (turn % 2 == 1) //white's turn
	{
	
		if (play[row - 1][col - 1] == black) {
			move_i = row - 1;
			for ((move_j = col - 1); (move_i >= 0 && move_j >= 0); (move_i-- && move_j--)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j + 1;
					for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
						if ((play[change_i][change_j] == black) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
							play[change_i][change_j] = white;
							play[row - 1][col - 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//left row up col

		if (play[row + 1][col - 1] == black) {
			move_i = row + 1;
			for ((move_j = col - 1); (move_i < 8 && move_j >= 0); (move_i++ && move_j--)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j + 1;
					for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
						if ((play[change_i][change_j] == black) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
							play[change_i][change_j] = white;
							play[row + 1][col - 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}

		}//left row down col
	
		if (play[row - 1][col + 1] == black) {
			move_i = row - 1;
			for ((move_j = col + 1); (move_i >= 0 && move_j < 8); (move_i-- && move_j++)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						if ((play[change_i][change_j] == black) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
							play[change_i][change_j] = white;
							play[row - 1][col + 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//left row down col

		if (play[row + 1][col + 1] == black) {
			move_i = row + 1;
			for ((move_j = col + 1); (move_i < 8 && move_j < 8); (move_i++ && move_j++)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j - 1;
					for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
						if ((play[change_i][change_j] == black) && (play[change_i][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
							play[change_i][change_j] = white;
							play[row + 1][col + 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//right row down col

		if (play[row + 1][col] == black) {
			for ((move_i = row + 1); (move_i < 8); (move_i++)) {
				if (play[move_i][col] == white) {
					for (change_i = move_i - 1; change_i > row; change_i--) {
						if ((play[change_i][col] == black) && (play[change_i][col] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i - 1; change_i > row; change_i--) {
							play[change_i][col] = white;
							play[row + 1][col] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//down col

		if (play[row - 1][col] == black) {
			for (move_i = row - 1; (move_i >= 0); (move_i--)) {
				if (play[move_i][col] == white) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						if ((play[change_i][col] == black) && (play[change_i][col] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i + 1; change_i < row; change_i++) {
							play[change_i][col] = white;
							play[row - 1][col] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//up col

		if (play[row][col - 1] == black) {
			for ((move_j = col - 1); (move_j >= 0); (move_j--)) {
				if (play[row][move_j] == white) {
					for (change_j = move_j + 1; change_j < col; change_j++) {
						if ((play[row][change_j] == black) && (play[row][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_j = move_j + 1; change_j < col; change_j++) {
							play[row][change_j] = white;
							play[row][col - 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}
		}//left row

		if (play[row][col + 1] == black) {
			for ((move_j = col + 1); (move_j < 8); (move_j++)) {
				if (play[row][move_j] == white) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						if ((play[row][change_j] == black) && (play[row][change_j] != empty)) {
							valid = 2;
						}
						else {
							valid = 0;
							break;
						}
					}
					if (valid == 2) {
						for (change_j = move_j - 1; change_j > col; change_j--) {
							play[row][change_j] = white;
							play[row][col + 1] = white;
							valid2 = 2;
						}
						break;
					}
					break;
				}
			}

		}//right row

	}

	return valid2;
}

int endgame(int play[8][8], int turn, int EndGame) {
	turn++;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			EndGame = move(turn, play, i, j);
			if (EndGame == 2)
				break;
		}
		if (EndGame == 2)
			break;
	}
	turn--;
	if (EndGame == 2)
		return 1;
	else
		return 0;
}

int move(int turn, int play[8][8], int row, int col) {
	int move_j, move_i;
	int change_i, change_j;
	int valid = 0;
	if (turn % 2 == 0) {
		if (play[row - 1][col - 1] == white) //black's turn
		{
			move_i = row - 1;
			for ((move_j = col - 1); (move_i >= 0 && move_j >= 0); (move_i-- && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		} //left row up col
		if (play[row + 1][col - 1] == white) {
			move_i = row + 1;
			for ((move_j = col - 1); (move_i < 8 && move_j >= 0); (move_i++ && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}

			}//left row down col
		}
		if (play[row - 1][col + 1] == white) {
			move_i = row - 1;
			for ((move_j = col + 1); (move_i >= 0 && move_j < 8); (move_i-- && move_j++)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//left row down col
		if (play[row + 1][col + 1] == white) {
			move_i = row + 1;
			for ((move_j = col + 1); (move_i < 8 && move_j < 8); (move_i++ && move_j++)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j - 1;
					for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//right row down col
		if (play[row + 1][col] == white) {
			for ((move_i = row + 1); (move_i < 8); (move_i++)) {
				if (play[move_i][col] == black) {
					for (change_i = move_i - 1; change_i > row; change_i--) {
						if (play[change_i][col] == white && play[change_i][col] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//down col
		if (play[row - 1][col] == white) {
			for ((move_i = row - 1); (move_i >= 0); (move_i--)) {
				if (play[move_i][col] == black) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						if (play[change_i][col] == white && play[change_i][col] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
	}//up col
	if (play[row][col - 1] == white) {
		for ((move_j = col - 1); (move_j >= 0); (move_j--)) {
			if (play[row][move_j] == black) {
				for (change_j = move_j + 1; change_j < col; change_j++) {
					if (play[row][change_j] == white && play[row][change_j] != empty) {

						valid = 2;
					}
					else
						valid = 0;
				}
			}
		}
		}//left row/////
		if (play[row][col + 1] == white) {
			for ((move_j = col + 1); (move_j < 8); (move_j++)) {
				if (play[row][move_j] == black) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						if (play[row][change_j] == white && play[row][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//right row
	}
	
	//////////////////////////////////////////////////////////////////
		
	else if (turn % 2 == 1) //white's turn
	{
		if (play[row - 1][col - 1] == black) {
			move_i = row - 1;
			for ((move_j = col - 1); (move_i >= 0 && move_j >= 0); (move_i-- && move_j--)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j + 1;
					for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
						if (play[change_i][change_j] == black && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//left row up col
		if (play[row + 1][col - 1] == black) {
			move_i = row + 1;
			for ((move_j = col - 1); (move_i < 8 && move_j >= 0); (move_i++ && move_j--)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j + 1;
					for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
						if (play[change_i][change_j] == black && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}

		}//left row down col

		if (play[row - 1][col + 1] == black) {
			move_i = row - 1;
			for ((move_j = col + 1); (move_i >= 0 && move_j < 8); (move_i-- && move_j++)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						if (play[change_i][change_j] == black && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//left row down col
		if (play[row + 1][col + 1] == black) {
			move_i = row + 1;
			for ((move_j = col + 1); (move_i < 8 && move_j < 8); (move_i++ && move_j++)) {
				if (play[move_i][move_j] == white) {
					change_j = move_j - 1;
					for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
						if (play[change_i][change_j] == black && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//right row down col
		if (play[row + 1][col] == black) {
			for ((move_i = row + 1); (move_i < 8); (move_i++)) {
				if (play[move_i][col] == white) {
					for (change_i = move_i - 1; change_i > row; change_i--) {
						if (play[change_i][col] == black && play[change_i][col] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//down col
		if (play[row - 1][col] == black) {
			for (move_i = row - 1; (move_i >= 0); (move_i--)) {
				if (play[move_i][col] == white) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						if (play[change_i][col] == black && play[change_i][col] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//up col
		if (play[row][col - 1] == black) {
			for ((move_j = col - 1); (move_j >=0); (move_j--)) {
				if (play[row][move_j] == white) {
					for (change_j = move_j + 1; change_j < col; change_j++) {
						if (play[row][change_j] == black && play[row][change_j] != empty) {

							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}
		}//left row
		if (play[row][col + 1] == black) {
			for ((move_j = col + 1); (move_j < 8); (move_j++)) {
				if (play[row][move_j] == white) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						if (play[row][change_j] == black && play[row][change_j] != empty) {
							valid = 2;
						}
						else
							valid = 0;
					}
				}
			}

		}//right row

	}

	return valid;
}