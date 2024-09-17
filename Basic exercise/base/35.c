#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintRhombus(int n) {
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= n; j++) {
            if ((j >= n / 2 - i) && (j <= n / 2 + i))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            if ((j <= i) || (j >= n - i - 1))
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n = 11;
    PrintRhombus(n);
    return 0;
}