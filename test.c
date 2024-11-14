#include <limits.h>
#include <stdio.h>

#define MAXSIZE 100
#define INF INT_MAX

typedef struct Graph {
    int vertex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
    int v_num, e_num;
} Graph;

// Dijkstra 算法
void Dijkstra(Graph *g, int start) {
    int dist[MAXSIZE];           // 最短路径数组
    int visited[MAXSIZE] = {0};  // 访问标记数组
    int i, j;

    // 初始化距离数组，所有距离初始为无穷大，起点到自己的距离为0
    for (i = 0; i < g->v_num; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    // 执行 Dijkstra 算法
    for (i = 0; i < g->v_num; i++) {
        int min_dist = INF, u = -1;

        // 找到未访问的最小距离的节点
        for (j = 0; j < g->v_num; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        // 标记节点 u 为已访问
        visited[u] = 1;

        // 更新 u 相邻节点的最短距离
        for (j = 0; j < g->v_num; j++) {
            if (g->edge[u][j] != INF && dist[u] + g->edge[u][j] < dist[j]) {
                dist[j] = dist[u] + g->edge[u][j];
            }
        }
    }

    // 输出从起点到各个节点的最短路径
    printf("Shortest distances from vertex %d:\n", start);
    for (i = 0; i < g->v_num; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d: No path\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    // 创建一个简单的图
    Graph g = {
        .v_num = 5, .e_num = 8, .edge = {{INF, 10, INF, INF, INF}, {10, INF, 5, INF, INF}, {INF, 5, INF, 2, 1}, {INF, INF, 2, INF, 3}, {INF, INF, 1, 3, INF}}};

    // 计算从顶点 0 开始的最短路径
    Dijkstra(&g, 0);

    return 0;
}
