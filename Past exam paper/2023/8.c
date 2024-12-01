#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Station {
    double lon, lat;
    double x, y;
    double temp;
    struct _Station* next;
} Station;

typedef struct _Grid {
    int row, col;
    double value;
    int num;  // number of station
    Station* stas;
} Grid;

Station* Transform(const char* path) {
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("File open failed");
        return NULL;
    }

    int num;
    if (fscanf(fp, "%d", &num) != 1) {
        fprintf(stderr, "Failed to read the number of stations\n");
        fclose(fp);
        return NULL;
    }

    Station* s = (Station*)malloc(sizeof(Station));
    Station* t = s;

    for (int i = 0; i < num; i++) {
        Station* new_s = (Station*)malloc(sizeof(Station));
        fscanf(fp, "%lf, %lf, %lf", &new_s->lon, &new_s->lat, &new_s->temp);
        new_s->next = NULL;
        t->next = new_s;
        t = new_s;
    }
    fclose(fp);

    t = s->next;
    double min_lon = INT_MAX;
    double min_lat = INT_MAX;

    while (t) {
        if (t->lon < min_lon)
            min_lon = t->lon;
        if (t->lat < min_lat)
            min_lat = t->lat;
        t = t->next;
    }

    t = s->next;
    while (t) {
        t->x = (t->lon - min_lon) / 0.000000156785 * cos(t->lat);  // 经纬度转换时加上角度转弧度
        t->y = (t->lat - min_lat) / 0.00000157;
        t = t->next;
    }
    return s;
}

Grid** CreateGrid(Station* s) {
    double left, right, up, down;
    Station* t = s->next;
    left = t->x;
    right = t->x;
    up = t->y;
    down = t->y;

    while (t != NULL) {
        left = t->x < left ? t->x : left;
        right = t->x > right ? t->x : right;
        up = t->y > up ? t->y : up;
        down = t->y < down ? t->y : down;
        t = t->next;
    }

    double dx = right - left;
    double dy = up - down;

    int row = dy / 1000 + 1;
    int col = dx / 1000 + 1;

    Grid** g = (Grid**)malloc(sizeof(Grid*) * row);
    for (int i = 0; i < row; i++)
        g[i] = (Grid*)malloc(sizeof(Grid) * col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            g[i][j].col = col;
            g[i][j].row = row;
            g[i][j].num = 0;
            g[i][j].value = 0;
            g[i][j].stas = (Station*)malloc(sizeof(Station));
            g[i][j].stas->next = NULL;
        }
    }

    // 遍历站点链表，将站点放入网格
    Station* current = s->next;  // 假设 s 是链表的头节点
    while (current != NULL) {
        int i = (int)((current->x - left) / 1000);
        int j = (int)((current->y - down) / 1000);

        // 确保 i 和 j 在有效范围内
        if (i >= 0 && i < row && j >= 0 && j < col) {
            // 复制当前站点并插入到网格相应位置
            Station* new_station = (Station*)malloc(sizeof(Station));

            *new_station = *current;                 // 复制站点信息
            new_station->next = g[i][j].stas->next;  // 将新的站点插入链表
            g[i][j].stas->next = new_station;        // 更新链表头
            g[i][j].num++;                           // 更新站点计数
        }

        current = current->next;  // 移动到链表中的下一个站点
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

            double d_inv[g[i][j].num];
            double w[g[i][j].num];
            double d_inv_total = 0;
            double t_cell = 0;
            Station* t = g[i][j].stas->next;

            for (int k = 0; k < g[i][j].num; k++) {
                // 假设格网单元中心为当前单元的中心
                double center_x = (i + 0.5) * 1000;
                double center_y = (j + 0.5) * 1000;
                double distance = sqrt(pow(center_x - t->x, 2) + pow(center_y - t->y, 2));
                d_inv[k] = 1 / distance;

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
