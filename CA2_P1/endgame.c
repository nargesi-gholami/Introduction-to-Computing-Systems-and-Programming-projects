
int endgame(int play[8][8],int turn,int EndGame) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			EndGame = allowed(turn, play, i, j);
			if (EndGame != 2)
				break;
		}
		if (EndGame != 2)
			break;
	}
			if (EndGame != 2)
				return 1;
			else
				return 0;
}