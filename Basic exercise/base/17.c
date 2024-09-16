#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPrimeNumber(int n){
    int i=sqrt(n);
    while (i!=1)
    {
        if(n%i==0)
            return false;
        i--;
    }
    return true;
}

void FilterPrimeNumber(int l,int r){
    for(int i=l;i<=r;i++){
        if(IsPrimeNumber(i))
            printf("%d ",i);
    }
}

int main() {
    FilterPrimeNumber(2,200);
    return 0;
}