#include <stdio.h>
#include <limits.h> // 包含INT_MAX用于表示无穷大

#define MAXVERTEXNUM 100
#define INFINITY INT_MAX // 用于表示无穷大

// 图的邻接矩阵定义
typedef struct {
    int vexnum;                  // 顶点数
    int arcnum;                  // 边数
    int Vex[MAXVERTEXNUM];       // 顶点数组
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM]; // 邻接矩阵
} AMGraph;

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

int main() {
    AMGraph g;
    g.vexnum = 8;  // 设置图的顶点数
    g.arcnum = 10;  // 设置图的边数

    // 初始化邻接矩阵
    for (int i = 0; i < g.vexnum; i++) {
        g.Vex[i]=i;
        for (int j = 0; j < g.vexnum; j++) {
            g.Edge[i][j] = INFINITY;  // 无边的情况
        }
    }

    // 设置边的权值
    g.Edge[0][1] = g.Edge[1][0] = 1;
    g.Edge[0][4] = g.Edge[4][0] = 1;
    g.Edge[1][5] = g.Edge[5][1] = 1;
    g.Edge[2][5] = g.Edge[5][2] = 1;
    g.Edge[5][6] = g.Edge[6][5] = 1;
    g.Edge[2][3] = g.Edge[3][2] = 1;
    g.Edge[6][3] = g.Edge[3][6] = 1;
    g.Edge[7][3] = g.Edge[3][7] = 1;
    g.Edge[6][7] = g.Edge[7][6] = 1;
    g.Edge[6][2] = g.Edge[2][6] = 1;
    // 假设从顶点0开始
    PrimAM(&g, 0);

    return 0;
}
