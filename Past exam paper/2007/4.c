#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long fun(int n) {
    if (n == 1)
        return 1;
    return n * fun(n - 1);
}

int main() {
    int n = 10;
    for (int i = 1; i <= n; i++) {
        printf("%ld ", fun(i));
    }
    return 0;
}