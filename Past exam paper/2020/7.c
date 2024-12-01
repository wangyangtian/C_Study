#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
#define INFINITY INT_MAX

// 邻接表存储结构
typedef struct ArcNode {
    int adjvex;            // 终点索引
    int weight;            // 边的权重
    struct ArcNode* next;  // 指向下一条边
} ArcNode;

typedef struct VNode {
    char data;          // 顶点数据
    ArcNode* firstArc;  // 指向边表的头指针
} VNode;

typedef struct ALGraph {
    VNode vertices[MAXVEX];  // 顶点数组
    int vnum, arcnum;        // 顶点数和边数
} ALGraph;

// 初始化图
void initGraph(ALGraph* graph, int vnum) {
    graph->vnum = vnum;
    graph->arcnum = 0;
    for (int i = 0; i < vnum; i++) {
        graph->vertices[i].data = 0;         // 初始化顶点数据
        graph->vertices[i].firstArc = NULL;  // 初始化边表为空
    }
}

// 添加边
void addEdge(ALGraph* graph, int start, int end, int weight) {
    ArcNode* newArc = (ArcNode*)malloc(sizeof(ArcNode));
    newArc->adjvex = end;
    newArc->weight = weight;
    newArc->next = graph->vertices[start].firstArc;
    graph->vertices[start].firstArc = newArc;
    graph->arcnum++;
}

// Dijkstra 算法
void dijkstra(ALGraph* graph, int start, int dist[], int path[]) {
    int vnum = graph->vnum;
    int visited[MAXVEX] = {0};  // 访问标记

    // 初始化
    for (int i = 0; i < vnum; i++) {
        dist[i] = INFINITY;  // 最短距离初值为无穷大
        path[i] = -1;        // 前驱结点初始化为 -1
    }
    dist[start] = 0;  // 起点到自身的距离为 0

    // 主循环：每次找到未访问顶点中距离最小的顶点
    for (int i = 0; i < vnum; i++) {
        int minDist = INFINITY;
        int u = -1;

        for (int j = 0; j < vnum; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;       // 所有可达顶点已访问
        visited[u] = 1;  // 标记 u 为已访问

        // 更新 u 的邻接顶点的最短距离
        for (ArcNode* arc = graph->vertices[u].firstArc; arc != NULL; arc = arc->next) {
            int v = arc->adjvex;
            if (!visited[v] && dist[u] + arc->weight < dist[v]) {
                dist[v] = dist[u] + arc->weight;  // 更新最短距离
                path[v] = u;                      // 记录前驱结点
            }
        }
    }
}

// 打印最短路径
void printPath(int start, int end, int path[]) {
    if (end == start) {
        printf("%d ", start);
        return;
    }
    if (path[end] == -1) {
        printf("No path from %d to %d\n", start, end);
        return;
    }
    printPath(start, path[end], path);
    printf("%d ", end);
}

// 主函数
int main() {
    ALGraph graph;
    initGraph(&graph, 5);  // 初始化 5 个顶点的图

    // 添加边
    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 3, 30);
    addEdge(&graph, 0, 4, 100);
    addEdge(&graph, 1, 2, 50);
    addEdge(&graph, 2, 4, 10);
    addEdge(&graph, 3, 2, 20);
    addEdge(&graph, 3, 4, 60);

    int dist[MAXVEX];
    int path[MAXVEX];

    // 计算从顶点 0 到其他顶点的最短路径
    dijkstra(&graph, 0, dist, path);

    // 输出结果
    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < graph.vnum; i++) {
        printf("%d\t%d\t\t\t", i, dist[i]);
        printPath(0, i, path);
        printf("\n");
    }

    return 0;
}
