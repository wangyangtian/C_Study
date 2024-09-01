#include <stdio.h>
#include <stdlib.h>

#define MAXVERTEXNUM 100 // 最大顶点数

typedef struct {
    int numVertices; // 顶点数
    int adjMatrix[MAXVERTEXNUM][MAXVERTEXNUM]; // 邻接矩阵
} Graph;

// 栈结构，用于存储排序结果
typedef struct {
    int data[MAXVERTEXNUM];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 入栈
void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

// 出栈
int pop(Stack* stack) {
    if (stack->top == -1) return -1; // 栈空检查
    return stack->data[stack->top--];
}

// 检查栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// DFS 递归函数
void dfs(int v, int visited[], Stack* stack, Graph* G) {
    visited[v] = 1; // 标记为已访问
    for (int i = 0; i < G->numVertices; i++) {
        // 如果存在边且目标顶点未被访问，递归访问
        if (G->adjMatrix[v][i] != 0 && !visited[i]) {
            dfs(i, visited, stack, G);
        }
    }
    push(stack, v); // 当前顶点访问完成后入栈
}

// 基于 DFS 的拓扑排序
void topologicalSortDFS(Graph* G) {
    Stack stack;
    initStack(&stack);

    int visited[MAXVERTEXNUM] = {0}; // 访问标记数组

    // 对所有顶点执行 DFS
    for (int i = 0; i < G->numVertices; i++) {
        if (!visited[i]) {
            dfs(i, visited, &stack, G);
        }
    }

    // 打印拓扑排序结果
    printf("拓扑排序结果: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

// 主函数示例
int main() {
    Graph G;
    G.numVertices = 6; // 假设图有 6 个顶点
    // 初始化邻接矩阵，示例图
    int adjMatrix[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    // 将邻接矩阵赋值给图
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.adjMatrix[i][j] = adjMatrix[i][j];
        }
    }

    // 进行拓扑排序
    topologicalSortDFS(&G);

    return 0;
}
