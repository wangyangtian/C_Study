#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsIntact(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
            sum+=i;
    }
    return sum==n;
}

int main() {
    for(int i=2;i<=300;i++){
        if(IsIntact(i))
            printf("%d ",i);
    }
    return 0;
}