#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

double getMiddle(int a[], int n) {
    BubbleSort(a, n);
    if (n % 2 == 0)
        return (a[n / 2 - 1] + a[n / 2]) / 2.0;
    else
        return a[n / 2];
}

int main() {
    int a[] = {1, 3, 5, 7, 2, 4, 6, 8};
    printf("%.2lf", getMiddle(a, 8));
    return 0;
}