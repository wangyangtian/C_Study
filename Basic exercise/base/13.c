#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



int main() {
    char ch[5];
    for(int i=0;i<5;i++){
        scanf("%c",&ch[i]);
    } 
    for(int i=0;i<5;i++){
        printf("%c",ch[i]+4);
        
    }
    for(int i=0;i<5;i++){
        putchar(ch[i]+4);
    }    
    
    return 0;
}