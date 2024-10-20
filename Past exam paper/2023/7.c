#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
    float x;
    float y;
} Point;

typedef struct ploy {
    int    Num;
    Point* Points;
} ploy;

typedef struct Ring {
    ploy  Exterior;
    ploy* Interior;
} Ring;

void load(const char* path, Ring* i) {
    FILE* fp = fopen(path, "r");
    char  flag[20];
    while (fscnaf(fp, "%s %s", &flag)) {

        if (strcmp(flag, "#Exterior") == 0) {
            fscanf(fp, "%d", &i->Exterior.Num);
            i->Exterior.Points = (Point*) malloc(sizeof(Point) * i->Exterior.Num);
            
            for (int j = 0; j < i->Exterior.Num;j++){
                fscanf(fp, "%lf, %lf", &i->Exterior.Points[j].x, &i->Exterior.Points[j].y);
            }
        }
        if (strcmp(flag, "#Interior") == 0){
            
        }
    }
}

int main() {
    Ring i;
    load("data.txt", &i);

    return 0;
}