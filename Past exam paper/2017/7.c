#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXZISE 100

typedef struct _MGraph {
    char vertex[MAXZISE];
    int edge[MAXZISE][MAXZISE];
    int v_num, e_num;
} MGrpah;

void BFS(MGrpah g, int start) {
    bool visited[MAXZISE] = {false};
    int queue[MAXZISE];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (rear != front) {
        int v = queue[front++];
        printf("%c ", g.vertex[v]);

        for (int i = 0; i < g.v_num; i++) {
            if (g.edge[v][i] != 0 && visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

void DFS(MGrpah g, int v, bool *visitd) {
    visitd[v] = true;
    printf("%c ", g.vertex[v]);

    for (int i = 0; i < g.v_num; i++) {
        if (g.edge[v][i] != 0 && visitd[i]) {
            DFS(g, i, visitd);
        }
    }
}

int main() {
    return 0;
}