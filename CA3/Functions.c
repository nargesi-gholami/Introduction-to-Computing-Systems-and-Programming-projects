#include "Function.h"

user* init_head(user*head) {
	head->user_name = "a";//we don't need head in Performancing program
	head->password = "b";
	head->phone_number = "c";
	head->Unique_ID = rand();
	head->number_of_transaction = 0;
	head->cash = 0;
	head->tra.transfer_to_other = 0;
	head->tra.transfer_to_me = 0;
	head->tra.admin_deposit = 0;
	head->tra.admin_withdraw = 0;
	head->next = NULL;//important
	return head;
}

void welcome (user* head) {
	
		admin* manager = (admin*)malloc(sizeof(admin));
		manager->name = "admin";
		manager->password = "123";
		manager->phone_number = "00000000000";//declare admin

		printf("________________________________________________________________________________\n");
		printf("|\t\tWelcome to UtBank,We are here to help you:)\t\t\t|\n|\t\t\t\t\t\t\t\t\t\t|\n|\t\tplease login to start service\t\t\t\t\t|\n");
		printf("|_______________________________________________________________________________|\n");

		

		while (TRUE) {
			char order[15];//for order login
			char name[15];//name of the user or admin
			char pass[15];//password of user
			char phone[15];//phone number of user 

			scanf_s("%s", order, sizeof(order));//get order from user
			scanf_s("%s", name, sizeof(name));//get name from user
			scanf_s("%s", pass, sizeof(pass));//get password from user
			scanf_s("%s", phone, sizeof(phone));//get pgone number from user

			if (!strcmp("login", order))
				login(manager, head, name, pass, phone);//login to admin orders or user orders
			else
				printf("\ninvalid command\n");
		}
	
}		

int login(admin* manager , user* head ,char* name, char* password, char* phone_number) {
	
			if (!(strcmp(name, manager->name)) && (!strcmp(password, manager->password) ) && (!strcmp(phone_number, manager->phone_number))) {
				enter_admin_orders(head);//enter to admin's command 
			}
			else {
				user* output = (user*)malloc(sizeof(user));
				if (output != NULL) {
					output = search_username(head, name, password, phone_number);//search user name 
					if (output != NULL) {
						enter_user_order(head, output);//enter into user order
					}
					else
						printf("\nWe don't have this user,Maybey you enter wrong username or password\n");
				}
				else
					printf("We don't have enough memory");
			}
		}

int enter_admin_orders(user* head) {

	char order[20];//for admin order
	int output;//for check return of functions

	printf("________________\n");
	printf("\n admin:)\nWhat can I do?\n");

	while (TRUE) {

		printf("\nEnter your command\n");
		scanf_s("%s", order, sizeof(order));//get order from user

		if (!strcmp(order, "logout"))
			welcome(head);//Get out of admin panel

		else
		output = init_order_admin(head, order);//enter to initialize admin's order

		if (output == TRUE) {
			printf("your command completed:)Do tou have another request?\nIf you don't have,write logout otherwise write your command");
			continue;
		}
		else
			printf("We don't recognize your command");
	}
}

int init_order_admin(user* head,char*order) {
	if (!strcmp(order, "view")) {//compare strings
		char name[15];

		scanf_s("%s", name, sizeof(name));//name of the person who we want to view

		view(head,name);

		return TRUE;
	}
	else if (!strcmp(order,"add_user")) {//compare strings

		char name[10];
		char pass[10];
		char phone[12];

		scanf_s("%s", name, sizeof(name));
		scanf_s("%s", pass, sizeof(pass));
		scanf_s("%s", phone, sizeof(phone));

		add_user(head,name, pass, phone);

		return TRUE;
	}
	else if (!strcmp(order, "deposit")) {//compare strings
		char name[15];
		int amount=0;

		scanf_s("%s", name, sizeof(name));
		scanf_s("%d", &amount);

		deposit(head,name,amount);

		return TRUE;
	}
	else if (!strcmp(order, "withdraw")){//compare strings

		char name[10];
		int amount = 0;

		scanf_s("%s", name, sizeof(name));
		scanf_s("%d", &amount);

		withdraw(head,name,amount);

		return TRUE;
	}
	 else if (!strcmp(order, "delete")) {//compare strings

		char user_name[10];

		scanf_s("%s", user_name, sizeof(user_name));

		deleting(head,user_name);

		return TRUE;
	}
	else if (!strcmp(order, "exit")) {//compare strings

		FILE* input;
		input = fopen("input.txt", "w");
		user* current = (user*)malloc(sizeof(user));

		current = head->next;
		while (current != NULL) {
			write(current, input);
			current = current->next;
		}
		exit(EXIT_FAILURE);
	}
	else
		return FALSE;
}

