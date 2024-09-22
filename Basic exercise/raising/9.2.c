#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float area(Point p1, Point p2, Point p3) {
    float s = fabs((p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y)) / 2.0;
    return s;
}

float polygonArea(Point points[],int n){
    float s=0;
    for(int i=0;i<n-1;i++){
        s+=area(points[0],points[i],points[i+1]);
    }
    return s;
}

int main() {
    Point polygon[] = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 3.0},
        {0.0, 3.0}
    };
    int n = sizeof(polygon) / sizeof(polygon[0]);

    float area = polygonArea(polygon, n);
    printf("The area of the polygon is: %.2f\n", area);

    return 0;
}