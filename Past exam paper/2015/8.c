#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
#define INF INT_MAX

typedef struct Graph {
    int vertex[MAXSIZE];
    int edge[MAXSIZE][MAXSIZE];
    int v_num, e_num;
} Graph;

int minDist(int dist[], bool sptSet[], int V) {
    int min = INF;
    int min_INdex = -1;
    for (int i = 0; i < V; i++) {
        if (sptSet[i] != true && dist[i] < min) {
            min = dist[i];
            min_INdex = i;
        }
    }
    return min_INdex;
}

void printPath(int prev[], int i) {
    if (prev[i] == -1) {
        printf("%d ", i);
        return;
    }
    printPath(prev, prev[i]);
    printf("->%d", i);
}

void printSolution(int dist[], int prev[], int V, int src) {
    printf("");
    for (int i = 0; i < V; i++) {
        printf("%d到%d的距离为：%d ;", i, src, dist[i]);
        printPath(prev, i);
        printf("\n");
    }
}

void Dijkstra(Graph g, int src) {
    int V = g.v_num;
    int dist[MAXSIZE] = {INF};
    bool sptSet[MAXSIZE] = {false};
    int prev[MAXSIZE] = {-1};

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && g.edge[u][v] != 0 && dist[u] + g.edge[u][v] < dist[v]) {
                dist[v] = dist[u] + g.edge[u][v];
                prev[v] = u;
            }
        }
    }

    printSolution(dist, prev, V, src);
}

int main() {
    return 0;
}