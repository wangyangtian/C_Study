#define _USE_MATH_DEFINES
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sin_value[3600];

double fast_sin(double angle) {
    int a = (int)(angle * 10);
    return sin_value[a];
}

int main() {
    for (int i = 0; i < 3600; i++) {
        sin_value[i] = sin(M_PI / 1800 * i);
    }
    printf("输入角度：");
    double angle;
    scanf("%lf", &angle);
    printf("sin值为：%lf", fast_sin(angle));
    return 0;
}