#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double factorial(int n){
    if(n==0)    return 1;
    return n*factorial(n-1);
}

double NuturalBase(int n){
    if(n==0)    return factorial(0);
    return 1/factorial(n)+NuturalBase(n-1);
}


int main() {
    int n=1;
    while (1/factorial(n)>pow(10,-10)){
        n++;
    }
     printf("%.10lf",NuturalBase(n));
    return 0;
}