#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double getDist(int x1, int y1, int x2, int y2, int px, int py) {
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;

    double d = fabs(A * px + B * py + C) / sqrt(A * A + B * B);
    return d;
}

void DP(double *x, double *y, int left, int right, int epsilon) {
    if (right - left <= 1)
        return;
    else {
        double maxDist = 0;
        int index = -1;
        for (int i = left; i <= right; i++) {
            double dist = getDist(x[left], y[left], x[right], y[right], x[i], y[i]);
            if (dist >= maxDist) {
                maxDist = dist;
                index = i;
            }
        }

        if (maxDist < epsilon) {
            for (int i = left + 1; i <= right - 1; i++) {
                x[i] = -1;
                y[i] = -1;
            }
        } else {
            DP(x, y, left, index, epsilon);
            DP(x, y, index, right, epsilon);
        }
    }
}

int main() {
    return 0;
}