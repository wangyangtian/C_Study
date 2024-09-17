#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPrime(int n){
    if (n <= 1) return false;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

bool IsTwinPrime(int n){
    if(IsPrime(n)&&IsPrime(n+2))
        return true;
    return false;
}

int main() {
    for(int i=3;i<=1000;i++){
        if(IsTwinPrime(i))
            printf("%d--%d ,",i,i+2);
    }
    return 0;
}