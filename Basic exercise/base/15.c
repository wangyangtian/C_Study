#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int pow2N(int n){
    if(n==1)return 2;
    return pow2N(n-1)*2;
}

int main() {
    printf("%d",pow2N(10));
    return 0;
}