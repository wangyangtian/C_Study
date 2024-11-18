#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Combine(int n, int r, int comb[], int R) {
    if (r == 0) {
        for (int i = 0; i < R; i++)
            printf("%d ", comb[i]);
        printf("\n");
        return;
    }
    for (int j = n; j >= r; j--) {
        comb[r - 1] = j;
        Combine(j - 1, r - 1, comb, R);
    }
}

int main() {
    int a[10];
    Combine(5, 3, a, 3);
    return 0;
}