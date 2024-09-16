#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool IsPrimeNumber(int n){
    if (n <= 1) return false;  // 1及以下的数不是素数
    for (int i = 2; i <= sqrt(n); i++) {  // 遍历到sqrt(n)
        if (n % i == 0) 
            return false;  // 有因数，非素数
    }
    return true;
}

int main() {
    printf("%d",IsPrimeNumber(13));
    return 0;
}