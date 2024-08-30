#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVERTEXNUM 100
#define INFINITY INT_MAX

typedef struct AMGraph  // 邻接矩阵(Adjacency Matrix Graph)
{
    char Vex[MAXVERTEXNUM];                // 顶点表
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];  // 邻接矩阵，边表
    int vexnum, arcnum;                    // 当前顶点数和弧数
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

typedef struct LinkQueue {
    int data;
    struct LinkQueue* next;
} LinkNode;
typedef struct  // 链队类型定义
{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue* q) {  // 初始化队列
    q->front = q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    q->front->next = NULL;
}

void EnQueue(LinkQueue* q, int elem) {  // 带头结点的入队
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = elem;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
}

bool DeQueue(LinkQueue* q, int* elem) {  // 带头结点的出队
    if (q->front == q->rear)
        return false;
    LinkNode* p = q->front->next;
    *elem = p->data;
    q->front->next = p->next;
    if (q->rear == p)  // 最后一次出队，修改rear指针
        q->rear = q->front;
    free(p);
}

// 判断队列是否为空
bool IsQueueEmpty(LinkQueue q) {
    return q.front == q.rear;
}

void visit(int v) {}

// 判断图G中是否存在边<x, y>或(x, y)
bool Adjacent(AMGraph g, int x, int y) {
    return g.Edge[x][y] != 0 && g.Edge[x][y] != INFINITY;
}

