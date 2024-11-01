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

typedef struct _Circle {
    Point center;
    double r;
} Circle;

typedef struct _Polygon {
    Point p[4];
} Polygon;

bool isInCircle(Circle c, Polygon t) {
    for (int i = 0; i < 4; i++) {
        double dx = t.p[i].x - c.center.x;
        double dy = t.p[i].y - c.center.y;
        double d = sqrt(dx * dx + dy * dy);
        if (d >= c.r)
            return false;
    }
    return true;
}

int main() {
    return 0;
}