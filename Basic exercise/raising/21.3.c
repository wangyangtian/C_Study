#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double f(double x) {
    return x * x * x - 5 * x * x + 10 * x - 80;
}

int main() {
    double x1 = 0, x2 = 10;
    double root = x1 + (x2 - x1) / 2;
    double y = f(root);
    double eps = 1e-6;
    while (fabs(y) > eps) {
        if (y > 0)
            x2 = root;
        else
            x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
    }
    printf("%.8f", root);
    return 0;
}