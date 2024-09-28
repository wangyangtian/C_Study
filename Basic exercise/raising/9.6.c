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

Point centroid(Point a,Point b,Point c){
    double x=(a.x+b.x+c.x)/3;
    double y=(a.y+b.y+c.y)/3;
    Point centroid;
    centroid.x=x;
    centroid.y=y;
    return centroid;
}

int main() {
    // 创建三个点
    Point p1 = {0, 0};
    Point p2 = {3, 0};
    Point p3 = {0, 4};

    // 计算重心
    Point center = centroid(p1, p2, p3);

    // 输出结果
    printf("Centroid: (%.2f, %.2f)\n", center.x, center.y);

    return 0;
}