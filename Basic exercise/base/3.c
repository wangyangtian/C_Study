#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void IsLeapYear(){
    for(int i=2000;i<=2500;i++){
        if((i%4==0&&i%100!=0)||(i%400==0))
            printf("%d ",i);
    }
}

int main() {
    IsLeapYear();
    return 0;
}