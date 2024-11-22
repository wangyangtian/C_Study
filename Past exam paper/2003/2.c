#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void printDoublePrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i) && isPrime(i + 2))
            printf("%d 是双素数\n", i);
    }
}

int main() {
    printDoublePrime(300);
    return 0;
}