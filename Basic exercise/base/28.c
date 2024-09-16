#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Fibonacci(int n){
    if(n==0)    return 0;
    if(n==1)    return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main() {
    for(int i=0;i<20;i++){
        printf("%d ",Fibonacci(i));
    }
    
    return 0;
}