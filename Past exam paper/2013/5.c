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

typedef struct _Polygon {
    Point* points;
    int n;
} Polygon;

bool IsInSide(Polygon p, Point a) {
    int intersect = 0;

    for (int i = 0; i < p.n; i++) {
        double dy = p.points[(i + 1) % p.n].y - p.points[i].y;
        double dx = p.points[(i + 1) % p.n].x - p.points[i].x;

        if (dy == 0)
            continue;

        double t = p.points[i].x + dx * (a.y - p.points[i].y) / dy;

        if (t > a.x)
            intersect++;
    }

    return intersect % 2 == 1;
}

int main() {
    return 0;
}