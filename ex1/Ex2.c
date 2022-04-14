#include <stdio.h>
#include <ctype.h>
int maxDigit (unsigned int num)
{
    int max_digit = 0;
    while (num > 0)
    {
        int i = num % 10;
        if (i > max_digit)
            max_digit = i;
        num /= 10;
    }
    return max_digit;
}

int delMax (unsigned int num)
{
    int max;
    int x=0;
    int i=1;
    max=maxDigit(num);
    while (num>0)
    {
        if (num%10!=max){
            x+=num%10*i;
            i*=10;
        }
        num /= 10;
    }
    return x;
}


int main()
{
    int num;
    printf("Enter a positive int number: ");
    if(scanf("%d" , &num)==0 || num<0 ){
        printf("invalid input");
        return -1;
    }
    else{
        printf("the new number is: %d\n",delMax(num)); 
        return 0;
    }
    
}