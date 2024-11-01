#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define V 5
#define INF 10000

void Floyd(int g[V][V], int dist[V][V]) {
    // 初始化最短路径矩阵dist为原图的邻接矩阵graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = g[i][j];
        }
    }

    // 更新dist矩阵，逐步求出所有点对的最短路径
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// 找到医院的最佳选址
int FindBest(int dist[V][V]) {
    int minPath = INF;
    int bestLoc = -1;
    int bestTotalPath = INF;

    for (int i = 0; i < V; i++) {
        int maxReturnPath = 0;
        int totalPath = 0;

        for (int j = 0; j < V; j++) {
            if (j != i) {
                int returnPath = dist[i][j] + dist[j][i];
                if (returnPath >= INF)
                    returnPath = INF;
                if (returnPath > maxReturnPath)
                    maxReturnPath = returnPath;
                totalPath += returnPath;
            }
        }

        if ((maxReturnPath < minPath) || ((maxReturnPath == minPath) && totalPath < bestTotalPath)) {
            minPath = maxReturnPath;
            bestTotalPath = totalPath;
            bestLoc = i;
        }
    }

    printf("最佳医院选址应在节点：%d\n", bestLoc + 1);
    printf("最长往返路程为：%d\n总往返路程为：%d\n", minPath, bestTotalPath);
    return bestLoc;
}

int main() {
    // 初始化邻接矩阵
    int graph[V][V] = {
        {0, 13, INF, 4, INF},
        {13, 0, 15, INF, 5},
        {INF, INF, 0, 12, INF},
        {4, INF, 12, 0, INF},
        {INF, INF, 6, 3, 0}};
    // 计算每一对结点的最短路径
    int dist[V][V];
    Floyd(graph, dist);

    // 找到最佳结点
    int bestNode = FindBest(dist);
    return 0;
}