#include <limits.h>  // 包含 INT_MAX 常量的定义
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTEXNUM 100  // 最大顶点数
#define INFINITY INT_MAX  // 表示无穷大的值

typedef struct {
    char Vex[MAXVERTEXNUM];                // 顶点表
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 邻接矩阵，边权值表
    int vexnum, arcnum;                    // 当前顶点数和边数
} AMGraph;

// 邻接表
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

// 寻找距离最近的未访问顶点
int MinDistance(int dist[], bool sptSet[], int V) {
    int min = INFINITY, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// 递归打印路径
void PrintPath(int prev[], int i) {
    if (prev[i] == -1) {  // 递归终止条件
        printf("%d ", i);
        return;
    }
    PrintPath(prev, prev[i]);
    printf("-> %d ", i);
}

// 打印从源点到各个顶点的最短距离和路径
void PrintSolution(int dist[], int prev[], int V, int src) {
    printf("Vertex \t Distance from Source\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\t\t", i, dist[i]);
        PrintPath(prev, i);
        printf("\n");
    }
}

// Dijkstra算法实现，求从源点到所有顶点的最短路径
void Dijkstra(AMGraph* g, int src) {
    int V = g->vexnum;          // 顶点个数
    int dist[MAXVERTEXNUM];     // 存储源点到每个顶点的最短距离
    bool sptSet[MAXVERTEXNUM];  // sptSet[i]为true表示顶点i在最短路径树中(Shortest Path Tree Set)
    int prev[MAXVERTEXNUM];     // prev[i]表示从源点到i的最短路径上的前一个顶点

    // 初始化所有顶点的距离为无穷大，sptSet[]为false
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITY;
        sptSet[i] = false;
        prev[i] = -1;  // 初始化前驱节点为-1，表示无前驱
    }

    // 源点到自身距离为0
    dist[src] = 0;

    // 找到从源点到所有其他顶点的最短路径
    for (int count = 0; count < V - 1; count++) {
        // 从尚未处理的顶点中选择距离最小的顶点
        int u = MinDistance(dist, sptSet, V);

        // 将选中的顶点加入到最短路径树中
        sptSet[u] = true;

        // 更新邻接顶点的距离值
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && g->Edge[u][v] != 0 && dist[u] != INFINITY &&
                dist[u] + g->Edge[u][v] < dist[v]) {
                dist[v] = dist[u] + g->Edge[u][v];
                prev[v] = u;  // 更新前驱节点
            }
        }
    }

    // 打印最短路径结果
    PrintSolution(dist, prev, V, src);
}

// 获取图中指定顶点的位置
int GetVertexIndex(ALGraph* g, char data) {
    for (int i = 0; i < g->vexnum; i++) {
        if (g->vertices[i].data == data)
            return i;
    }
    return -1;
}

// Dijkstra算法实现
void Dijkstra_L(ALGraph* g, int src) {
    int V = g->vexnum;          // 顶点个数
    int dist[MAXVERTEXNUM];     // 存储源点到每个顶点的最短距离
    bool sptSet[MAXVERTEXNUM];  // 记录顶点是否在最短路径树中
    int prev[MAXVERTEXNUM];     // 存储前驱节点

    // 初始化dist数组为无穷大，sptSet数组为false
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITY;
        sptSet[i] = false;
        prev[i] = -1;  // 前驱节点初始化为-1
    }

    dist[src] = 0;  // 源点到自身距离为0

    // 找到从源点到所有其他顶点的最短路径
    for (int count = 0; count < V - 1; count++) {
        int min = INFINITY, u = -1;

        // 从未处理的顶点中选择距离最小的顶点
        for (int i = 0; i < V; i++) {
            if (!sptSet[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        // 将选中的顶点加入到最短路径树中
        sptSet[u] = true;

        // 更新u的邻接顶点的距离值
        ArcNode* p = g->vertices[u].first;
        while (p != NULL) {
            int v = p->adjvex;
            if (!sptSet[v] && dist[u] + p->weight < dist[v]) {
                dist[v] = dist[u] + p->weight;
                prev[v] = u;  // 更新前驱节点
            }
            p = p->next;
        }
    }

    // 打印最短路径结果
    PrintSolution(dist, prev, V, src);
}

// 添加一条边
void AddEdge(ALGraph* g, int u, int v, int weight) {
    ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
    node->adjvex = v;
    node->weight = weight;
    node->next = g->vertices[u].first;
    g->vertices[u].first = node;
}

int main() {
    // AMGraph g;
    // g.vexnum = 5;  // 设置图的顶点数
    // g.arcnum = 7;  // 设置图的边数

    // // 初始化邻接矩阵
    // for (int i = 0; i < g.vexnum; i++) {
    //     for (int j = 0; j < g.vexnum; j++) {
    //         g.Edge[i][j] = 0;  // 无边的情况
    //     }
    // }

    // // 设置边的权值
    // g.Edge[0][1] = 10;
    // g.Edge[0][4] = 5;
    // g.Edge[1][2] = 1;
    // g.Edge[2][3] = 4;
    // g.Edge[3][0] = 7;
    // g.Edge[4][1] = 3;
    // g.Edge[4][2] = 9;
    // g.Edge[4][3] = 2;

    // // 运行Dijkstra算法，假设从顶点0开始
    // Dijkstra(&g, 0);
    ALGraph g;
    g.vexnum = 5; // 设置图的顶点数
    g.arcnum = 7; // 设置图的边数

    // 初始化图的顶点
    for (int i = 0; i < g.vexnum; i++) {
        g.vertices[i].data = 'A' + i; // 顶点命名为A, B, C, D, E...
        g.vertices[i].first = NULL;   // 初始化无边
    }

    // 添加边
    AddEdge(&g, 0, 1, 10); // A -> B
    AddEdge(&g, 0, 4, 5);  // A -> E
    AddEdge(&g, 1, 2, 1);  // B -> C
    AddEdge(&g, 2, 3, 4);  // C -> D
    AddEdge(&g, 3, 0, 7);  // D -> A
    AddEdge(&g, 4, 1, 3);  // E -> B
    AddEdge(&g, 4, 2, 9);  // E -> C
    AddEdge(&g, 4, 3, 2);  // E -> D

    // 运行Dijkstra算法，假设从顶点0(A)开始
    Dijkstra_L(&g, 1);
    return 0;
}
