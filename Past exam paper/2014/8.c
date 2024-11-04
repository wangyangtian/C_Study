#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _DEM {
    double x0, y0;
    double dx, dy;
    int xcount, ycount;
    double **alt;
} DEM;

DEM *cutDEM(DEM *src, double new_x0, double new_y0, int xcount, int ycount) {
    if (new_x0 < src->x0 || new_x0 + src->dx * (xcount - 1) > src->x0 + src->dx * (src->xcount - 1))
        return NULL;
    if (new_y0 < src->y0 || new_y0 + src->dy * (ycount - 1) > src->y0 + src->dy * (src->ycount - 1))
        return NULL;

    DEM *newDEM = (DEM *)malloc(sizeof(DEM));
    if (!newDEM)
        return NULL;

    newDEM->x0 = new_x0;
    newDEM->y0 = new_y0;
    newDEM->xcount = xcount;
    newDEM->ycount = ycount;
    newDEM->dx = src->dx;
    newDEM->dy = src->dy;

    newDEM->alt = (double **)malloc(sizeof(double *) * xcount);

    for (int i = 0; i < xcount; i++) {
        newDEM->alt[i] = (double *)malloc(sizeof(double) * ycount);
    }

    for (int i = 0; i < xcount; i++) {
        for (int j = 0; j < ycount; j++) {
            int src_i = i + (int)(new_x0 - src->x0) / src->dx;
            int src_j = j + (int)(new_y0 - src->y0) / src->dy;
            newDEM->alt[i][j] = src->alt[src_i][src_j];
        }
    }
    return newDEM;
}

int main() {
    return 0;
}