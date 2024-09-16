#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double fun(int i){
    if(i==1)    return 1;
    return pow(-1, i + 1) * (1.0 / i) + fun(i - 1);
}

int main() {
    printf("%f",fun(100));
    return 0;
}