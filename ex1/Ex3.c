#include <stdio.h>
int numOccurs(long number, int digit){
     int res=0;
     while (number>0){
         if (number%10==digit){ 
             res+=1;
         }
          number/=10;
     }
     return(res);
 }

int maxOccurs(long number){
    int max=0;
    int numMax=0;
    while (number>0){
        if(numOccurs(number,number%10)>max){
            numMax=number%10;
            max=(numOccurs(number,number%10));
        }
        number/=10;
    }
    return(numMax) ;
}

 long delReverse (long number, int digit){
     int num=0;
     int rev=0;
     
    while (number>0){
        if(number%10 != digit){
        num = number % 10;
        rev = rev * 10 + num;
        } 
        number /= 10;
    }
    return (rev);
 }

void printDigits(long number){
    int res=0;
    int i=1;
    int  ans=0;
    printf("The digits are ");
    while(number>0){
        res=maxOccurs(number);
        ans=ans*10+res;
       
        number=delReverse(number,res);
        
    i*=10;
    
    printf("%d ",res);
    }
}

int main(){
    int x;
    printf("Enter a number:");
    if(scanf("%d", &x)==0 || x<0){
        printf("invalid input");
        return -1;
    }
    printDigits(x);
    return 0;
}