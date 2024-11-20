#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    double x;
    double y;
} Point;

void Line(Point a, Point b, double *A, double *B, double *C) {
    *A = b.y - a.y;
    *B = a.x - b.x;
    *C = b.x * a.y - a.x * b.y;
}

int pointInLine(Point *p, int m) {
    int maxCount = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            int count = 0;
            double A, B, C;
            Line(p[i], p[j], &A, &B, &C);

            for (int k = 0; k < m; k++) {
                if (fabs(A * p[k].x + B * p[k].y + C) < 1e-6)
                    count++;
            }
            if (count > maxCount)
                maxCount = count;
        }
    }
    return maxCount;
}

int main() {
    Point p[] = {{0, 0}, {1, 1}, {0, 1}, {1, 0}, {2, 2}, {3, 3}};
    int maxNum = pointInLine(p, 6);
    printf("%d", maxNum);
    return 0;
}