#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

// 判断点q是否在p1和p2形成的直线上
int isPointOnLine(Point p1, Point p2, Point q) {
    // 计算叉积，如果叉积为0，则共线
    float crossProduct = (p2.x - p1.x) * (q.y - p1.y) - (q.x - p1.x) * (p2.y - p1.y);
    
    if (crossProduct == 0.0) {
        return 1; // 在直线上
    } else {
        return 0; // 不在直线上
    }
}

int main() {
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 4.0};
    Point q = {2.0, 2.0};
    
    if (isPointOnLine(p1, p2, q)) {
        printf("Point q is on the line formed by p1 and p2.\n");
    } else {
        printf("Point q is not on the line formed by p1 and p2.\n");
    }
    
    return 0;
}
