#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* Insert(int* a, int len, int pos, int elem) {
    int* b = (int*)malloc(sizeof(int) * (len + 1));
    for (int i = 0; i < pos; i++) {
        b[i] = a[i];
    }
    for (int i = pos; i < len; i++) {
        b[i + 1] = a[i];
    }
    b[pos] = elem;
    return b;
}

int main() {
    int a[] = {5, 3, 6, 2, 1};
    int* b = Insert(a, 5, 2, 2);
    for (int i = 0; i < 6; i++) {
        printf("%d ", b[i]);
    }
    free(b);
    return 0;
}