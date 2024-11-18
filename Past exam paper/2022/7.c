#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double lon;  // 经度
    double lat;  // 纬度
} Point;

void get_tile_info(int n, int *num_row, int *num_col) {
    *num_col = 1 << n;
    *num_row = 1 << n;
}

void get_from_tile(int n, int row, int col, double *x, double *y) {
    int num_row = 0, num_col = 0;
    get_tile_info(n, &num_row, &num_col);

    double dx = 360.0 / num_col;
    double dy = 180.0 / num_row;

    *x = -180 + (col + 0.5) * dx;
    *y = -90 + (row + 0.5) * dy;
}

// 经纬度转瓦片编号
void get_form_cords(int level, double lat, double lon, int *row, int *col) {
    int tile_count = 1 << level;  // 瓦片的行列数
    double tile_width = 360.0 / tile_count;
    double tile_height = 180.0 / tile_count;

    *row = (int)((lat + 90) / tile_height);
    *col = (int)((lon + 180) / tile_width);
}

void get_form_polygon(Point polygon[], int p_num, int *n, int *row, int *col) {
    // 计算最小外接矩形
    double min_lon = polygon[0].lon, max_lon = polygon[0].lon;
    double min_lat = polygon[0].lat, max_lat = polygon[0].lat;

    for (int i = 0; i < p_num; i++) {
        if (polygon[i].lon < min_lon)
            min_lon = polygon[i].lon;
        if (polygon[i].lon > max_lon)
            max_lon = polygon[i].lon;
        if (polygon[i].lat < min_lat)
            min_lat = polygon[i].lat;
        if (polygon[i].lat > max_lat)
            max_lat = polygon[i].lat;
    }
    int row_min, col_min, row_max, col_max;
    for (int i = 19; i >= 0; i--) {
        get_form_cords(i, min_lat, min_lon, &row_min, &col_min);
        get_form_cords(i, max_lat, max_lon, &row_max, &col_max);
        if (row_max == row_min && col_max == col_min) {
            *n = i;
            *row = row_max;
            *col = col_min;
            return;
        }
    }
    *n = -1;
    return;
}

int main() {
    Point polygon[] = {
        {-79.1, -8.0},
        {-79.2, -8.0},
        {-79.2, -8.2},
        {-79.1, -8.2}};
    int p_num = 4;  // 顶点数
    int n, row, col;

    get_form_polygon(polygon, p_num, &n, &row, &col);

    if (n != -1) {
        printf("多边形在级别 %d 的瓦片中，行号: %d，列号: %d\n", n, row, col);
    } else {
        printf("无法找到满足条件的瓦片。\n");
    }

    return 0;
}
