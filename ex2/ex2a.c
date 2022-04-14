#include <stdio.h>
#include <ctype.h>

void swap (char* lhs, char* rhs)
{
    char temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}


void reorderArray (char* arr, int size)
{
    char *p1 = arr; 
    char *p2 = arr + (size - 1);
    while (p1 != p2)
    {

        /* p1 is letter? */
        if (isalpha(*p1))
        {
            p1++;
            continue;
        }
        
        /* p2 is letter? swap*/
        if (isalpha(*p2))
        {
            swap(p1, p2);
            p1++;
        }
        else
        {
            p2--;
        }
    }

    p2 = arr + (size - 1);
    
    while (p1 != p2)
    {
        /* p1 is dijit? */
        if (isdigit(*p1))
        {
            p1++;
            continue;
        }

        /*p2 is digit?*/
        if (isdigit(*p2))
        {
            swap(p1, p2);
            p1++;
        }
        else
        {
            p2--;
        }
    }
}

int main ()
{
    int size = 13;
    char arr[13] = {'s','5','=','r','1','!','t','T','y','9','@','>','4'};
    reorderArray(arr, size);
    printf("%s", arr);

    return 0;
}
