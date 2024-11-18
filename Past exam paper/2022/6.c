#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int sub_move(int a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!isPrime(a[i])) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }

    int sum = 0;
    for (int i = 0; i <= j; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int a[] = {3, 5, 7, 9, 11, 13, 15, 17};
    int sum = sub_move(a, 8);
    char path[] = "result.txt";
    FILE* fp = fopen(path, "w");
    fprintf(fp, "sum=%d\n", sum);
    printf("sum=%d\n", sum);
    for (int i = 0; i < 8; i++) {
        fprintf(fp, "%d ", a[i]);
        printf("%d ", a[i]);
    }
    return 0;
}