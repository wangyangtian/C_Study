#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct POINT {
    double x;
    double y;
} Point;

void leastSquareLinear(Point p[], int N, double *a, double *b) {
    double t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    for (int i = 0; i < N; i++) {
        t1 += (p[i].x * p[i].y);
        t2 += p[i].x;
        t3 += p[i].y;
        t4 += (p[i].x * p[i].x);
    }

    *a = (N * t1 - t2 * t3) / (N * t4 - t2 * t2);
    *b = t3 / N - (*a) * t2 / N;
}

int main() {
    return 0;
}