int add_user(user* head, char* name, char* password, char* phone_number) {

	int invalid=0;//for check Repetitious name 

	user* current = (user*)malloc(sizeof(user));
	if (current != NULL) {
		current = head;

		while (current != NULL) {
			if ((!strcmp(current->user_name, name)) || (!strcmp(current->phone_number, phone_number))) {
				invalid = INVALID;//invalid for check Repetitious name
				break;
			}
			else
				current = current->next;
		}


		if (invalid == INVALID) {
			printf("It's not valid name or phone number\nplease enter another name or phone number\n");

			enter_admin_orders(head);//back and get another order from user
		}
		else {
			current = head;
			while (TRUE) {
				if (current->next == NULL) {
					user* new_user = (user*)malloc(sizeof(user));
					if (new_user != NULL) {
						transactions* tra = ((transactions*)malloc(sizeof(transactions)));//declare a struct for transactions
						new_user->user_name = name;
						new_user->password = password;
						new_user->phone_number = phone_number;
						srand(time(0));
						new_user->Unique_ID = rand();
						new_user->number_of_transaction = 0;//declare primary information
						new_user->cash = 0;
						new_user->tra.transfer_to_other = 0;
						new_user->tra.transfer_to_me = 0;
						new_user->tra.admin_deposit = 0;
						new_user->tra.admin_withdraw = 0;
						new_user->next = NULL;
						current->next = new_user;

						printf("\nUser registered\n");
						enter_admin_orders(head);//back to admin panel
					}
					else 
						printf("We don't have enough memory");
				}
					else
						current = current->next;
				
			}
		}
	}
	else
		printf("We don't have enough memory");
}

int view(user* head, char* name) {

	user* current = (user*)malloc(sizeof(user));
	if (current != NULL) {
		current = head;//for searching and find name

		while (current != NULL) {
			if (!strcmp(current->user_name, name)) {
				printf("_____________________________________________________________________________\n");
				printf("The username is :%s\n", current->user_name);
				printf("The phone number is :%s\n", current->phone_number);
				printf("The unique ID is :%d\n", current->Unique_ID);
				printf("The cash is :%d\n", current->cash);
				printf("The number of transactions is %d\n", current->number_of_transaction);
				printf("The number of transferring to other is :%d\n", current->tra.transfer_to_other);
				printf("The number of transfserring to me is :%d\n", current->tra.transfer_to_me);
				printf("The number of admin deposit  is :%d\n", current->tra.admin_deposit);
				printf("The number of admin withdraw is :%d\n", current->tra.admin_withdraw);
				readtra(current);//read all transactions from file
				printf("_____________________________________________________________________________\n");

				enter_admin_orders(head);
			}

			current = current->next;
		}
		printf("this person doesn't exist\n");
		enter_admin_orders(head);//back to admin's panel
	}
	else
		printf("We don't have enough memory");
}

int init_order(user* head,user* user_0,char*order) {
	if (!strcmp(order, "view") ){

		view_user(head,user_0);//function for view person
		return TRUE;
	}
	if (!strcmp(order, "transfer")) {

		char name[10];
		char amount[10];
		int amounti;

		scanf_s("%s", name, sizeof(name));
		scanf_s("%s", amount, sizeof(amount));

		amounti = atoi(amount);
		user_0->tra.transfer_to_other++;

		if (amounti <= user_0->cash) {
			transfer(head, user_0, name, amounti);//transferring money
			return TRUE;
		}

		else
			printf("You don't have enough cash");
	}
	if (!strcmp(order, "exit")) {

		FILE* input;
		input = fopen("input.txt", "w");

		if (input != NULL) {

			user* current = (user*)malloc(sizeof(user));//declare temp struct
			current = head->next;//declare current
			while (current != NULL) {
				write(current, input);
				current = current->next;
			}
			fclose(input);
			exit(EXIT_FAILURE);
		}
		else
			printf("can't open a file");
	}
	
	return FALSE;
}

