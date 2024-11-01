#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double** mean(double DEM[256][256]) {
    double** newDEM = (double**)malloc(256 * sizeof(double*));
    for (int i = 0; i < 256; i++) {
        newDEM[i] = (double*)malloc(256 * sizeof(double));
    }

    for (int i = 0; i < 256; i++) {
        newDEM[0][i] = DEM[0][i];
        newDEM[255][i] = DEM[255][i];
        newDEM[i][0] = DEM[i][0];
        newDEM[i][255] = DEM[i][255];
    }

    for (int i = 1; i < 255; i++) {
        for (int j = 1; j < 255; j++) {
            double total = 0;
            for (int u = i - 1; u <= i + 1; u++) {
                for (int v = j - 1; v <= j + 1; j++)
                    total += DEM[u][v];
            }

            newDEM[i][j] = total / 9.0;
        }
    }
    return newDEM;
}

int main() {
    return 0;
}