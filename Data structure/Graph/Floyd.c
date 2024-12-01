#include <stdio.h>

#define MAXVERTEXNUM 100  // 最大顶点数
#define INF 100000        // 用于表示无穷大的值

// 图的结构定义
typedef struct AMGraph {
    char Vex[MAXVERTEXNUM];                // 顶点表
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 邻接矩阵，边表
    int vexnum, arcnum;                    // 当前顶点数和弧数
} AMGraph;

// Floyd算法实现
void Floyd(AMGraph *G, int D[][MAXVERTEXNUM], int Path[][MAXVERTEXNUM]) {
    int i, j, k;

    // 初始化D和Path数组
    for (i = 0; i < G->vexnum; i++) {
        for (j = 0; j < G->vexnum; j++) {
            D[i][j] = G->Edge[i][j];  // D数组存储最短路径长度
            Path[i][j] = -1;          // 设为-1
        }
    }

    // 三重循环更新最短路径
    for (k = 0; k < G->vexnum; k++) {
        for (i = 0; i < G->vexnum; i++) {
            for (j = 0; j < G->vexnum; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];  // 更新最短路径长度
                    Path[i][j] = k;               // 更新路径
                }
            }
        }
    }
}

// 打印最短路径矩阵
void PrintspMatrix(int D[][MAXVERTEXNUM], int vexnum) {
    printf("最短路径矩阵:\n");
    for (int i = 0; i < vexnum; i++) {
        for (int j = 0; j < vexnum; j++) {
            if (D[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

// 打印从顶点 u 到 v 的路径
void PrintPath(int u, int v, int path[][MAXVERTEXNUM], int D[][MAXVERTEXNUM]) {
    if (D[u][v] == INF) {
        printf("从 %d 到 %d 没有路径\n", u, v);  // 如果没有路径
        return;
    } else {
        if (path[u][v] == -1)
            printf("<%d, %d> ", u, v);  // 直接路径
        else {
            int intermediate = path[u][v];
            PrintPath(u, intermediate, path, D);  // 打印从 u 到中间节点的路径
            PrintPath(intermediate, v, path, D);  // 打印从中间节点到 v 的路径
        }
    }
}

int main() {
    AMGraph G;
    int i, j;

    // 初始化图的顶点数和边数
    G.vexnum = 4;  // 例如4个顶点
    G.arcnum = 5;  // 例如5条边

    // 初始化顶点表
    G.Vex[0] = 'A';
    G.Vex[1] = 'B';
    G.Vex[2] = 'C';
    G.Vex[3] = 'D';

    // 初始化邻接矩阵
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            if (i == j)
                G.Edge[i][j] = 0;  // 自己到自己距离为0
            else
                G.Edge[i][j] = INF;  // 其他初始化为无穷大
        }
    }

    // 添加图中的边及权重
    G.Edge[0][1] = 2;  // A -> B 距离为2
    G.Edge[0][2] = 6;  // A -> C 距离为6
    G.Edge[1][2] = 3;  // B -> C 距离为3
    G.Edge[1][3] = 8;  // B -> D 距离为8
    G.Edge[2][3] = 1;  // C -> D 距离为1

    int D[MAXVERTEXNUM][MAXVERTEXNUM];     // 存储最短路径长度
    int Path[MAXVERTEXNUM][MAXVERTEXNUM];  // 存储路径信息

    // 调用Floyd算法
    Floyd(&G, D, Path);

    // 打印最短路径矩阵
    PrintspMatrix(D, G.vexnum);
    printf("\n");
    PrintPath(0, 3, Path, D);
    return 0;
}
