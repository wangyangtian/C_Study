#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Station {
    double           lon, lat;
    double           x, y;
    double           temp;
    struct _Station* next;
} Station;

typedef struct _Grid {
    int      row, col;
    double   value;
    int      num; //number of station
    Station* stas;
} Grid;

Station* Transform(const char* path) {
    FILE* fp = fopen(path, "r");
    int   num;
    fscanf(fp, "%d", &num);
    Station* s = (Station*) malloc(sizeof(Station));
    Station* t = s;

    for (int i = 0; i < num; i++) {
        Station* new = (Station*) malloc(sizeof(Station));
        fscanf(fp, "%lf, %lf, %lf", &new->lon, &new->lat, &new->temp);
        new->next = NULL;
        t->next   = new;
        t         = new;
    }

    t              = s->next;
    double min_lon = INT_MAX;
    double min_lat = INT_MAX;

    for (int i = 0; i < num; i++) {
        if (t->lon < min_lon)
            min_lon = t->lon;
        if (t->lat < min_lat)
            min_lat = t->lat;
        t = t->next;
    }
    t = s->next;

    for (int i = 0; i < num; i++) {
        t->x = (t->lon - min_lon) / 0.000000156785 * cos(t->lat);
        t->y = (t->lat - min_lat) / 0.00000157;
        t    = t->next;
    }
    return s;
}

Grid** CreateGrid(Station* s) {
    double   left, right, up, down;
    Station* t = s->next;
    left       = t->x;
    right      = t->x;
    up         = t->y;
    down       = t->y;

    while (t != NULL) {
        left  = t->x < left ? t->x : left;
        right = t->x > right ? t->x : right;
        up    = t->y > up ? t->y : up;
        down  = t->y < down ? t->y : down;
        t     = t->next;
    }

    double dx = right - left;
    double dy = up - down;

    int row = dy / 1000 + 1;
    int col = dx / 1000 + 1;

    Grid** g = (Grid**) malloc(sizeof(Grid*) * row);
    for (int i = 0; i < row; i++)
        g[i] = (Grid*) malloc(sizeof(Grid) * col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            g[i][j].col        = col;
            g[i][j].row        = row;
            g[i][j].num        = 0;
            g[i][j].value      = 0;
            g[i][j].stas       = (Station*) malloc(sizeof(Station));
            g[i][j].stas->next = NULL;
        }
    }

    t = s->next;
    while (t != NULL) {
        int i = (int) ((t->x - left) / 1000);
        int j = (int) ((t->y - down) / 1000);

        Station* new = (Station*) malloc(sizeof(Station));
        new->lat     = t->lat;
        new->lon     = t->lon;
        new->temp    = t->temp;
        new->x       = t->x;
        new->y       = t->y;

        new->next = g[i][j].stas->next;
        g[i][j].stas->next = new;
        g[i][j].num++;
        t = t->next;
    }
    return g;
}

void assign(Grid** g) {
    int row = g[0][0].row;
    int col = g[0][0].col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (g[i][j].num == 0)
                continue;

            double   d_inv[g[i][j].num];
            double   w[g[i][j].num];
            double   d_inv_total = 0;
            double   t_cell      = 0;
            Station* t           = g[i][j].stas->next;

            for (int k = 0; k < g[i][j].num; k++) {
                // 假设格网单元中心为当前单元的中心
                double center_x = (i + 0.5) * 1000;
                double center_y = (j + 0.5) * 1000;
                double distance = sqrt(pow(center_x - t->x, 2) + pow(center_y - t->y, 2));
                d_inv[k]        = 1 / distance;

                d_inv_total += d_inv[k];
                t = t->next;
            }
            for (int k = 0; k < g[i][j].num; k++) {
                w[k] = d_inv[k] / d_inv_total;
            }

            t = g[i][j].stas->next;
            for (int k = 0; k < g[i][j].num; k++) {
                t_cell += w[k] * t->temp;
                t = t->next;
            }
            g[i][j].value = t_cell;
        }
    }
}
int main() {
    // 假设数据文件名为 "data.txt"
    const char* filepath = "station.txt";

    // 转换坐标
    Station* stations = Transform(filepath);

    // 创建格网
    Grid** grid = CreateGrid(stations);

    // 计算每个格网单元的温度
    assign(grid);

    // 输出结果
    int row = grid[0][0].row;
    int col = grid[0][0].col;

    printf("Grid Temperature Values:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Cell (%d, %d): Temperature = %.2f\n", i, j, grid[i][j].value);
        }
    }


    return 0;
}