// Neighbors: 列出图G中与结点x邻接的边
void Neighbors(AMGraph G, int x) {
    printf("Neighbors of vertex %d: ", x);
    for (int i = 0; i < G.vexnum; i++) {
        if (G.Edge[x][i] != 0 && G.Edge[x][i] != INFINITY) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// InsertVertex: 在图G中插入顶点x
bool InsertVertex(AMGraph* g, char x) {
    if (g->vexnum < MAXVERTEXNUM) {
        g->Vex[g->vexnum++] = x;
        for (int i = 0; i < g->vexnum; i++) {
            g->Edge[g->vexnum - 1][i] = INFINITY;
            g->Edge[i][g->vexnum - 1] = INFINITY;
        }
        return true;
    } else {
        printf("Graph has reached its maximum capacity!\n");
        return false;
    }
}

// RemoveEdge: 在图G中删除边<x, y>
bool RemoveEdge(AMGraph* g, int x, int y) {
    if ((x >= 0 && x < g->vexnum) && (y >= 0 && y < g->vexnum)) {
        g->Edge[x][y] = INFINITY;
        g->arcnum--;
        return true;
    } else
        return false;
}

// FirstNeighbor: 返回图G中顶点x的第一个邻接点
int FirstNeighbor(AMGraph g, int x) {
    if (x >= MAXVERTEXNUM)
        return -1;
    for (int i = 0; i < MAXVERTEXNUM; i++) {
        if (g.Edge[x][i] != 0 && g.Edge[x][i] != INFINITY)
            return i;
    }
    return -1;
}

int FirstNeighbor2(ALGraph g, int x) {
    ArcNode* p = g.vertices[x].first;
    if (p != NULL) {
        return p->adjvex;
    }
    return -1; // 没有邻接点时返回 -1
}

// NextNeighbor: 返回图G中顶点x的下一个邻接点，假设y是一个已知的邻接点
int NextNeighbor(AMGraph g, int x, int y) {
    for (int i = y + 1; i < g.vexnum; i++) {
        if (g.Edge[x][i] != 0 && g.Edge[x][i] != INFINITY)
            return i;
    }
    return -1;
}

int NextNeighbor_L(ALGraph g, int x, int y) {
    ArcNode* p = g.vertices[x].first;
    while (p != NULL) {
        if (p->adjvex == y) {
            if (p->next != NULL) {
                return p->next->adjvex;
            }
        }
        p = p->next;
    }
    return -1; // 没有下一个邻接点时返回 -1
}

// Get_edge_value: 获取图中边<x, y>的权值
int Get_edge_value(AMGraph G, int x, int y) {
    if (x >= 0 && x < G.vexnum && y >= 0 && y < G.vexnum) {
        return G.Edge[x][y];
    }
    return INFINITY;  // 返回无穷大表示不存在该边
}

// Set_edge_value: 设置图G中边<x, y>的权值为v
void Set_edge_value(AMGraph* G, int x, int y, int v) {
    if (x >= 0 && x < G->vexnum && y >= 0 && y < G->vexnum) {
        G->Edge[x][y] = v;
    } else {
        printf("Invalid vertices!\n");
    }
}

void BFS(AMGraph g, int v, bool Visited[]) {
    LinkQueue q;  // 定义一个队列用于存储待访问的顶点
    int e;  // 用于保存从队列中取出的顶点
    InitQueue(&q);  // 初始化队列
    visit(v);  // 访问初始顶点v
    Visited[v] = true;  // 标记顶点v已被访问
    EnQueue(&q, v);  // 将顶点v入队

    while (!IsQueueEmpty(q)) {  // 当队列不为空时循环
        DeQueue(&q, &e);  // 从队列中取出一个顶点e
        for (int w = FirstNeighbor(g, e); w >= 0; w = NextNeighbor(g, e, w)) {  // 遍历顶点e的所有邻接点
            if (!Visited[w]) {  // 如果顶点w未被访问
                visit(w);  // 访问顶点w
                Visited[w] = true;  // 标记顶点w已被访问
                EnQueue(&q, w);  // 将顶点w入队
            }
        }
    }
}

void BFS_L(ALGraph g, int v, bool Visited[]) {
    LinkQueue q;  // 定义一个队列用于存储待访问的顶点
    InitQueue(&q);  // 初始化队列
    visit(v);  // 访问初始顶点v
    Visited[v] = true;  // 标记顶点v已被访问
    EnQueue(&q, v);  // 将顶点v入队

    while (!IsQueueEmpty(q)) {  // 当队列不为空时循环
        int u;
        DeQueue(&q, &u);  // 从队列中取出一个顶点u
        ArcNode* p = g.vertices[u].first;  // 获取顶点u的第一条边
        while (p) {  // 遍历顶点u的所有邻接点
            if (!Visited[p->adjvex]) {  // 如果邻接点p->adjvex未被访问
                visit(p->adjvex);  // 访问邻接点p->adjvex
                Visited[p->adjvex] = true;  // 标记邻接点p->adjvex已被访问
                EnQueue(&q, p->adjvex);  // 将邻接点p->adjvex入队
            }
            p = p->next;  // 指向下一条弧
        }
    }
}

void BFSTraverse(AMGraph g) {   // 广度优先遍历图G，适用于非连通图
    bool Visited[MAXVERTEXNUM] = {false};  // 初始化访问标记数组，表示所有顶点都未被访问
    for (int v = 0; v < g.vexnum; v++) {  // 遍历图G中的所有顶点
        if (!Visited[v]) {  // 如果顶点v未被访问
            BFS(g, v, Visited);  // 从顶点v开始进行广度优先遍历
        }
    }
}

void DFS(AMGraph g, int v, bool Visited[]) {
    visit(v);  // 访问顶点v
    Visited[v] = true;  // 标记顶点v已被访问
    for (int w = FirstNeighbor(g, v); w >= 0; w = NextNeighbor(g, v, w)) {  // 遍历顶点v的所有邻接点
        if (!Visited[w]) {  // 如果顶点w未被访问
            DFS(g, w, Visited);  // 递归访问顶点w
        }
    }
}

void DFS_L(ALGraph g, int v, bool Visited[]) {
    visit(v);  // 访问顶点v
    Visited[v] = true;  // 标记顶点v已被访问
    ArcNode* p = g.vertices[v].first;  // 获取顶点v的第一条边
    while (p) {  // 遍历顶点v的所有邻接点
        if (!Visited[p->adjvex]) {  // 如果邻接点p->adjvex未被访问
            DFS_L(g, p->adjvex, Visited);  // 递归访问邻接点p->adjvex
        }
        p = p->next;  // 指向下一条弧
    }
}

void DFSTraverse(AMGraph g) {   // 深度优先遍历图G，适用于非连通图
    bool Visited[MAXVERTEXNUM] = {false};  // 初始化访问标记数组，表示所有顶点都未被访问
    for (int v = 0; v < g.vexnum; v++) {  // 遍历图G中的所有顶点
        if (!Visited[v]) {  // 如果顶点v未被访问
            DFS(g, v, Visited);  // 从顶点v开始进行深度优先遍历
        }
    }
}

// 使用邻接矩阵实现 Prim 算法
void PrimAM(AMGraph *G, int start)
{
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
        printf("边: %c - %c, 权值: %d\n", G->Vex[closest[minid]], G->Vex[minid], min);

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

// 查找顶点位置的辅助函数
int LocateVertex(ALGraph *G, char vertex) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == vertex)
            return i;
    }
    return -1;
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

// 递归打印路径
void PrintPath(int prev[], int i) {
    if (prev[i] == -1) {  // 递归终止条件
        printf("%d ", i);
        return;
    }
    PrintPath(prev, prev[i]);
    printf("-> %d ", i);
}
// 求顶点u 到其他顶点的最短路径
void BFS_ShortestPath(AMGraph* g, int u) {
    bool Visited[MAXVERTEXNUM] = {false};  // 是否访问标记
    int d[MAXVERTEXNUM];  // d[i] 表示从 u 到 i 结点的最短路径长度
    int path[MAXVERTEXNUM];  // path[i] 表示最短路径中每个结点的前一个结点
    LinkQueue q;
    InitQueue(&q);

    for (int i = 0; i < g->vexnum; i++) {
        d[i] = INFINITY;  // 初始化最短路径长度为无穷大
        path[i] = -1;     // 初始化前驱结点为 -1
    }
    d[u] = 0;           // 起始点到自身距离为 0
    Visited[u] = true;  // 标记起始点已访问
    EnQueue(&q, u);     // 起始点入队

    while (!IsQueueEmpty(q)) {
        int current;
        DeQueue(&q, &current);
        for (int w = FirstNeighbor(*g, current); w >= 0; w = NextNeighbor(*g, current, w)) {
            if (!Visited[w]) {
                d[w] = d[current] + 1;    // 更新最短路径长度
                path[w] = current;        // 记录前驱结点
                Visited[w] = true;  // 标记结点已访问
                EnQueue(&q, w);     // 邻接点入队
            }
        }
    }
    // 输出最短路径信息
    for (int i = 0; i < g->vexnum; i++) {
        printf("Shortest path from vertex %d to vertex %d is %d\n", u, i, d[i]);
        PrintPath(path,i);
        printf("\n");
    }
}

int main() {
    AMGraph g;
    g.vexnum = 8;  // 设置图的顶点数
    g.arcnum = 10;  // 设置图的边数

    // 初始化邻接矩阵
    for (int i = 0; i < g.vexnum; i++) {
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
    BFS_ShortestPath(&g, 0);

    return 0;
}