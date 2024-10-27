#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVNUM 100

// 定义边结构体
typedef struct ArcNode {
    int             adjvex; // 该边所指向的顶点下标
    struct ArcNode* next;   // 指向下一条边的指针
    int             weight; // 边的权重
} ArcNode;

// 定义顶点结构体
typedef struct VNode {
    char     data;     // 顶点的数据 (字符表示)
    ArcNode* firstArc; // 指向第一条边的指针
} VNode, adjList[MAXVNUM];

// 图的邻接表结构
typedef struct ALGraph {
    adjList vertices;     // 存储顶点的数组
    int     vnum, arcnum; // 图的顶点数和边数
} ALGraph;

// 访问标志数组，记录各顶点是否已被访问
bool visited[MAXVNUM] = {false};

// 寻找从顶点 u 到顶点 v 的所有路径
void FindPath(ALGraph* g, int u, int v, int* path, int d) {
    ArcNode* p;
    visited[u] = true; // 标记顶点 u 已被访问
    path[d++]  = u;    // 将顶点 u 加入路径

    // 如果到达目标顶点 v，输出路径
    if (u == v) {
        for (int i = 0; i<d; i++)
            printf("%d ", path[i]);
        printf("\n");
    }

    // 遍历与 u 相连的所有顶点
    p = g->vertices[u].firstArc;
    while (p != NULL) {
        // 若该顶点未访问，递归寻找路径
        if (visited[p->adjvex] == false)
            FindPath(g, p->adjvex, v, path, d);
        p = p->next;
    }

    visited[u] = false; // 回溯时取消顶点 u 的访问标记
}

// 测试函数，用于构建图并调用 FindPath 函数
void TestFindPath() {
    ALGraph g;
    g.vnum   = 4; // 图中顶点数
    g.arcnum = 5; // 图中边数

    // 初始化图的顶点
    for (int i = 0; i < g.vnum; i++) {
        g.vertices[i].data     = 'A' + i; // 顶点数据从 'A' 开始
        g.vertices[i].firstArc = NULL;    // 初始化时没有边
    }

    // 添加边 A <-> B
    ArcNode* arcAB         = (ArcNode*) malloc(sizeof(ArcNode));
    arcAB->adjvex          = 1; // A -> B
    arcAB->next            = g.vertices[0].firstArc;
    g.vertices[0].firstArc = arcAB;

    ArcNode* arcBA         = (ArcNode*) malloc(sizeof(ArcNode));
    arcBA->adjvex          = 0; // B -> A
    arcBA->next            = g.vertices[1].firstArc;
    g.vertices[1].firstArc = arcBA;

    // 添加边 A <-> C
    ArcNode* arcAC         = (ArcNode*) malloc(sizeof(ArcNode));
    arcAC->adjvex          = 2; // A -> C
    arcAC->next            = g.vertices[0].firstArc;
    g.vertices[0].firstArc = arcAC;

    ArcNode* arcCA         = (ArcNode*) malloc(sizeof(ArcNode));
    arcCA->adjvex          = 0; // C -> A
    arcCA->next            = g.vertices[2].firstArc;
    g.vertices[2].firstArc = arcCA;

    // 添加边 B <-> C
    ArcNode* arcBC         = (ArcNode*) malloc(sizeof(ArcNode));
    arcBC->adjvex          = 2; // B -> C
    arcBC->next            = g.vertices[1].firstArc;
    g.vertices[1].firstArc = arcBC;

    ArcNode* arcCB         = (ArcNode*) malloc(sizeof(ArcNode));
    arcCB->adjvex          = 1; // C -> B
    arcCB->next            = g.vertices[2].firstArc;
    g.vertices[2].firstArc = arcCB;

    // 添加边 B <-> D
    ArcNode* arcBD         = (ArcNode*) malloc(sizeof(ArcNode));
    arcBD->adjvex          = 3; // B -> D
    arcBD->next            = g.vertices[1].firstArc;
    g.vertices[1].firstArc = arcBD;

    ArcNode* arcDB         = (ArcNode*) malloc(sizeof(ArcNode));
    arcDB->adjvex          = 1; // D -> B
    arcDB->next            = g.vertices[3].firstArc;
    g.vertices[3].firstArc = arcDB;

    // 添加边 C <-> D
    ArcNode* arcCD         = (ArcNode*) malloc(sizeof(ArcNode));
    arcCD->adjvex          = 3; // C -> D
    arcCD->next            = g.vertices[2].firstArc;
    g.vertices[2].firstArc = arcCD;

    ArcNode* arcDC         = (ArcNode*) malloc(sizeof(ArcNode));
    arcDC->adjvex          = 2; // D -> C
    arcDC->next            = g.vertices[3].firstArc;
    g.vertices[3].firstArc = arcDC;

    // 初始化路径数组，-1 表示路径结束
    int path[MAXVNUM];
    for (int i = 0; i < MAXVNUM; i++)
        path[i] = -1;

    // 寻找从 A (顶点 0) 到 D (顶点 3) 的路径
    printf("路径 A 到 D:\n");
    FindPath(&g, 0, 3, path, 0);

    // 释放分配的内存
    free(arcAB);
    free(arcBA);
    free(arcAC);
    free(arcCA);
    free(arcBC);
    free(arcCB);
    free(arcBD);
    free(arcDB);
    free(arcCD);
    free(arcDC);
}

int main() {
    TestFindPath(); // 调用测试函数
    return 0;
}
