#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100

typedef struct Graph {
    int vertex[MAX_VERTEX];
    int edge[MAX_VERTEX][MAX_VERTEX];
    int v_num, e_num;
} Graph;

int Depth(Graph *g, int v) {
    bool visited[MAX_VERTEX] = {false};
    int queue[MAX_VERTEX];
    int depth[MAX_VERTEX] = {0};
    int front = 0, rear = 0;

    queue[rear++] = v;
    visited[v] = true;

    int maxDepth = 0;

    while (rear != front) {
        int c = queue[front++];

        for (int i = 0; i < g->v_num; i++) {
            if (g->edge[c][i] != 0 && visited[i] != true) {
                queue[rear++] = i;
                visited[i] = true;

                depth[i] = depth[c] + 1;
                maxDepth = maxDepth > depth[i] ? maxDepth : depth[i];
            }
        }
    }

    return maxDepth;
}

int MinDepth(Graph *g) {
    int min = INT_MAX;
    for (int i = 0; i < g->v_num; i++) {
        min = min < Depth(g, i) ? min : Depth(g, i);
    }
    return min;
}

int main() {
    Graph graph = {
        .vertex = {1, 2, 3, 4, 5},
        .edge = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}},
        .v_num = 5,
        .e_num = 6};

    int start = 0;
    printf("%d", MinDepth(&graph));

    return 0;
}
