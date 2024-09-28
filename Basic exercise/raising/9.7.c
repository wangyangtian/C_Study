#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    double x;
    double y;
} Point;

Point centroid(Point a, Point b, Point c) {
    double x = (a.x + b.x + c.x) / 3;
    double y = (a.y + b.y + c.y) / 3;
    Point centroid;
    centroid.x = x;
    centroid.y = y;
    return centroid;
}

double triangleArea(Point a, Point b, Point c) {
    double s = fabs((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x));
    return s;
}

Point polygonCenter(Point points[], int n) {
    Point pc = {0, 0};  // 初始化多边形中心
    double sumS = 0;     // 多边形面积的总和

    for (int i = 1; i < n - 1; i++) {
        Point triCentroid = centroid(points[0], points[i], points[i + 1]);
        double area = triangleArea(points[0], points[i], points[i + 1]);
        sumS += area;
        pc.x += triCentroid.x * area;
        pc.y += triCentroid.y * area;
    }

    // 除以总面积得到加权后的多边形中心
    pc.x /= sumS;
    pc.y /= sumS;

    return pc;
}

int main() {
    // 测试多边形中心计算
    Point polygon[] = {
        {0, 0},
        {4, 0},
        {4, 3},
        {0, 3}
    };
    int n = sizeof(polygon) / sizeof(polygon[0]);

    Point center = polygonCenter(polygon, n);
    printf("Polygon Center: (%.2f, %.2f)\n", center.x, center.y);

    return 0;
}