#include <stdio.h>
int main(){
    int k,j,i;
    for(k=2;k<100;k++){
        for (j=k;j<100;j++){
            for(i=j;i<100;i++){
                if (i*i==j*j+k*k){
                printf("%d^2 = %d^2 + %d^2\n",i,k,j);
                }
            }
        }
    }
    return 0;
}