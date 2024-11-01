#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int n) {
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    for (int i = 2; i < 100; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    return 0;
}