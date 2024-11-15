#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

int main() {
    double ax1, ax2, ay1, ay2, bx1, bx2, by1, by2;
    printf("输入第一个矩形的左上点坐标和右下角坐标\n");
    scanf("%lf %lf %lf %lf", &ax1, &ay1, &ax2, &ay2);
    printf("输入第二个矩形的左上点坐标和右下角坐标\n");
    scanf("%lf %lf %lf %lf", &bx1, &by1, &bx2, &by2);

    // 计算交集区域的坐标
    double x1 = max(ax1, bx1);  // 交集区域的左边界
    double x2 = min(ax2, bx2);  // 交集区域的右边界
    double y1 = min(ay1, by1);  // 交集区域的上边界
    double y2 = max(ay2, by2);  // 交集区域的下边界

    // 判断是否有交集
    if (x1 < x2 && y1 > y2) {
        double area = (x2 - x1) * (y1 - y2);  // 计算交集的面积
        printf("相交面积为%.2lf\n", area);
    } else {
        printf("矩形不相交\n");
    }

    return 0;
}