#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Combine(int n, int r, char a[], int b[], int R) {
    if (r == 0) {
        for (int i = 0; i < R; i++) {
            printf("%c ", a[b[i]]);
        }
        printf("\n");
    } else {
        for (int j = n; j >= r; j--) {
            b[r - 1] = j - 1;
            Combine(j - 1, r - 1, a, b, R);
        }
    }
}

// 若m个数组成集合，求该集合的子集
int main() {
    int n = 4;
    char a[] = "abcd";
    int b[4];
    for (int i = 0; i < n; i++) {
        Combine(n, i, a, b, i);
    }
    return 0;
}