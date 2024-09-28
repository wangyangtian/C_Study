#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
}Point;


typedef struct Circle
{
    Point center;
    double r;
}Circle;

typedef struct Polygon
{
    Point *vertex;
    int VNum;
}Polygon;

bool IsInCircle(Polygon p, Circle c) {
    for (int i = 0; i < p.VNum; i++) {
        // 计算多边形顶点与圆心的距离
        double distance = sqrt((p.vertex[i].x - c.center.x) * (p.vertex[i].x - c.center.x) +(p.vertex[i].y - c.center.y) * (p.vertex[i].y - c.center.y));
        // 如果距离大于圆的半径，返回 false
        if (distance > c.r)
            return false;
    }
    return true;  // 所有顶点都在圆内
}

int main() {
    // 定义一个圆，圆心(0, 0)，半径5
    Circle c = {{0, 0}, 5};

    // 定义一个三角形多边形，顶点为(1, 1), (2, 2), (3, 3)
    Polygon p;
    p.VNum = 3;
    p.vertex = (Point*)malloc(p.VNum * sizeof(Point));
    p.vertex[0] = (Point){1, 1};
    p.vertex[1] = (Point){2, 2};
    p.vertex[2] = (Point){3, 3};

    // 判断该多边形是否在圆内
    if (IsInCircle(p, c)) {
        printf("多边形在圆内\n");
    } else {
        printf("多边形不在圆内\n");
    }

    free(p.vertex);  // 释放动态分配的内存
    return 0;
}
