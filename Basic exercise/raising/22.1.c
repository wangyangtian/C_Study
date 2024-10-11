#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

void enums(char *s,int n){
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++){
            for (int k = j + 1; k < n;k++){
                printf("%c %c %c\n", s[i], s[j], s[k]);
            }
        }
    }
}

int main() {
    char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    enums(s, 7);
    return 0;
}