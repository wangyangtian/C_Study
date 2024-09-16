#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int Cumsum(int i){
    if(i==1)    return 1;
    return (i+Cumsum(i-1));
}

int main() {
    printf("%d",Cumsum(100));
    return 0;
}