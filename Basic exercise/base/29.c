#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Rabbit(int n){
    if(n==1||n==2)    return 1;
    return Rabbit(n-1)+Rabbit(n-2);
}

int main() {
    
    return 0;
}