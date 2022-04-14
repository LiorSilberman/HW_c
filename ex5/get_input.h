#ifndef GET_INPUT_H
#define GET_INPUT_H
#include <stdio.h>
#include "isValid.h"

#define SIZE_TEN 10
#define SIZE_SEVEN 7
#define SIZE_FIVE 5
#define SIZE_TWENTY 20
#define SIZE_NINE 9
#define SIZE_THREE 3


/* functions to get car details from user.
   functions to get supplier details from user.
   functions to get client details from user.*/

void get_user_input_unlimitStr(char* head, char* str);

void get_user_input_num (char input[], char* str ,int length);

int get_user_input_num_flex (char* str ,int length);

char* get_user_input_string (char* input, char* str ,int length);

int getInput_rentDate ();

int getInput_carRentTime ();

#endif