#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}
int Sum(int n){
    if(n==1) return factorial(n);
    return factorial(n)+Sum(n-1);
}

int main() {
    printf("%d",Sum(3));
    return 0;
}

