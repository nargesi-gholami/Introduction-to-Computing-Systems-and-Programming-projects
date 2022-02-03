#include <stdio.h> 


#define black -1
#define white 1
#define empty 0


int allowed(int turn, int play[8][8], int row, int col) {
	int move_j, move_i;
	int change_i, change_j;
	int i, j;// i for row and j for column
	int valid = 0;
	if (turn %2 == 0 ) {
		if (play[row - 1][col - 1] == white) //black's turn
		{
			move_i = row-1 ;
			for ((move_j = col-1); (move_i >= 0 && move_j >= 0 ); (move_i-- && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i + 1; change_i < row && change_j < col; change_i++&& change_j++) {
							play[change_i][change_j] = black;
							play[row - 1][col - 1] = black;
						}
					}
				}
			}
		}//correct
		//left row up col
		if (play[row + 1][col - 1] == white) {
			move_i = row +1 ;
			for ((move_j = col - 1); (move_i < 8 && move_j >= 0); (move_i++ && move_j--)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j + 1;
					for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
							play[change_i][change_j] = black;
							play[row + 1][col - 1] = black;
						}
					}
				}

			}//left row down col

		}
		if (play[row - 1][col + 1] == white) {
			move_i = row -1;
			for ((move_j = col + 1); (move_i >=0 && move_j < 8); (move_i-- && move_j++)) {
				if (play[move_i][move_j] == black) {
					change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						if (play[change_i][change_j] == white && play[change_i][change_j] != empty) {
							valid = 2;
						}
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
							play[change_i][change_j] = black;
							play[row - 1][col + 1] = black;
						}
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
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j - 1;
						for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
							play[change_i][change_j] = black;
							play[row + 1][col + 1] = black;
						}
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
						else {
							break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i - 1; change_i > row; change_i--) {
							play[change_i][col] = black;
							play[row + 1][col] = black;
						}
					}
				}
			}
		}//down col
		if (play[row - 1][col] == white) {
			for ((move_i = row - 1); (move_i >=0); (move_i--)) {
				if (play[move_i][col] == black) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						if (play[change_i][col] == white && play[change_i][col] != empty) {
							valid = 2;
						}
						else {
					break;
						}
					}
					if (valid == 2) {
						for (change_i = move_i + 1; change_i < row; change_i++) {
							play[change_i][col] = black;
							play[row - 1][col] = black;
						}
					}
				}
			}
		}//up col
		if (play[row][col - 1] == white) {
			for ((move_j = col - 1); (move_j >=0); (move_j--)) {
				if (play[row][move_j] == black) {
					for (change_j = move_j + 1; change_j < col; change_j++) {
						if (play[row][change_j] == white && play[row][change_j] != empty) {

							valid = 2;
						}
						else {
							break;
						}
					}
					if (valid == 2) {
						for (change_j = move_j + 1; change_j < col; change_j++) {
							play[row][change_j] = black;
							play[row][col - 1] = black;
						}
					}
				}
			}
		}//left row
		if (play[row][col + 1] == white) {
			for ((move_j = col + 1); (move_j < 8); (move_j++)) {
				if (play[row][move_j] == black) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						if (play[row][change_j] == white && play[row][change_j] != empty) {
							valid = 2;
						}
						else {
							break;
						}
					}

					if (valid == 2) {
						for (change_j = move_j - 1; change_j > col; change_j--) {
							play[row][change_j] = black;
							play[row][col + 1] = black;
						}
					}
				}
			}
		}//right row
	}

	//////////////////////////////////////////////////////////////////


	else if (turn %2==1) //white's turn
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
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i + 1; change_i < row && change_j < col; change_i++ && change_j++) {
							play[change_i][change_j] = white;
							play[row - 1][col - 1] = white;
						}
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
						else {
							break;
						}
					}
					if (valid == 2) {
						change_j = move_j + 1;
						for (change_i = move_i - 1; change_i > row && change_j < col; change_i--&& change_j++) {
							play[change_i][change_j] = white;
							play[row + 1][col - 1] = white;
						}
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
					else {
						break;
					}
				}
				if (valid == 2) {
						change_j = move_j - 1;
					for (change_i = move_i + 1; change_i < row && change_j > col; change_i++ && change_j--) {
						play[change_i][change_j] = white;
						play[row - 1][col + 1] = white;
					}
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
					else {
						break;
					}
				}
				if (valid == 2) {
					change_j = move_j - 1;
					for (change_i = move_i - 1; change_i > row && change_j > col; change_i-- && change_j--) {
						play[change_i][change_j] = white;
						play[row + 1][col + 1] = white;
					}
				}
			}
		}
	}//right row down col
	if (play[row + 1][col] == black) {
		for ((move_i = row + 1); (move_i < 8 ); (move_i++)) {
			if (play[move_i][col] == white) {
				for (change_i = move_i - 1; change_i > row; change_i--) {
					if (play[change_i][col] == black && play[change_i][col] != empty) {
						valid = 2;
					}
					else {
						break;
					}
				}
				if (valid == 2) {
					for (change_i = move_i - 1; change_i > row; change_i--) {
						play[change_i][col] = white;
						play[row + 1][col] = white;
					}
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
					else {
						break;
					}
				}
				if (valid == 2) {
					for (change_i = move_i + 1; change_i < row; change_i++) {
						play[change_i][col] = white;
						play[row - 1][col] = white;
					}
				}
			}
		}
	}//up col
	if (play[row][col - 1] == black) {
		for ((move_j = col-1); (move_j >0); (move_j--)) {
			if (play[row][move_j] == white) {
				for (change_j = move_j + 1; change_j < col; change_j++) {
					if (play[row][change_j] == black && play[row][change_j] != empty) {

						valid = 2;
					}
					else {
						break;
					}
				}
				if (valid == 2) {
					for (change_j = move_j + 1; change_j < col; change_j++) {
						play[row][change_j] = white;
						play[row][col - 1] = white;
					}
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
					else {
						break;
					}
				}
				if (valid == 2) {
					for (change_j = move_j - 1; change_j > col; change_j--) {
						play[row][change_j] = white;
						play[row][col + 1] = white;
					}
				}
			}
		}

	}//right row

}

		return valid;
}