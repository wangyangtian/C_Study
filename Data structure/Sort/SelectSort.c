#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main() {
    int a[] = {5, 3, 1, 6, 2, 8, 4};
    SelectSort(a, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}