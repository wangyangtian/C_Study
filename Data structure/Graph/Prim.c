#include <stdio.h>
#include <limits.h> // 包含INT_MAX用于表示无穷大
#include <stdlib.h>
#define MAXVERTEXNUM 100
#define INFINITY INT_MAX // 用于表示无穷大

// 图的邻接矩阵定义
typedef struct {
    int vexnum;                  // 顶点数
    int arcnum;                  // 边数
    int Vex[MAXVERTEXNUM];       // 顶点数组
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM]; // 邻接矩阵
} AMGraph;

// 邻接表(Adjacency List Graph)
typedef struct ArcNode {   // 边
    int adjvex;            // 弧指向的结点
    struct ArcNode* next;  // 指向下一条弧的指针
    int weight;           //边权值
} ArcNode;

typedef struct VNode {  // 顶点
    char data;          // 顶点信息
    ArcNode* first;     // 指向第一条弧的指针
} VNode, AdjList[MAXVERTEXNUM];

typedef struct ALGraph {
    AdjList vertices;   //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
} ALGraph;

// 使用邻接矩阵实现 Prim 算法
void PrimAM(AMGraph *G, int start) {
    int lowcost[MAXVERTEXNUM];   // 存储最小代价
    int closest[MAXVERTEXNUM];   // 存储相应的最小代价边的另一个端点
    int min, minid;

    // 初始化
    for (int i = 0; i < G->vexnum; i++) {
        lowcost[i] = G->Edge[start][i];
        closest[i] = start;
    }
    closest[start] = -1;  // 将起点标记为已加入树

    // Prim算法主循环
    for (int i = 1; i < G->vexnum; i++) {
        min = INFINITY;
        minid = -1;
        // 查找最小代价边
        for (int j = 0; j < G->vexnum; j++) {
            if (closest[j] != -1 && lowcost[j] < min) {
                min = lowcost[j];
                minid = j;
            }
        }

        // 输出最小代价边
        printf("边: %d - %d, 权值: %d\n", G->Vex[closest[minid]], G->Vex[minid], min);

        // 将新顶点加入树
        closest[minid] = -1;

        // 更新lowcost和closest数组
        for (int j = 0; j < G->vexnum; j++) {
            if (closest[j] != -1 && G->Edge[minid][j] < lowcost[j]) {
                lowcost[j] = G->Edge[minid][j];
                closest[j] = minid;
            }
        }
    }
}

// 使用邻接表的Prim算法
void PrimAL(ALGraph *G, int start) {
    int lowcost[MAXVERTEXNUM];  // 存储最小代价
    int closest[MAXVERTEXNUM];  // 存储相应的最小代价边的另一个端点
    int min, minid;

    // 初始化
    for (int i = 0; i < G->vexnum; i++) {
        lowcost[i] = INFINITY;
        closest[i] = -1;
    }

    // 将起始点加入树
    int current = start;
    lowcost[current] = 0;

    // Prim算法主循环
    for (int i = 1; i < G->vexnum; i++) {
        min = INFINITY;
        minid = -1;
        ArcNode *p = G->vertices[current].first;

        // 更新与当前树相邻的顶点的代价
        while (p) {
            if (p->weight < lowcost[p->adjvex]) {
                lowcost[p->adjvex] = p->weight;
                closest[p->adjvex] = current;
            }
            p = p->next;
        }

        // 找到具有最小代价的边
        for (int j = 0; j < G->vexnum; j++) {
            if (closest[j] != -1 && lowcost[j] < min) {
                min = lowcost[j];
                minid = j;
            }
        }

        // 输出最小代价边
        printf("边: %c - %c, 权值: %d\n", G->vertices[closest[minid]].data, G->vertices[minid].data, min);

        // 将新顶点加入树
        current = minid;
        closest[current] = -1;
    }
}

// 添加一条边
void AddEdge(ALGraph* g, int u, int v, int weight) {
    ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
    node->adjvex = v;
    node->weight = weight;
    node->next = g->vertices[u].first;
    g->vertices[u].first = node;
}

// 初始化图
void InitGraph(ALGraph* G, int vexnum) {
    G->vexnum = vexnum;
    G->arcnum = 0;
    for (int i = 0; i < vexnum; i++) {
        G->vertices[i].data = 'A' + i;  // 顶点名为 A, B, C...
        G->vertices[i].first = NULL;
    }
}

int main() {
    AMGraph g;
    g.vexnum = 5;  // 设置图的顶点数
    g.arcnum = 6;  // 设置图的边数

    // 初始化邻接矩阵
    for (int i = 0; i < g.vexnum; i++) {
        g.Vex[i]=i;
        for (int j = 0; j < g.vexnum; j++) {
            g.Edge[i][j] = INFINITY;  // 无边的情况
        }
    }

    // 设置边的权值
    g.Edge[0][1] = g.Edge[1][0] = 2;
    g.Edge[0][2] = g.Edge[2][0] = 3;
    g.Edge[1][2] = g.Edge[2][1] = 1;
    g.Edge[1][3] = g.Edge[3][1] = 4;
    g.Edge[2][4] = g.Edge[4][2] = 5;
    g.Edge[3][4] = g.Edge[4][3] = 7;
    // 假设从顶点0开始
    PrimAM(&g, 4);

    // ALGraph G;
    // InitGraph(&G, 5);  // 初始化图，假设有 5 个顶点

    // // 添加边
    // AddEdge(&G, 0, 1, 2);  // A-B 边，权值 2
    // AddEdge(&G, 1, 0, 2);  // B-A 边，权值 2 (无向图需要双向添加)
    // AddEdge(&G, 0, 2, 3);  // A-C 边，权值 3
    // AddEdge(&G, 2, 0, 3);  // C-A 边，权值 3
    // AddEdge(&G, 1, 2, 1);  // B-C 边，权值 1
    // AddEdge(&G, 2, 1, 1);  // C-B 边，权值 1
    // AddEdge(&G, 1, 3, 4);  // B-D 边，权值 4
    // AddEdge(&G, 3, 1, 4);  // D-B 边，权值 4
    // AddEdge(&G, 2, 4, 5);  // C-E 边，权值 5
    // AddEdge(&G, 4, 2, 5);  // E-C 边，权值 5
    // AddEdge(&G, 3, 4, 7);  // D-E 边，权值 7
    // AddEdge(&G, 4, 3, 7);  // E-D 边，权值 7

    // // 调用 Prim 算法，从顶点 A（索引 0）开始
    // PrimAL(&G, 0);

    return 0;
}
