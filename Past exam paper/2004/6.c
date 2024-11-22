#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int r[], int n) {
    if (n == 1)
        return r[0];
    return max(r, n - 1) > r[n - 1] ? max(r, n - 1) : r[n - 1];
}

int sum(int r[], int n) {
    if (n == 1)
        return r[0];
    return r[n - 1] + sum(r, n - 1);
}

double avg(int r[], int n) {
    if (n == 1)
        return r[0];
    else
        return (r[n - 1] + avg(r, n - 1) * (n - 1)) / n;
}

int main() {
    int a[] = {1, 2, 3, 5, 4};
    printf("%d\n", max(a, 5));
    printf("%d\n", sum(a, 5));
    printf("%.2lf\n", avg(a, 5));
    return 0;
}