#include <stdio.h>
#include <string.h>

void swap (char* lhs, char* rhs)
{
    char temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

void reverseArray (char* arr, int len)
{  

    char* p_start = arr;
    char* p_end = arr + (len-1);

    if (len >= 2)
    {
        swap(p_start, p_end);
        reverseArray(++p_start, len-2);
    }
}

void insertLength(char arr[], int x)
{
    char arrLen = strlen(arr);
    if (arr[x] == '\0')
    {
        return;
    }
    if (arr[x]==' ')
    {
       arr[x]=arrLen;
    }
    x++;
    insertLength(arr,x);
}

int main()
{
    char arr[] = "12345";
    char str[] = "The book is on the table , and the table is red";

    reverseArray(arr,5);
    insertLength(str,2);
    printf("%s\n",str);
    return 0;
}