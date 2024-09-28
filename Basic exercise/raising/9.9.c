#define _USE_MATH_DEFINES
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

Point forwardIntersection(Point A, Point B, double alpha, double beta) {
    Point P;

    // 将角度转换为弧度制
    alpha = alpha * M_PI / 180.0;
    beta = beta * M_PI / 180.0;

    // 计算 AB 的距离
    double S_AB = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    // 计算 AP 的距离
    double S_AP = S_AB * sin(beta) / sin(alpha + beta);

    // 计算 AB 的方向角
    double theta_AB = atan2(B.y - A.y, B.x - A.x);
    // 计算 AP 的方向角
    double theta_AP = theta_AB + alpha;

    // 计算 P 的坐标
    P.x = A.x + S_AP * cos(theta_AP);
    P.y = A.y + S_AP * sin(theta_AP);

    return P;
}


int main() {
    Point A = {0, 0};  // 已知点 A
    Point B = {4, 0};  // 已知点 B
    double alpha = 45; // 角 PAB
    double beta = 90;  // 角 PBA

    Point P = forwardIntersection(A, B, alpha, beta);

    printf("未知点 P 的坐标: (%.2f, %.2f)\n", P.x, P.y);

    return 0;
}