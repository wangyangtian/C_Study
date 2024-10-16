#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>



int main() {
    char a[] = "134EOF";
    printf("%d",strncmp(a, "EOF", 3));
    
    return 0;
}