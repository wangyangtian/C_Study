#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point, Vector;

typedef struct {
    Point start;
    Point end;
} Line;

int cross(Vector v1, Vector v2) {
    return v1.x * v2.y - v2.x * v1.y;
}

bool isInersect(Line l1, Line l2) {
    if (__max(l1.end.x, l1.start.x) < __min(l2.end.x, l1.start.x) ||
        __min(l1.end.x, l1.start.x) > __max(l2.end.x, l1.start.x) ||
        __max(l1.end.y, l1.start.y) < __min(l2.end.y, l1.start.y) ||
        __min(l1.end.y, l1.start.y) > __max(l2.end.y, l1.start.y))
        return false;

    Vector v1, v2, v3, v4;
    v1.x = l2.end.x - l1.start.x;
    v1.y = l2.end.y - l1.start.y;
    v2.x = l2.start.x - l1.start.x;
    v2.y = l2.start.y - l1.start.y;
    v3.x = l1.end.x - l2.start.x;
    v3.y = l1.end.y - l2.start.y;
    v4.x = l1.start.x - l2.start.x;
    v4.y = l1.start.y - l2.start.x;
    return (cross(v1, v2) < 0) && (cross(v3, v4) < 0);
}

int main() {
    return 0;
}