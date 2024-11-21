#include <stdio.h>
#include <stdlib.h>

int *merge(const int a[], int len_a, const int b[], int len_b) {
    int len = len_a + len_b;
    int *c = (int *)malloc(sizeof(int) * len);

    int i = len_a - 1, j = len_b - 1, k = 0;
    while (i >= 0 && j >= 0) {
        if (a[i] > b[j]) {
            c[k++] = a[i--];
        } else {
            c[k++] = b[j--];
        }
    }
    while (i >= 0) {
        c[k++] = a[i--];
    }
    while (j >= 0) {
        c[k++] = b[j--];
    }
    return c;
}

int main() {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};
    int len_a = sizeof(a) / sizeof(a[0]);
    int len_b = sizeof(b) / sizeof(b[0]);

    int *result = merge(a, len_a, b, len_b);
    if (result != NULL) {
        for (int i = 0; i < len_a + len_b; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);  // 释放分配的内存
    }

    return 0;
}
