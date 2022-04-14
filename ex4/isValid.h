#ifndef IS_VALID_H
#define IS_VALID_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*functions to check input for int valid details.*/
bool isValid_intLen (const char* str, int len) ;

bool isValid_intLenLimit (int num, int max_len) ;

bool isValid_sizeName (char* name, int len);

bool isValid_rentDate (int dd , int mm , int yy);

bool isValid_carRentTime (int h,int m);

#endif