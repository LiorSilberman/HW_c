
#include "get_input.h"

/* functions to get car details from user.*/

void get_user_input_unlimitStr(char* head, char* str)
{
	char name[100];
	
	do{
		printf("%s", str);
		scanf("%s",name);
	}
	while (!isValid_alpha (name));

	head = ALLOC(char, strlen(name)+1);
	strcpy(head, name);
}

void get_user_input_num (char* input, char* str ,int length)
{

	do{
		printf("%s\n", str);
		scanf("%s",input);
	}

	while (!isValid_intLen (input, length));
}

char* get_user_input_string (char* input, char* str ,int length)
{
	
	do{
		printf("%s\n", str);
		scanf("%s", input);
	}
	while (!isValid_sizeName (input, length));
	
	return input;
	
}

int get_user_input_num_flex (char* str ,int max_length)
{
	int input;
	
	do{
		printf("%s\n", str);
		scanf("%d",&input);
	}
	while (!isValid_intLenLimit (input, max_length));
	
	return input;
	
}

int getInput_rentDate()
{
	int dd,mm,yy;
	do{
	printf("Enter date (DD/MM/YYYY format): ");
    scanf("%2d/%2d/%4d",&dd,&mm,&yy);
	}
	while (!isValid_rentDate (dd,mm,yy));
	
	return 1;
}

int getInput_carRentTime ()
{
	int hour,minute;
	do{
	printf("Enter time (HH:MM format): ");
    scanf("%2d:%2d",&hour, &minute);
	}

	while (!isValid_carRentTime (hour, minute));
	
	return 0;
}