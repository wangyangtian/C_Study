#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVEX 100

typedef struct AMGraph {
    int vex[MAXVEX];
    int edge[MAXVEX][MAXVEX];
    int vnum, arcnum;
} AMGraph;

typedef struct ArcNode {
    int weight;
    int adjvex;
    struct ArcNode *nextArc;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode *firstArc;
} VNode;

typedef struct ALGraph {
    VNode vertices[MAXVEX];
    int vnum, arcnum;
} ALGraph;

ALGraph *Mtol(AMGraph *m) {
    ALGraph *l = (ALGraph *)malloc(sizeof(ALGraph));
    if (l == NULL)
        return NULL;

    l->arcnum = m->arcnum;
    l->vnum = m->vnum;

    for (int i = 0; i < m->vnum; i++) {
        l->vertices[i].data = m->vex[i];
        l->vertices[i].firstArc = (ArcNode *)malloc(sizeof(ArcNode));
        l->vertices[i].firstArc->nextArc = NULL;
    }

    for (int i = 0; i < m->vnum; i++) {
        for (int j = 0; j < m->vnum; j++) {
            if (m->edge[i][j] != 0) {
                ArcNode *node = (ArcNode *)malloc(sizeof(ArcNode));
                node->adjvex = j;
                node->nextArc = l->vertices[i].firstArc->nextArc;
                node->weight = m->edge[i][j];
                l->vertices[i].firstArc->nextArc = node;
            }
        }
    }

    return l;
}

AMGraph *Ltom(ALGraph *l) {
    AMGraph *m = (AMGraph *)malloc(sizeof(AMGraph));
    if (m == NULL)
        return NULL;

    m->vnum = l->vnum;
    m->arcnum = l->arcnum;

    for (int i = 0; i < l->vnum; i++) {
        m->vex[i] = l->vertices[i].data;

        ArcNode *current = l->vertices[i].firstArc->nextArc;

        while (current != NULL) {
            int j = current->adjvex;
            int weight = current->weight;
            m->edge[i][j] = weight;
            current = current->nextArc;
        }
    }

    return m;
}

void hospital(AMGraph *g, int d[][MAXVEX]) {
    for (int i = 0; i < g->vnum; i++) {
        for (int j = 0; j < g->vnum; j++) {
            d[i][j] = g->edge[i][j];
        }
    }

    for (int k = 0; k < g->vnum; k++) {
        for (int i = 0; i < g->vnum; i++) {
            for (int j = 0; j < g->vnum; i++) {
                if (g->edge[i][k] + g->edge[k][j] < g->edge[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int minLongestPath = INT_MAX;
    int hospital = -1;

    for (int i = 0; i < g->vnum; i++) {
        int LongthPath = 0;
        for (int j = 0; j < g->vnum; j++) {
            LongthPath = d[i][j] > LongthPath ? d[i][j] : LongthPath;
        }

        if (LongthPath < minLongestPath) {
            minLongestPath = LongthPath;
            hospital = i;
        }
    }

    printf("医院的最佳选址在%d", hospital);
}

int main() {
    return 0;
}