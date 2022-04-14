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


bool isValid_rentDate (char* date)
{
    if (date[0] > 51)
    {
        return false;
    }

    if (date[0] == 51 && date[1] > 49)
    {
        return false;
    }

    if (date[3] >= 50)
    {
        return false;
    }

    if (date[3] == 49 && date[4] > 50)
    {
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