#include "isValid.h"
#include <stdlib.h>

static unsigned int allocated_blocks = 0;

void *checked_malloc(unsigned int size)
{
	void * ret;

	ret = malloc(size);
	if (!ret) {
		perror ("Memory allocation error");
		exit (1);
	}
	allocated_blocks++;
	return ret;
}
void *checked_calloc(unsigned int size1,unsigned int size2)
{
	void * ret;

	ret = calloc(size1,size2);
	if (!ret) {
		perror ("Memory allocation error");
		exit (1);
	}
	allocated_blocks++;
	return ret;
}



/* check only if alpha*/
bool isValid_alpha (char* input)
{
    while ((*input) != '\0')
    {
        if (!isalpha(*input))
        {
            return false;
        }
        input++;
    }

    return true;
}
/*functions to check input for int valid details.*/

bool isValid_intLen (const char* input, int len)
{

    if (strlen(input) != len)
    {
        return false;
    }
    while ((*input) != '\0')
    {
        if (!isdigit(*input))
        {
            return false;
        }
        input++;
    }
    return true;
}

/*functions to check input for int valid details.*/
bool isValid_intLenLimit (int num, int max_len) 
{
    int i=0;
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    if (i > max_len)
        return false;

    return true;
}

/*functions to check input for cahr* valid details.*/

bool isValid_sizeName (char* name, int len)
{
    char* p1 = name;
    
    if (strlen(name) > len)
    {
        return false;
    }
    while (*p1 != '\0')
    {
        if (!isalpha(*p1))
        {
            return false;
        }
        p1++;
    }
    return true;
}


bool isValid_rentDate (int dd , int mm , int yy) {

    /*check year*/
    if(yy>=1900 && yy<=9999)
    {
        /*check month*/
        if(mm>=1 && mm<=12)
        {
            /*check days*/
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                printf("Date is valid.\n");
            else if((dd>=1 && dd<=28) && (mm==2))
                printf("Date is valid.\n");
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                printf("Date is valid.\n");
            else
                {
                printf("Day is invalid.\n");
                return false;
                }
        }
        else
        {
            printf("Month is not valid.\n");
            return false;
        }
    }
    else
    {
        printf("Year is not valid.\n");
        return false;
    }
 
    return true;
}

bool isValid_carRentTime (int h,int m) 
{
  if((h >= 0 && h < 24) && (m >= 0 && m < 60))
    {
    printf("Valid\n");
    return true;
    }

    else
    {
    printf("Invalid\n");
    }

    return false;
}