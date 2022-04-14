#include <stdio.h>
#include <math.h>
#include <ctype.h>
int intFactorial (int num){
    int fact=1;
    int i;
    for ( i=2;i<=num;i++){
        fact*=i;
    }
        return(fact);
        return 0;
}

float taylorColumn(float x){
    float res=0;
    
    int i=0;
    while (i<=9){
        res+=(pow((-1),i)/intFactorial(2*i+1))*pow(x,(2*i+1));
        i++;
    }
    
    return res;
}
        
int main(){
    float x;
    printf("Enter a number in radian: ");
    if(scanf("%f", &x)==0){
         printf("invalid input");
         return -1;
    }
    else{
    printf("sin(%f) is: %f",x*180/3.14159265358979323846,taylorColumn(x));
    return 0;
    }
}
