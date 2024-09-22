#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float area(Point p1, Point p2, Point p3) {
    float s = fabs((p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y)) / 2.0;
    return s;
}

int main() {
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 0.0};
    Point p3 = {0.0, 3.0};

    float result = area(p1, p2, p3);
    printf("The area of the triangle is: %.2f\n", result);

    return 0;
}
