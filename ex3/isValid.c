#include "isValid.h"

/*functions to check input for int valid details.*/
int isValid_intLen (int num, int len) 
{
    int i=0;
    
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    if (i != len)
        {
            return 0;
        }
    return 1;
}

/*functions to check input for cahr* valid details.*/

int isValid_sizeName (char* name, int len)
{
    int i;
    char* p1 = name;
    
    if (strlen(name) > len)
    {
        return 0;
    }
    for (i=0; i<strlen(name); i++)
    {
        if (!isalpha(*p1))
        {
            return 0;
        }
        p1++;
    }
    return 1;
}

int isValid_exactName (char* name, int len)
{
    int i;
    char* p1 = name;
    
    if (strlen(name) != len)
    {
        return 0;
    }
    for (i=0; i<strlen(name); i++)
    {
        if (!isalpha(*p1))
        {
            return 0;
        }
        p1++;
    }
    return 1;
}

int isValid_maxSize (int price) 
{
	int i=0;
    
    while (price > 0)
    {
        /*int digit = price%10;						 לטפל בהמשך*/

        price /= 10;
        i++;
    }
    if (i > 7)
        {
            return 0;
        }
    return 1;
}


/*functions to check input for supplier details.*/


/*functions to check input for client details.*/


int isValid_rentDate (int date) {return 1;}

int isValid_carRentTime (int time) {return 1;}

int isValid_supplierPrice (int price){return 1;}

int isValid_currentPrice (int price){return 1;}
