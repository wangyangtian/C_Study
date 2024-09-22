#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int gcd(int a ,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int gcd2(int a ,int b){
    while (true)
    {
        if(a>b)
            a-=b;
        else if(a<b)
            b-=a;
        else
            return a;
    }
    
}

int main() {
    
    return 0;
}