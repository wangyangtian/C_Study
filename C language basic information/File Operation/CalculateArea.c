#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.1415
typedef struct POINT {
    int x;
    int y;
} POINT;

typedef struct LINE {
    POINT p1;
    POINT p2;
    float len;
} LINE;

typedef struct RECT {
    POINT p;
    int width;
    int height;
    float area;
} RECT;

typedef struct CIRCLE {
    POINT center;
    int r;
    float area;
} CIRCLE;

int Marching(char* str) {
    if (strcmp(str, "LINE") == 0)
        return 1;
    if (strcmp(str, "RECT") == 0)
        return 2;
    if (strcmp(str, "CIRCLE") == 0)
        return 3;
    return 0;
}

int main() {
    FILE* fp;
    char str[100];
    char buffer[100];
    LINE L;
    RECT R;
    CIRCLE C;
    fp = fopen("geodata.txt", "r");
    if (fp == NULL) {
        printf("geo文件打开错误！\n");
        return 1;
    } else {

        fscanf(fp, "%s", str);
        fgets(buffer,100,fp);

        while (strcmp(str, "END") != 0) {
            int k = Marching(str);
            switch (k) {
                case 1:
                    fscanf(fp, "%d %d %d %d", &L.p1.x, &L.p1.y, &L.p2.x,
                           &L.p2.y);   
                    break;
                case 2:
                    fscanf(fp, "%d %d %d %d", &R.p.x, &R.p.y, &R.width,
                           &R.height);
                    break;
                case 3:
                    fscanf(fp, "%d %d %d", &C.center.x, &C.center.y, &C.r);
                    break;
                default:
                    break;
            }    
            fscanf(fp, "%s", str);
            fgets(buffer,100,fp);
        }
    }
    fclose(fp);

    L.len = sqrt((L.p1.x - L.p2.x) * (L.p1.x - L.p2.x) +
                 (L.p1.y - L.p2.y) * (L.p1.y - L.p2.y));
    R.area = R.height * R.width;
    C.area = PI * C.r * C.r;

    fp = fopen("newdata.txt", "w");
    if (fp == NULL)
        printf("newdata打开文件错误！");
    else {
        fprintf(fp, "LINE: %d %d %d %d Area: %f\n", L.p1.x, L.p1.y, L.p2.x,
                L.p2.y, L.len);
        fprintf(fp, "RECT: %d %d %d %d Area: %f\n", R.p.x, R.p.y, R.width,
                R.height, R.area);
        fprintf(fp, "CIRCLE: %d %d %d Area: %f\n", C.center.x, C.center.y,  
                C.r,C.area);
    }
    fclose(fp);
    return 0;
}