#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
1. 从要判断的点𝑄(𝑥𝑞,𝑦𝑞)向任意方向发射一条射线（通常向右），然后统计射线与多边形边的交点数量。
2. 如果射线与多边形边交点的次数是奇数，则点在多边形内部；如果是偶数，则点在多边形外部。
*/

typedef struct Point
{
    float x;
    float y;
}Point;

// 判断射线是否与多边形的边相交
bool IsIntersecting(Point p1,Point p2,Point q){
    if(p1.y==p2.y)  
        return false;
    if(q.y<fmin(p1.y,p2.y)||q.y>fmax(p1.y,p2.y))
        return false;
    float x_intersect=p1.x+(p2.x-p1.x)*(q.y-p1.y)/(p2.y-p1.y);
    // x_intersect>q.x,交点在射线右侧
    return x_intersect>q.x;
}

// 判断点是否在多边形内部
bool IsInpolygon(Point polygon[],int n,Point q){
    int intersections = 0;
    for(int i=0;i<n;i++){
        // 注意处理最后一个点与第一个点的连线
        if(IsIntersecting(polygon[i],polygon[(i+1)%n],q))
            intersections++;
    }
    return intersections%2==1;
}

int main() {
    // 定义一个四边形
    Point polygon[] = {
        {1.0, 1.0}, {5.0, 1.0}, {5.0, 5.0}, {1.0, 5.0}
    };
    int n = sizeof(polygon) / sizeof(polygon[0]);

    // 定义要检查的点
    Point q = {3.0, 3.0}; // 内部点
    Point q2 = {6.0, 3.0}; // 外部点

    // 检查点是否在多边形内部
    if (IsInpolygon(polygon, n, q)) {
        printf("Point q is inside the polygon.\n");
    } else {
        printf("Point q is outside the polygon.\n");
    }

    if (IsInpolygon(polygon, n, q2)) {
        printf("Point q2 is inside the polygon.\n");
    } else {
        printf("Point q2 is outside the polygon.\n");
    }

    return 0;
}