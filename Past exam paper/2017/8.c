#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _MGraph {
    vex[MAXSIZE];
    edge[MAXSIZE][MAXSIZE];
    int v_num, e_num;
} MGraph;

void Prim(MGraph* g, int start) {
    int lowcost[MAXSIZE];
    int closest[MAXSIZE];
    int min, minid;

    for (int i = 0; i < g->v_num; i++) {
        lowcost[i] = g->edge[start][i];
        closest[i] = start;
    }
    closest[start] = -1;

    for (int i = 1; i < g->v_num; i++) {
        min = INFINITY;
        minid = -1;

        for (int j = 0; j < g->v_num; j++) {
            if (lowcost[j] < min && closest[j] != -1) {
                min = lowcost[j];
                minid = j;
            }
        }

        if (minid != -1) {
            printf("边：%c-%c，权值：%d\n", g->vex[minid], g->vex[closest[minid]], min);
        }

        closest[minid] = -1;

        for (int j = 0; j < g->v_num; j++) {
            if (closest[j] != -1 && g->edge[minid][j] < lowcost[j]) {
                lowcost[j] = g->edge[minid][j];
                closest[j] = minid;
            }
        }
    }
}

int main() {
    return 0;
}