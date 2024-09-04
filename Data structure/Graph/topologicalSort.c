// 拓扑排序
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERTEXNUM 100
typedef struct AMGraph {
    char Vex[VERTEXNUM];
    int Edge[VERTEXNUM][VERTEXNUM];
    int vexnum, arcnum;
} AMGraph;

typedef struct ArcNode {
    int Adjvex;
    struct ArcNode* next;
    int weight;
} ArcNode;

typedef struct VexNode {
    char data;
    ArcNode* first;
} VexNode, AdjList[VERTEXNUM];

typedef struct ALGraph {
    AdjList vertices;
    int arcnum, vexnum;
} ALGraph;

typedef struct Stack {
    int data[VERTEXNUM];
    int top;
} Stack;

void InitStack(Stack* s) {
    s->top = -1;
}

bool IsEmpty(Stack s) {
    return s.top == -1;
}

bool Push(Stack* s, int elem) {
    if (s->top == VERTEXNUM - 1)
        return false;
    s->data[++(s->top)] = elem;
    return true;
}

bool Pop(Stack* s, int* elem) {
    if (s->top == -1)
        return false;
    *elem = s->data[(s->top)--];
    return true;
}

// 拓扑排序算法
bool TopologicalSort(AMGraph* g) {
    int inDegree[VERTEXNUM] = {0};  // 入度数组，用于存储每个顶点的入度
    int sorted[VERTEXNUM];          // 存储拓扑排序的结果
    int index = 0;                  // 结果数组的索引
    int t;                          // 临时变量，用于存储出栈元素
    Stack s;
    InitStack(&s);

    // 计算每个顶点的入度
    for (int i = 0; i < g->vexnum; i++) {
        for (int j = 0; j < g->vexnum; j++) {
            if (g->Edge[i][j] != 0) // 如果存在边（权重不为0），则增加入度
                inDegree[j]++;
        }
    }

    // 将所有入度为 0 的顶点压入栈中
    for (int i = 0; i < g->vexnum; i++) {
        if (inDegree[i] == 0)
            Push(&s, i);
    }

    // 进行拓扑排序
    while (!IsEmpty(s)) {
        Pop(&s, &t);            // 从栈中弹出一个入度为 0 的顶点
        sorted[index++] = t;    // 将该顶点加入排序结果

        // 更新所有与该顶点相连的顶点的入度
        for (int i = 0; i < g->vexnum; i++) {
            if (g->Edge[t][i] != 0) { // 如果存在边
                inDegree[i]--;        // 相连顶点入度减 1
                if (inDegree[i] == 0) // 如果入度变为 0，则压入栈中
                    Push(&s, i);
            }
        }
    }

    // 检查是否完成拓扑排序，若未排序完所有顶点，则说明存在环
    if (index != g->vexnum) {
        printf("该图存在环，无法进行拓扑排序！\n");
        return false;
    }

    // 打印拓扑排序结果
    printf("拓扑排序结果: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", sorted[i]); // 输出排序结果
    }
    printf("\n");
    return true;
}

bool TopologicalSort_AL(ALGraph* g) {
    int inDegree[VERTEXNUM] = {0};  // 入度数组
    int sorted[VERTEXNUM];          // 存储拓扑排序的结果
    int index = 0;                  // 结果数组的索引
    int t;                          // 临时变量，用于存储出栈元素
    Stack s;
    InitStack(&s);

    // 计算每个顶点的入度
    for (int i = 0; i < g->vexnum; i++) {
        ArcNode* p = g->vertices[i].first;
        while (p != NULL) {
            inDegree[p->Adjvex]++;  // 正确计算入度
            p = p->next;
        }
    }

    // 将所有入度为 0 的顶点压入栈中
    for (int i = 0; i < g->vexnum; i++) {
        if (inDegree[i] == 0)
            Push(&s, i);
    }

    // 进行拓扑排序
    while (!IsEmpty(s)) {
        Pop(&s, &t);               // 从栈中弹出一个入度为 0 的顶点
        sorted[index++] = t;       // 将该顶点加入排序结果
        ArcNode* p = g->vertices[t].first;

        // 遍历该顶点的邻接点，更新入度
        while (p != NULL) {
            inDegree[p->Adjvex]--; // 相连顶点入度减 1
            if (inDegree[p->Adjvex] == 0) // 如果入度变为 0，则压入栈中
                Push(&s, p->Adjvex);
            p = p->next;           // 移动到下一个邻接点
        }
    }

    // 检查是否完成拓扑排序，若未排序完所有顶点，则说明存在环
    if (index != g->vexnum) {
        printf("该图存在环，无法进行拓扑排序！\n");
        return false;
    }

    // 打印拓扑排序结果
    printf("拓扑排序结果: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", sorted[i]);  // 输出排序结果
    }
    printf("\n");
    return true;
}

// 创建边并添加到邻接表
void AddEdge(ALGraph* g, int start, int end) {
    ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
    newNode->Adjvex = end;
    newNode->next = g->vertices[start].first;
    g->vertices[start].first = newNode;
}

int main() {
    // AMGraph G;
    // G.vexnum = 6;  // 假设图有 6 个顶点
    // // 初始化邻接矩阵，示例图的邻接关系
    // int adjMatrix[6][6] = {
    //     {0, 1, 1, 0, 0, 0}, 
    //     {0, 0, 0, 1, 1, 0},
    //     {0, 0, 0, 1, 0, 0}, 
    //     {0, 0, 0, 0, 0, 1},
    //     {0, 0, 0, 0, 0, 1}, 
    //     {0, 0, 0, 0, 0, 0}
    // };

    // // 将邻接矩阵赋值给图
    // for (int i = 0; i < G.vexnum; i++) {
    //     for (int j = 0; j < G.vexnum; j++) {
    //         G.Edge[i][j] = adjMatrix[i][j];
    //     }
    // }

    // // 进行拓扑排序
    // TopologicalSort(&G);


    ALGraph G;
    G.vexnum = 6;  // 假设图有 6 个顶点
    G.arcnum = 6;  // 假设图有 6 条边

    // 初始化顶点
    for (int i = 0; i < G.vexnum; i++) {
        G.vertices[i].data = 'A' + i;  // 顶点名称
        G.vertices[i].first = NULL;    // 邻接点初始化为空
    }

    // 添加边到图中
    AddEdge(&G, 0, 1); // A -> B
    AddEdge(&G, 0, 2); // A -> C
    AddEdge(&G, 1, 3); // B -> D
    AddEdge(&G, 1, 4); // B -> E
    AddEdge(&G, 2, 3); // C -> D
    AddEdge(&G, 3, 5); // D -> F
    AddEdge(&G, 4, 5); // E -> F

    // 进行拓扑排序
    TopologicalSort_AL(&G);

    // 释放所有动态分配的内存
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].first;
        while (p != NULL) {
            ArcNode* temp = p;
            p = p->next;
            free(temp);
        }
    }
    return 0;
}