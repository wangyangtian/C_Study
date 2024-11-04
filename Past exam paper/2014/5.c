#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void fun(int n, int factor) {
    if (n > 1) {
        if (n % factor == 0) {
            printf("%d", factor);
            if (!isPrime(n)) {
                printf("*");
            }
            fun(n / factor, factor);
        } else {
            fun(n, factor + 1);
        }
    }
}

int main() {
    fun(2025, 2);
    return 0;
}