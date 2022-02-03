void printboard(int play[8][8]);

void init_board(int play[8][8]);

void print_g(int play[8][8]);

int count(int turn, int play[8][8], int EndGame);

void choose(int turn,int play[8][8]);

int allowed(int turn, int play[8][8], int row, int col);

int move(int turn, int play[8][8], int row, int col);

int endgame(int play[8][8], int turn, int EndGame);