#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char encrypt (unsigned char ch, unsigned int key)
{
    ch = ch + 32 + (key%26);
    if (ch > 122)
    {
        ch = ch - 26;
    }
    return ch;
}

char decrypt (unsigned char ch, unsigned int key){
    ch = ch - 32 - (key%26);
    if (ch < 65){
        ch = ch + 26;
    }
    return ch;
}


int main()
{
    int key, i;
    char str[100];
    
    
    printf("Enter encryption key:\n");
    if(scanf("%d", &key)==0){
        printf("invalid inpit: only number can be used");
        return -1;
    }
    else{
    printf("Enter string of capital letters:\n");
    scanf("%s", str);
    for(i=0;i<strlen(str);i++){
        if (str[i] < 65 || str[i] > 90){
            printf("\nInvalid input: only capital letters can be used\n");
            return -1;
        }
        
        printf("%c", encrypt(str[i], key));
    }
    return 0;
    }
    
}