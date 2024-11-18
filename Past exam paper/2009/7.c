#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Huff {
    int data;
    int parent;
    int lchild, rchild;
} Huff;

void InitHuff(Huff *h, int *a, int len) {
    for (int i = 0; i < len; i++) {
        h[i].data = a[i];
        h[i].parent = -1;
        h[i].lchild = h[i].rchild = -1;
    }
    for (int i = len; i < 2 * len - 1; i++) {
        h[i].parent = -1;
        h[i].lchild = h[i].rchild = -1;
    }
}

int findMin(Huff *h, int len) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < len; i++) {
        if (h[i].data < min && h[i].parent == -1) {
            min = h[i].data;
            min_index = i;
        }
    }
    return min_index;
}

void creatHuff(Huff *h, int len) {
    for (int i = len; i < 2 * len - 1; i++) {
        int lchild = findMin(h, i);
        h[lchild].parent = i;
        int rchild = findMin(h, i);
        h[rchild].parent = i;

        h[i].data = h[lchild].data + h[rchild].data;
        h[i].lchild = lchild;
        h[i].rchild = rchild;
    }
}

int main() {
    return 0;
}