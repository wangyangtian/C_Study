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

void initHuff(Huff *h, int a[], int len) {
    for (int i = 0; i < len; i++) {
        h[i].data = a[i];
        h[i].lchild = h[i].rchild = -1;
        h[i].parent = -1;
    }

    for (int i = len; i < 2 * len - 1; i++) {
        h[i].lchild = h[i].rchild = -1;
        h[i].parent = -1;
    }
}

int findMin(Huff *h, int len) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < len; i++) {
        if (h[i].data < min && h[i].parent == -1) {
            min = h[i].data;
            minIndex = i;
        }
    }
    return minIndex;
}

void creatHuff(Huff *h, int a[], int len) {
    for (int i = len; i < len * 2 - 1; i++) {
        int m1 = findMin(h, i);
        h[m1].parent = i;
        int m2 = findMin(h, i);
        h[m2].parent = i;
        h[i].lchild = m1;
        h[i].rchild = m2;
        h[i].data = h[m1].data + h[m2].data;
    }
}

int main() {
    return 0;
}