int transfer(user* head,user*user_0,char*name, int amount) {
	FILE*information;
	int check;//for check write in file
	user* current = (user*)malloc(sizeof(user));//declare temp struct
	if (current != NULL) {
		current = head;

		while (current != NULL) {
			if (!strcmp(current->user_name, name)) {

				current->cash += amount;
				current->number_of_transaction++;
				current->tra.transfer_to_me++;
				user_0->cash -= amount;

				information = fopen("information.txt", "a+");
				if (information != NULL) {
					check = fprintf(information, " %s\n transfer %d to %s\n", user_0->user_name, amount, name);//print in file
					check = fprintf(information, " %s\n %s transferred for You %d\n", name, user_0->user_name, amount);
					if (check == 0)
						printf("Can't open a file for write");
					fclose(information);
				}
				else
					printf("can't open a file for write information");

				printf("Your command done\n");
				enter_user_order(head, user_0);
			}
			else
				current = current->next;//search in user name
		}

		printf("We can't find this username,try again");
	}
	else
		printf("We don't have enough memory");

}

int deleting(user* head, char* name) {
	int valid=0;

	user* current = (user*)malloc(sizeof(user));
	current = head;

	while (current->next != NULL) {
		if (!strcmp(name,current->next->user_name)) {
			valid = VALID;//Be sure ! that person exist
			break;
		}
		else
		current = current->next;
	}

	if (valid != VALID) {
		printf("It's not valid name or phone number\nplease enter another name for deleting\n");
		enter_admin_orders(head);//Back to the panel
	}

	else {
		while (TRUE) {
			if (!strcmp(current->next->user_name, name)) {
				user* new1 = (user*)malloc(sizeof(user));
				if (new1 != NULL) {
					new1 = current->next;
					current->next = current->next->next;
					free(new1);//delete that user from bank
					printf("\nUser deleted\n");
					enter_admin_orders(head);
				}
			else
				printf("We don't have enough memory");
			}
			else
			current = current->next;
		}
	}
}

int deposit(user* head, char* name, int amount) {

	FILE* information;
	
	user* current = (user*)malloc(sizeof(user));
	if (current != NULL) {
		current = head;

		while (current != NULL) {
			if (!strcmp(current->user_name, name)) {
				current->cash += amount;
				current->number_of_transaction++;
				current->tra.admin_deposit++;
				information = fopen("information.txt", "a+");
				if (information != NULL) {
					fprintf(information, " %s\n admin deposited %d for you\n", current->user_name, amount);
					fclose(information);
				}
				else
					printf("can't open a file for write information");

				printf("\n\nYour command done\n %d deposited\n\n", amount);
				enter_admin_orders(head);
			}
			else
				current = current->next;
		}
		printf("We can't find this username,try again\n");
	}
	else
		printf("We don't have enough memory");
}

int withdraw(user* head, char* name, int amount) {
	FILE*information;
	
	user* current = (user*)malloc(sizeof(user));
	if (current != NULL) {
		current = head;

		while (current != NULL) {
			if (!strcmp(current->user_name, name)) {
				if (amount <= current->cash) {
					current->cash -= amount;
					current->number_of_transaction++;
					current->tra.admin_withdraw++;
					information = fopen("information.txt", "a+");//open file
					if (information != NULL) {
						fprintf(information, " %s\n Admin withdrawn %d from you\n", current->user_name, amount);//write in file
						fclose(information);//close file
					}
					else
						printf("can't open a file for write information");

					printf("Your command done\n %d withdrawn\n", amount);
					enter_admin_orders(head);
				}
				else {
					printf("\ncash isn't enough\n");
					enter_admin_orders(head);//back to admin's panel
				}
			}
			else
				current = current->next;
		}
		printf("We can't find this username,try again");
	}
	else
		printf("We don't have enough memory");

}

int write(user*new_user,FILE* input) {
	
	fprintf(input, " %s\n", new_user->user_name);
	fprintf(input, "%s\n", new_user->password);
	fprintf(input, "%s\n", new_user->phone_number);
	fprintf(input, "%d\n", new_user->Unique_ID);
	fprintf(input, "%d\n", new_user->cash);
	fprintf(input, "%d\n", new_user->number_of_transaction);
	fprintf(input, "%d\n", new_user->tra.transfer_to_other);
	fprintf(input, "%d\n", new_user->tra.transfer_to_me);
	fprintf(input, "%d\n", new_user->tra.admin_deposit);
	fprintf(input, "%d\n", new_user->tra.admin_withdraw);//print all thing in file
	
	

}

