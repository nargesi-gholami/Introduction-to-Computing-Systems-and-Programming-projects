#include <stdio.h>
#include <conio.h>
int main() {
	printf("guide:\n");
	printf("\n we have two player,player number 1 & player number 2,Each time it was player 1's(or 2's) turnæ press a number that he(or she)want to put his(or her) mark\n start");
	printf("\n   |   |   \n 1 | 2 | 3 \n___|___|___\n   |   |   \n 4 | 5 | 6 \n___|___|___\n   |   |   \n 7 | 8 | 9 \n   |   |   \n ");/*guide*/
	char a = ' ', b = ' ', c = ' ', d = ' ', e = ' ', f = ' ', g = ' ', h = ' ', i = ' '; /* a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9 */
	int r = 0;/* when the person wins this number changes to 1*/
	int q; /*turn*/
	char j, w;/*enterred number*/
	int t;/*for start a new game*/
	while (3) {
		for (q = 1; q < 10; q++) {
			if (q % 2 == 1)/*odd number for X*/ {
				printf("player one's turn\n");
				while (1)
				{
					scanf_s("%c", &j);
					switch (j) {
					case '1':
						if (a == ' ')
							a = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '2':
						if (b == ' ')
							b = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '3':
						if (c == ' ')
							c = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '4':if (d == ' ')
						d = 'X';
							 else {
								 printf("please press another number");
								 continue;
							 }
							 break;
					case '5':
						if (e == ' ')
							e = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '6':
						if (f == ' ')
							f = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '7':
						if (g == ' ')
							g = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '8':
						if (h == ' ')
							h = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					case '9':
						if (i == ' ')
							i = 'X';
						else {
							printf("please press another number");
							continue;
						}
						break;
					default: printf("\n please choose a number between 1 to 9");
						break;
					}
					if ('1' <= j&&j <= '9')
					{
						printf("\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n   |   |   \n", a, b, c, d, e, f, g, h, i);
						break;
					}
				}
				if ((a == 'X'&& b == 'X'&& c == 'X') || (d == 'X'&& e == 'X'&& f == 'X') || (g == 'X'&& h == 'X'&& i == 'X') || (a == 'X'&& d == 'X'&& g == 'X') || (b == 'X'&&e == 'X'&&h == 'X') || (c == 'X'&&f == 'X'&&i == 'X') || (a == 'X'&&e == 'X'&&i == 'X') || (c == 'X'&&e == 'X'&&g == 'X')) {
					printf("congratulation!player 1 has won the game");
					r = 1;
					break;
				}
				if (r != 1 && q == 9)
					printf("no one has won the game");
				continue;
			}
			else if (q % 2 == 0)/*even number for O*/
				printf("player two's turn\n ");
			while (2)
			{
				scanf_s("%c", &w);
				switch (w) {
				case '1':
					if (a == ' ')
						a = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '2':
					if (b == ' ')
						b = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '3':
					if (c == ' ')
						c = 'O';
					else
					{
						printf("please press another number");
						continue;
					}
					break;
				case '4':
					if (d == ' ')
						d = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '5':
					if (e == ' ')
						e = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '6':
					if (f == ' ')
						f = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '7':
					if (g == ' ')
						g = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '8':
					if (h == ' ')
						h = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				case '9':
					if (i == ' ')
						i = 'O';
					else {
						printf("please press another number");
						continue;
					}
					break;
				default: printf("\n please choose a number between 1 to 9");
					break;
				}
				if ('1' <= w && w <= '9') {
					printf("\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n___|___|___\n   |   |   \n %c | %c | %c \n   |   |   \n", a, b, c, d, e, f, g, h, i);
					break;
				}
			}

			if ((a == 'O'&& b == 'O'&& c == 'O') || (d == 'O'&& e == 'O'&& f == 'O') || (g == 'O'&& h == 'O'&& i == 'O') || (a == 'O'&& d == 'O'&& g == 'O') || (b == 'O'&&e == 'O'&&h == 'O') || (c == 'O'&&f == 'O'&&i == 'O') || (a == 'O'&&e == 'O'&&i == 'O') || (c == 'O'&&e == 'O'&&g == 'O')) {
				printf("congratulation!player 2 has won the game");
				r = 1;
				break;
			}
			if (r != 1 && q == 9)
				printf("no one has won the game");
			continue;
		}
		printf("\n press 1 if yot want to start a new game.otherwisw press 2");/*for start a new game*/
		scanf_s("%d", &t);
		if (t == 1) {
			q = 1;
            a = ' ', b = ' ', c = ' ', d = ' ', e = ' ', f = ' ', g = ' ', h = ' ', i = ' ';
			r = 0;
			continue;
		}
		else if (t==2)
			break;
	}
		_getch();
		return 0;
}