#ifndef IS_VALID_H
#define IS_VALID_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define ALLOC(typ,no) ((typ *) checked_malloc(no))
#define ACLLOC(typ,no1,no2) ((typ *) checked_calloc(no1,no2))


/*functions to check input for int valid details.*/
void *checked_malloc(unsigned int size);
void *checked_calloc(unsigned int size1,unsigned int size2);
bool isValid_intLen (const char* str, int len);

bool isValid_alpha (char* input);

bool isValid_intLenLimit (int num, int max_len) ;

bool isValid_sizeName (char* name, int len);

bool isValid_rentDate (char* date);

bool isValid_carRentTime (int h, int m);

#endif