#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct _Point{
    double x;
    double y;
} Point;

bool IsCross(Point a1,Point a2,Point p){
    if(a1.y==a2.y)
        return false;

    double x_intersection = a1.x + (p.y - a1.y) / (a2.y - a1.y) * (a2.x - a1.x);
    return x_intersection > p.x;
}

bool IsInPolygon(Point* polygon,int n,Point p){
    int count = 0;
    for (int i = 0; i < n;i++){
        if(IsCross(polygon[i],polygon[(i+1)%n],p))
            count++;
    }
    return count % 2 == 1;
}

int main() {
    // 定义一个四边形
    Point polygon[] = {{1.0, 1.0}, {5.0, 1.0}, {5.0, 5.0}, {1.0, 5.0}};
    int   n         = sizeof(polygon) / sizeof(polygon[0]);

    // 定义要检查的点
    Point q  = {3.0, 3.0}; // 内部点
    Point q2 = {6.0, 3.0}; // 外部点

    // 检查点是否在多边形内部
    if (IsInPolygon(polygon, n, q)) {
        printf("Point q is inside the polygon.\n");
    } else {
        printf("Point q is outside the polygon.\n");
    }

    if (IsInPolygon(polygon, n, q2)) {
        printf("Point q2 is inside the polygon.\n");
    } else {
        printf("Point q2 is outside the polygon.\n");
    }

    return 0;
}