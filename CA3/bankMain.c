#include "Function.h"

int main() {
	
	user* head = (user*)malloc(sizeof(user));
	head = init_head(head);

	readfile(head);
	
	welcome(head);

	getch();
	return 0;
}