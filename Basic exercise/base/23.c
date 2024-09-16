#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double fun(int n){
    double u=2;double d=1;
    if(n==1)    return u/d;
    for(int i=1;i<n;i++){
        double temp=u;
        u=u+d;
        d=temp;
    }
    return u/d;
}

int main() {
    double sum=0;
    int n=20;
    for(int i=1;i<=n;i++){
        sum+=fun(i);
    }
    printf("%f",sum);
    return 0;
}