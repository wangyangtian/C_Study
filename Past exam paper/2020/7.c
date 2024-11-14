#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTEXNUM 100
#define INF INT_MAX

typedef struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode* next;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode* firstArc;
} VNode, AdjList[MAXVERTEXNUM];

typedef struct ALGraph {
    AdjList vertices;
    int vnum, arcnum;
} ALGraph;

void Dijkstra(ALGraph* g, int src) {
    int dist[MAXVERTEXNUM];
    bool sptSet[MAXVERTEXNUM] = {false};

    for (int i = 0; i < g->vnum; i++) {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int count = 0; count < g->vnum - 1; count++) {
        int min = INF;
        int u = -1;
        for (u = 0; u < g->vnum; u++) {
            if (sptSet[u] == false && dist[u] < min) {
                min = dist[u];
            }
        }

        sptSet[u] = true;

        ArcNode* p = g->vertices[u].firstArc;

        while (p != NULL) {
            int v = p->adjvex;

            if (sptSet[v] != true && dist[u] + p->weight < dist[v]) {
                dist[v] = dist[u] + p->weight;
            }
            p = p->next;
        }
    }
}

int main() {
    return 0;
}