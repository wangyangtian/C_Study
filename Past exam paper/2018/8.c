#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point {
    int p_id;
    double x;
    double y;
    double z;
    struct Point *next;
} Point;

typedef struct Tri {
    int t_id;
    int p1_id, p2_id, p3_id;
    struct Tri *next;
} Tri;

typedef struct Edge {
    int e_id;
    int p1_id, p2_id;
    int adj_t1_id, adj_t2_id;
    struct Edge *next;
} Edge;

int main() {
    return 0;
}