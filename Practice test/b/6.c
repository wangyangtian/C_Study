#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return 0;
}