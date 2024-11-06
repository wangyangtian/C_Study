#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Point {
    double x;
    double y;
} Point;

double triArea(Point p1, Point p2, Point p3) {
    double v1_x = p2.x - p1.x;
    double v1_y = p2.y - p1.y;
    double v2_x = p3.x - p1.x;
    double v2_y = p3.y - p1.y;
    double area = fabs(v1_x * v2_y - v1_y * v2_x) / 2;
    return area;
}

double polygonArea(Point p[], int n) {
    double total = 0;
    for (int i = 1; i < n - 1; i++) {
        total += triArea(p[0], p[i], p[i + 1]);
    }
    return total;
}

int main() {
    return 0;
}