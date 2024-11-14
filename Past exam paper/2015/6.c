#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
#define INF INT_MAX

typedef struct Graph {
    int vertex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
    int v_num, e_num;
} Graph;

// 寻找最短路径集合外的最小距离节点
int minDist(int dist[], bool sptSet[], int V) {
    int min = INF;
    int min_Index = -1;
    for (int i = 0; i < V; i++) {
        if (!sptSet[i] && dist[i] < min) {
            min = dist[i];
            min_Index = i;
        }
    }
    return min_Index;
}

// 打印路径
void printPath(int prev[], int i) {
    if (prev[i] == -1) {
        printf("%d", i);
        return;
    }
    printPath(prev, prev[i]);
    printf("->%d", i);
}

void printSolution(int dist[], int prev[], int V, int src) {
    printf("源点 %d 到各个节点的最短路径和距离：\n", src);
    for (int i = 0; i < V; i++) {
        printf("从 %d 到 %d 的最短距离为：%d ; 路径为：", src, i, dist[i]);
        printPath(prev, i);
        printf("\n");
    }
}

void Dijkstra(Graph g, int src) {
    int V = g.v_num;
    int dist[MAXSIZE];
    bool sptSet[MAXSIZE] = {false};  // 最短路径树集合
    int prev[MAXSIZE];               // 记录最短路径前驱节点

    // 初始化距离数组，所有节点的距离设为无穷大
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && g.edge[u][v] != INF && dist[u] + g.edge[u][v] < dist[v]) {
                dist[v] = dist[u] + g.edge[u][v];
                prev[v] = u;
            }
        }
    }

    printSolution(dist, prev, V, src);
}

int main() {
    // 创建一个简单的图
    Graph g = {
        .v_num = 5,
        .e_num = 8,
        .edge = {{INF, 10, INF, INF, INF},
                 {10, INF, 5, INF, INF},
                 {INF, 5, INF, 2, 1},
                 {INF, INF, 2, INF, 3},
                 {INF, INF, 1, 3, INF}}};

    // 计算从顶点 0 开始的最短路径
    Dijkstra(g, 0);

    return 0;
}
