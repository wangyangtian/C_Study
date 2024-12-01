#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LoadFile(double *t, double *x, double *y, double *z, char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("open failed!\n");
        return;
    }
    for (int i = 0; i < 13; i++) {
        fscanf(fp, "%lf,%lf,%lf,%lf", &t[i], &x[i], &y[i], &z[i]);
    }
    fclose(fp);
}

void leastSquares(double *x, double *y, double *b0, double *b1) {
    double sum_x = 0, sum_y = 0;
    double avg_x = 0, avg_y = 0;

    for (int i = 0; i < 13; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }
    avg_x = sum_x / 13;
    avg_y = sum_y / 13;

    double t1 = 0, t2 = 0;
    for (int i = 0; i < 13; i++) {
        t1 += ((x[i] - avg_x) * (y[i] - avg_y));
        t2 += ((x[i] - avg_x) * (x[i] - avg_x));
    }
    *b1 = t1 / t2;
    *b0 = avg_y - (*b1) * avg_x;
}

void model(double *t, double *x, double *y, double *z, double ti, double *xi, double *yi, double *zi) {
    double b0x, b1x, b0y, b1y, b0z, b1z;
    leastSquares(t, x, &b0x, &b1x);
    leastSquares(t, y, &b0y, &b1y);
    leastSquares(t, z, &b0z, &b1z);

    *xi = b0x + b1x * ti;
    *yi = b0y + b1y * ti;
    *zi = b0z + b1z * ti;
}

int main() {
    double t[13];
    double x[13], y[13], z[13];
    char path[] = "orbit.txt";
    LoadFile(t, x, y, z, path);

    double xi, yi, zi;
    model(t, x, y, z, 4500, &xi, &yi, &zi);
    printf("t=4500时预测x=%.2lf,y=%.2lf,z=%.2lf", xi, yi, zi);
    return 0;
}