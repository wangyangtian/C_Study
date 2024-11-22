#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

int main() {
    int a[] = {1, 3, 5, 7, 2, 4, 6, 8};
    sort(a, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}