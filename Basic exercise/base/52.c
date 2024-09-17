#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float f(float x){
    return x*x*x+3*x*x-x+2;
}

float Integral(float a,float b,int n){//范围a~b,分为n份
    float deltaX=(b-a)/n;
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=(f(a+i*deltaX)+f(a+(i+1)*deltaX))*deltaX/2;
    }
    return sum;
}

int main() {
    printf("%f",Integral(1,2,100));
    return 0;
}