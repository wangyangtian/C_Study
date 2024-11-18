#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(int n) {
    for (int i = 1; i <= n; i++) {
        int total = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0)
                total += j;
        }
        if (total == i) {
            printf("%d ", i);
        }
    }
}

int main() {
    fun(1000);
    return 0;
}