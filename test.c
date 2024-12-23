#include <stdio.h>
#include <stdlib.h>

typedef struct DEM {
    double x0, y0;
    double dx, dy;
    int xcount, ycount;
    double **alt;
} DEM;

void processDEM(DEM *d) {
    int xcount = d->xcount;
    int ycount = d->ycount;
    double meanDEM[xcount][ycount];

    // 计算每个点的平均值
    for (int i = 1; i < d->xcount - 1; i++) {
        for (int j = 1; j < d->ycount - 1; j++) {
            double total = 0;
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    total += d->alt[ii][jj];
                }
            }
            meanDEM[i][j] = total / 9;  // 9个值的平均
        }
    }

    // 将计算的平均值更新到原始数组 d->alt 中
    for (int i = 1; i < d->xcount - 1; i++) {
        for (int j = 1; j < d->ycount - 1; j++) {
            d->alt[i][j] = meanDEM[i][j];
        }
    }
}

int main() {
    // 示例 DEM 数据初始化
    DEM d;
    d.xcount = 10;
    d.ycount = 10;

    // 动态分配 alt 数组
    d.alt = (double **)malloc(d.xcount * sizeof(double *));
    for (int i = 0; i < d.xcount; i++) {
        d.alt[i] = (double *)malloc(d.ycount * sizeof(double));
    }

    // 假设 alt 已经被填充了一些数据
    for (int i = 0; i < d.xcount; i++) {
        for (int j = 0; j < d.ycount; j++) {
            d.alt[i][j] = i * d.ycount + j;  // 这里可以使用任意的初始化方式
        }
    }

    // 处理 DEM 数据
    processDEM(&d);

    // 打印处理后的 alt 数据
    for (int i = 0; i < d.xcount; i++) {
        for (int j = 0; j < d.ycount; j++) {
            printf("%.2f ", d.alt[i][j]);
        }
        printf("\n");
    }

    // 释放动态分配的 alt 数组
    for (int i = 0; i < d.xcount; i++) {
        free(d.alt[i]);
    }
    free(d.alt);

    return 0;
}
