#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

// 判断射线是否与多边形的边相交
bool isIntersecting(Point p1, Point p2, Point q) {
    // 确保p1, p2是多边形的一条边，q是要判断的点
    if (p1.y == p2.y)
        return false;  // 水平边不可能相交

    if (q.y < fmin(p1.y, p2.y) || q.y > fmax(p1.y, p2.y))
        return false;  // 射线没有穿过边

    float x_intersect = p1.x + (q.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);

    return x_intersect > q.x;  // 交点在射线右侧
}

// 判断点是否在多边形内部
bool isPointInsidePolygon(Point polygon[], int n, Point q) {
    int intersections = 0;

    for (int i = 0; i < n; i++) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];  // 处理最后一个点与第一个点的连线

        if (isIntersecting(p1, p2, q)) {
            intersections++;
        }
    }

    // 如果交点数量是奇数，点在多边形内部；偶数则在外部
    return intersections % 2 == 1;
}

int main() {
    // 定义一个四边形
    Point polygon[] = {{1.0, 1.0}, {5.0, 1.0}, {5.0, 5.0}, {1.0, 5.0}};
    int n = sizeof(polygon) / sizeof(polygon[0]);

    // 定义要检查的点
    Point q = {3.0, 3.0};   // 内部点
    Point q2 = {6.0, 3.0};  // 外部点

    // 检查点是否在多边形内部
    if (isPointInsidePolygon(polygon, n, q)) {
        printf("Point q is inside the polygon.\n");
    } else {
        printf("Point q is outside the polygon.\n");
    }

    if (isPointInsidePolygon(polygon, n, q2)) {
        printf("Point q2 is inside the polygon.\n");
    } else {
        printf("Point q2 is outside the polygon.\n");
    }

    return 0;
}
