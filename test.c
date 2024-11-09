#include <limits.h>
#include <stdio.h>

#define MAXVERTEXNUM 100
#define INFINITY INT_MAX  // 定义 INFINITY 为一个很大的整数表示无穷大

typedef struct {
    char Vex[MAXVERTEXNUM];                // 顶点数组
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 邻接矩阵
    int vexnum, edgenum;                   // 顶点数和边数
} AMGraph;

void PrimAM(AMGraph *G, int start) {
    int lowcost[MAXVERTEXNUM];  // 存储最小代价
    int closest[MAXVERTEXNUM];  // 存储相应的最小代价边的另一个端点
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
        if (minid != -1) {
            printf("边: %c - %c, 权值: %d\n", G->Vex[closest[minid]], G->Vex[minid], min);
        }

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

int main() {
    AMGraph graph;

    // 初始化图的顶点数和边数
    graph.vexnum = 5;
    graph.edgenum = 7;

    // 顶点名称
    graph.Vex[0] = 'A';
    graph.Vex[1] = 'B';
    graph.Vex[2] = 'C';
    graph.Vex[3] = 'D';
    graph.Vex[4] = 'E';

    // 初始化邻接矩阵
    for (int i = 0; i < graph.vexnum; i++) {
        for (int j = 0; j < graph.vexnum; j++) {
            if (i == j) {
                graph.Edge[i][j] = 0;  // 对角线为0
            } else {
                graph.Edge[i][j] = INFINITY;  // 其他位置初始化为无穷大
            }
        }
    }

    // 设置边的权值
    graph.Edge[0][1] = 2;
    graph.Edge[0][3] = 6;
    graph.Edge[1][2] = 3;
    graph.Edge[1][3] = 8;
    graph.Edge[1][4] = 5;
    graph.Edge[2][4] = 7;
    graph.Edge[3][4] = 9;

    // 对称赋值，因为是无向图
    for (int i = 0; i < graph.vexnum; i++) {
        for (int j = i + 1; j < graph.vexnum; j++) {
            graph.Edge[j][i] = graph.Edge[i][j];
        }
    }

    // 调用Prim算法，假设从顶点A（下标0）开始
    printf("最小生成树的边及权重：\n");
    PrimAM(&graph, 0);

    return 0;
}
