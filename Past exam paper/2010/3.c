#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float root(double x1, double x2) {
    double xm = (x1 + x2) / 2;
    double eps = 1E-6;
    if (fabs(2 * xm * xm * xm - 4 * xm * xm + 3 * xm - 6) < eps)
        return xm;

    if (2 * xm * xm * xm - 4 * xm * xm + 3 * xm - 6 > 0)
        root(x1, xm);
    else
        root(xm, x2);
}

int main() {
    printf("%lf", root(-10, 10));
    return 0;
}