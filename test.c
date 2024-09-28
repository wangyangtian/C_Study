#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct Point {
    double x;
    double y;
} Point;

Point forwardIntersection(Point A, Point B, double alpha, double beta) {
    Point P;
    
    // 将角度转换为弧度制
    alpha = alpha * PI / 180.0;
    beta = beta * PI / 180.0;

    // 计算 AB 的距离
    double AB = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));

    // 利用正弦定理计算 PA 和 PB
    double PA = (AB * sin(beta)) / sin(alpha + beta);
    double PB = (AB * sin(alpha)) / sin(alpha + beta);

    // 计算向量方向
    double dx = B.x - A.x;
    double dy = B.y - A.y;

    // 计算点 P 的坐标 (利用 PA，PB 比例确定 P 在 AB 线上的位置)
    P.x = A.x + (dx * PA) / AB;
    P.y = A.y + (dy * PA) / AB;

    return P;
}

int main() {
    Point A = {0, 0};  // 已知点 A
    Point B = {4, 0};  // 已知点 B
    double alpha = 30; // 角 PAB
    double beta = 45;  // 角 PBA

    Point P = forwardIntersection(A, B, alpha, beta);

    printf("未知点 P 的坐标: (%.2f, %.2f)\n", P.x, P.y);

    return 0;
}
