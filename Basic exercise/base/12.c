#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ponit {
    double x;
    double y;
} Point;

double Area(Point a, Point b, Point c) {
    double x1 = b.x - a.x;
    double y1 = b.y - a.y;
    double x2 = c.x - a.x;
    double y2 = c.y - a.y;
    double area = 0.5 * fabs(x1 * y2 - x2 * y1);
    return area;
}

int main() {
    Point a = {0, 0};
    Point b = {3, 0};
    Point c = {0, 4};
    printf("%.2f", Area(a, b, c));
    return 0;
}