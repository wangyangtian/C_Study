#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} Point;

// 计算叉积crossProduct
float cp(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool IsIntersecting(Point p1, Point p2, Point q1, Point q2) {
    // 快速排斥实验
    if (fmax(p1.x, p2.x) < fmin(q1.x, q2.x) ||
        fmax(q1.x, q2.x) < fmin(p1.x, p2.x) ||
        fmax(p1.y, p2.y) < fmin(q1.y, q2.y) ||
        fmax(q1.y, q2.y) < fmin(p1.y, p2.y))
        return false;

    // 判断叉积是否异号，确保 p1p2 在 q1q2 两侧，并且 q1q2 在 p1p2 两侧
    float d1 = cp(q1, q2, p1);
    float d2 = cp(q1, q2, p2);
    float d3 = cp(p1, p2, q1);
    float d4 = cp(p1, p2, q2);

    if (d1 * d2 < 0 && d3 * d4 < 0) {
        return true;  // 线段相交
    }
    return false;
}
int main() {
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 4.0};
    Point q1 = {0.0, 4.0};
    Point q2 = {4.0, 0.0};

    if (IsIntersecting(p1, p2, q1, q2)) {
        printf("The segments intersect.\n");
    } else {
        printf("The segments do not intersect.\n");
    }

    return 0;
}