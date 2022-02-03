#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define INVALID -1
#define VALID 1
#define ZERO 0
#define ONE 1



typedef struct Admin {
	char* name;
	char* password;
	char* phone_number;
}admin;

typedef struct Transactions {
	int transfer_to_other;
	int transfer_to_me;
	int admin_deposit;
	int admin_withdraw;
}transactions;

typedef struct User {
	char* user_name;
	char* password;
	int * phone_number;
	int   Unique_ID;
	int   cash;
	int   number_of_transaction;
	transactions tra;
	struct User*next;
}user;

user* init_head(user*head);

user* search_username(user*head, char* name, char* password, char* phone_number);

void welcome(user* head);

int login(admin* manager , user* head ,char* name, char* password, char* phone_number);

int enter_user_order(user* head, user* user_0);

int enter_admin_orders(user* head);

int init_order_admin(user* head,char*order);

int init_order(user* head, user* user_0, char*order);

int add_user(user* head,char* name, char* password, char* phone_number);

int deleting (user* head, char* name);

int view(user* head, char* name);

int deposit(user* head, char* name, int amount);

int withdraw(user* head, char* name, int amount);

int view_user(user* head, user* user_0);

int transfer(user* head, user*user_0, char*name, int amount);

int write(user*new_user, FILE* input);

int readtra(user* current);

char* readline(FILE*information);

int readfile( user* head);

user* add_user_from_file(user* head);
