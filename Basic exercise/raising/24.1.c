#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVNUM 100

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* next;
    int weight;
} ArcNode;

typedef struct VNode {
    char data;
    ArcNode* firstArc;
} VNode, adjList[MAXVNUM];

typedef struct ALGraph {
    adjList vertices;
    int vnum, arcnum;
} ALGraph;

bool visited[MAXVNUM] = {false};

void FindPath(ALGraph* g, int u, int v, int* path, int len) {
    ArcNode* p;
    visited[u] = true;
    path[len++] = u;
    if (u == v) {
        for (int i = 0; path[i] != -1; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    p = g->vertices[u].firstArc;
    while (p != NULL) {
        if (visited[p->adjvex] == false)
            FindPath(g, p->adjvex, v, path, len);
        p = p->next;
    }
    visited[u] = 0;
}

void TestFindPath() {
    ALGraph g;
    g.vnum = 5;
    g.arcnum = 5;

    // 初始化图顶点
    for (int i = 0; i < g.vnum; i++) {
        g.vertices[i].data = 'A' + i;
        g.vertices[i].firstArc = NULL;
    }

    // 添加边 A -> B, A -> C, B -> D, C -> D, D -> E
    ArcNode* arcAB = (ArcNode*)malloc(sizeof(ArcNode));
    arcAB->adjvex = 1;  // A->B
    arcAB->next = NULL;
    g.vertices[0].firstArc = arcAB;

    ArcNode* arcAC = (ArcNode*)malloc(sizeof(ArcNode));
    arcAC->adjvex = 2;  // A->C
    arcAC->next = g.vertices[0].firstArc;
    g.vertices[0].firstArc = arcAC;

    ArcNode* arcBD = (ArcNode*)malloc(sizeof(ArcNode));
    arcBD->adjvex = 3;  // B->D
    arcBD->next = NULL;
    g.vertices[1].firstArc = arcBD;

    ArcNode* arcCD = (ArcNode*)malloc(sizeof(ArcNode));
    arcCD->adjvex = 3;  // C->D
    arcCD->next = NULL;
    g.vertices[2].firstArc = arcCD;

    ArcNode* arcDE = (ArcNode*)malloc(sizeof(ArcNode));
    arcDE->adjvex = 4;  // D->E
    arcDE->next = NULL;
    g.vertices[3].firstArc = arcDE;

    // 初始化路径数组
    int path[MAXVNUM];
    for (int i = 0; i < MAXVNUM; i++)
        path[i] = -1;

    printf("路径 A 到 E:\n");
    FindPath(&g, 0, 4, path, 0);

    // 释放内存
    free(arcAB);
    free(arcAC);
    free(arcBD);
    free(arcCD);
    free(arcDE);
}

int main() {
    TestFindPath();
    return 0;
}
