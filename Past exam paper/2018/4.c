#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 重力加速度
#define g 9.8
// 阻力系数
#define c 1
// 物体质量
#define m 1

// 定义结构体Point和Vector用于表示位置和速度的坐标
typedef struct {
    double x;
    double y;
} Point, Vector;

// 轨迹绘制函数，模拟物体在空气阻力作用下的运动轨迹
void drawingTrack(Point p0, Vector v0) {
    // 时间步长
    double dt = 0.01;
    // 初始化位置坐标
    double pxt = p0.x;
    double pyt = p0.y;
    // 初始化速度
    double vxt = v0.x;
    double vyt = v0.y;

    // 当物体高度未低于地面时，循环计算轨迹点
    while (pyt >= 0) {
        // 计算x方向的加速度，注意空气阻力与速度方向相反
        double ax = -(c * vxt * fabs(vxt)) / m;
        // 计算y方向的加速度，包括重力和空气阻力
        double ay = -(c * vyt * fabs(vyt) + m * g) / m;

        // 更新速度：v = v0 + at
        vxt = vxt + ax * dt;
        vyt = vyt + ay * dt;

        // 更新位置：p = p0 + vt
        pxt = pxt + vxt * dt;
        pyt = pyt + vyt * dt;

        // 输出当前坐标点
        printf("(%.3lf,%.3lf),", pxt, pyt);
    }
}

int main() {
    // 定义初始位置
    Point p0 = {0.0, 0.0};
    // 定义初始速度
    Vector v0 = {10.0, 10.0};
    // 调用函数绘制轨迹
    drawingTrack(p0, v0);
    return 0;
}