int readtra(user* current) {
	char c=" ";

	FILE*information;
	information = fopen("information.txt", "r");
	if (information != NULL) {
		c = fgetc(information);

		while (c != EOF) {//for checking EOF
			char*line;
			line = readline(information);
			if (!strcmp(line, current->user_name)) {
				line = readline(information);
				puts(line);//print line
				printf("\n");
			}
			c = fgetc(information);
		}
		fclose(information);
	}
	else
		printf("Can't open A FILE");
}

char* readline(FILE*information) {
	int i = 0;
	int length = ZERO;

	char* line = (char*)malloc(sizeof(char));//malloc line
	*(line) = '0';
	char temp[1] =" ";

	while (i<5000) {

		fread(temp, sizeof(char), ONE, information);//reading file 
		length++;

		line = (char*)realloc(line, sizeof(char) * length);//reaalloc file

		line[length - ONE] = NULL;//make free

			if (temp[ZERO] == '\n') {
				return line;
			}
			else if (temp[ZERO] == EOF) {
				return line;
			}
			else{
			line[length - ONE] = temp[ZERO];
			i++;
		}
	}
}

user* search_username(user* head,char* name, char* password, char* phone_number) {
	
	user* current = (user*)malloc(sizeof(user));
	if (current != NULL) {
		current = head;//initialized current
		while (current != NULL) {
			if ((!strcmp(current->user_name, name)) && (!strcmp(current->password, password)) && (!strcmp(current->phone_number, phone_number)))
				return current;
			else
				current = current->next;
		}
		return NULL;
	}
		else
		printf("We don't have enough memory");
	return NULL;
}

int readfile(user* head) {
	FILE* input;
input = fopen("input.txt", "r");

	user* current = (user*)malloc(sizeof(user));
	if(current!=NULL){
	current = head;
	
	char c;

	c = fgetc(input);
	if (c == EOF) {//for check EOF
		fclose(input);
		return 1;
	}
	else {
		while (c != EOF) {

			current = add_user_from_file(head);
			current->user_name = readline(input);//reading from file
			current->password = readline(input);
			current->phone_number = readline(input);
			current->Unique_ID = atoi(readline(input));
			current->cash = atoi(readline(input));
			current->number_of_transaction = atoi(readline(input));
			current->tra.transfer_to_other = atoi(readline(input));
			current->tra.transfer_to_me = atoi(readline(input));
			current->tra.admin_deposit = atoi(readline(input));
			current->tra.admin_withdraw = atoi(readline(input));


			c = fgetc(input);
		}

		fclose(input);

	}
	}
	else
		printf("We don't have enough memory");
}

int enter_user_order(user* head, user* user_0) {

	char order[20];
	int output;
	printf("\n");

	while (TRUE) {
		printf("please enter your commands %s:)\n", user_0->user_name);
		scanf_s("%s", order, sizeof(order));

		if (!strcmp(order, "logout"))
			welcome(head);
		else
			output = init_order(head, user_0, order);

		if (output == TRUE) {
			printf("\nyour command completed:)Do tou have another request?\nIf you don't have,write logout otherwise write your command\n");
			continue;
		}
		else
			printf("We don't recognize your command\n");
	}

}

int view_user(user* head, user* user_0) {
	int amount;
	int test;
	char* ptr = 0;
	printf("the name is:%s\n", user_0->user_name);
	printf("The phone number is :%s\n", user_0->phone_number);
	printf("The unique ID is :%d\n", user_0->Unique_ID);
	printf("The cash is :%d\n", user_0->cash);
	printf("The number of transactions is %d\n", user_0->number_of_transaction);
	printf("The number of transferring to other is :%d\n", user_0->tra.transfer_to_other);
	printf("The number of transfserring to me is :%d\n", user_0->tra.transfer_to_me);
	printf("The number of admin deposit  is :%d\n", user_0->tra.admin_deposit);
	printf("The number of admin withdraw is :%d\n", user_0->tra.admin_withdraw);//print user's information on command line 
	readtra(user_0);
	enter_user_order(head, user_0);
}

user* add_user_from_file(user* head) {
	user* temp = (user*)malloc(sizeof(user));
	temp = head;
	while (TRUE) {
		if (temp->next == NULL) {
			user* current = (user*)malloc(sizeof(user));
			temp->next = current;
			current->next = NULL;
			return current;
		}
		else
			temp = temp->next;
	}
	
}