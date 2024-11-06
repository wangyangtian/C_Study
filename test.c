#include <limits.h>
#include <stdio.h>

#define MAXVERTEXNUM 100  // 最大顶点数
#define INFINITY INT_MAX  // 表示无穷大

typedef struct {
    char Vex[MAXVERTEXNUM];                // 顶点表
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 邻接矩阵，边权值表
    int vexnum, arcnum;                    // 当前顶点数和边数
} AMGraph;

void Dijkstra(AMGraph *G, int start, int dist[], int path[]) {
    int visited[MAXVERTEXNUM] = {0};  // 记录顶点是否已访问
    for (int i = 0; i < G->vexnum; i++) {
        dist[i] = G->Edge[start][i];                                // 初始化从start到各点的最短路径
        path[i] = (dist[i] < INFINITY && i != start) ? start : -1;  // 初始化路径
    }
    dist[start] = 0;     // 起点到自身的距离为0
    visited[start] = 1;  // 标记起点已访问

    for (int i = 1; i < G->vexnum; i++) {  // 对每个顶点，执行一次
        int min = INFINITY;
        int u = -1;

        // 找到未访问节点中dist值最小的顶点
        for (int j = 0; j < G->vexnum; j++) {
            if (!visited[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }

        if (u == -1)
            break;       // 如果没有找到，退出
        visited[u] = 1;  // 标记u已访问

        // 更新从u出发到其他未访问顶点的最短路径
        for (int v = 0; v < G->vexnum; v++) {
            if (!visited[v] && G->Edge[u][v] < INFINITY && dist[u] + G->Edge[u][v] < dist[v]) {
                dist[v] = dist[u] + G->Edge[u][v];
                path[v] = u;
            }
        }
    }
}

// 打印最短路径和距离
void printPath(int start, int dist[], int path[], int vexnum) {
    for (int i = 0; i < vexnum; i++) {
        if (dist[i] == INFINITY) {
            printf("No path from %d to %d\n", start, i);
        } else {
            printf("Shortest path from %d to %d: ", start, i);
            int stack[MAXVERTEXNUM], top = 0;
            int u = i;
            while (u != -1) {
                stack[top++] = u;
                u = path[u];
            }
            while (top > 0) {
                printf("%d ", stack[--top]);
            }
            printf("with distance %d\n", dist[i]);
        }
    }
}

int main() {
    AMGraph G;
    G.vexnum = 5;
    G.arcnum = 10;  // 边数不用于此代码，但可以根据需要设置

    // 初始化邻接矩阵
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.Edge[i][j] = (i == j) ? 0 : INFINITY;
        }
    }

    // 添加边及权重
    G.Edge[0][1] = 10;
    G.Edge[0][4] = 5;
    G.Edge[1][2] = 1;
    G.Edge[1][4] = 2;
    G.Edge[2][3] = 4;
    G.Edge[3][0] = 7;
    G.Edge[3][2] = 6;
    G.Edge[4][1] = 3;
    G.Edge[4][2] = 9;
    G.Edge[4][3] = 2;

    int dist[MAXVERTEXNUM], path[MAXVERTEXNUM];
    Dijkstra(&G, 0, dist, path);
    printPath(0, dist, path, G.vexnum);

    return 0;
}
