#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {  //(x,y)
    double x;
    double y;
} Point;

bool isInLine(Point p, Point a, Point b) {
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = b.x * a.y - a.x * b.y;
    double res = A * p.x + B * p.y + C;
    return res == 0;
}

int main() {
    return 0;
}