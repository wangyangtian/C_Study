#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct POINT
{
    int x;
    int y;
}POINT;

typedef struct LINE
{
    POINT p1;
    POINT p2;
    float len;
}LINE;

typedef struct RECT
{
    POINT p;
    int width;
    int height;
    float area;
}RECT;

typedef struct CIRCLE
{
    POINT center;
    int r;
    float area;
}CIRCLE;



int main() {
    FILE* fp;
    
    fp=fopen("geodata.text","r");

    fclose(fp);
    return 0;
}