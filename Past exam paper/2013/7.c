#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Point {
    double x;
    double y;
} Point;

typedef struct _Polygon {
    int id;
    Point* point;
    int point_num;
} Polygon;

typedef struct _Polygons {
    Polygon* Polygons;
    int polygon_num;
} PolygonSet;

int main() {
    char path[] = "polygons.txt";
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("文件打开失败");
        return 0;
    }
    PolygonSet set;

    char line[1024];
    fgets(line, 1024, fp);
    sscanf(line, "%d", &set.polygon_num);

    set.Polygons = (Polygon*)malloc(sizeof(Polygon) * set.polygon_num);

    for (int i = 0; i < set.polygon_num; i++) {
        fgets(line, 1024, fp);
        sscanf(line, "%d %d", &set.Polygons[i].id, &set.Polygons[i].point_num);
        set.Polygons[i].point = (Point*)malloc(sizeof(Point) * set.Polygons[i].point_num);

        for (int j = 0; j < set.Polygons[i].point_num; j++) {
            fgets(line, 1024, fp);
            sscanf(line, "%lf %lf", &set.Polygons[i].point[j].x, &set.Polygons[i].point[j].y);
        }
    }
    fclose(fp);

    printf("多边形集共有%d个多边形\n", set.polygon_num);

    for (int i = 0; i < set.polygon_num; i++) {
        printf("多边形%d共有%d个点\n", set.Polygons[i].id, set.Polygons[i].point_num);

        for (int j = 0; j < set.Polygons[i].point_num; j++) {
            printf("第%d个点为(%.2lf,%.2lf)\n", j + 1, set.Polygons[i].point[j].x, set.Polygons[i].point[j].y);
        }
    }

    return 0;
}