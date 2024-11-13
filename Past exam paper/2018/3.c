#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Huff {
    int weight;
    int parent;
    int lchild, rchild;
} Huff;

int findMin(Huff *h, int len) {
    int min = INT_MAX;
    int minid = -1;
    for (int i = 0; i < len; i++) {
        if (h[i].parent == -1 && h[i].weight < min) {
            min = h[i].weight;
            minid = i;
        }
    }
    return minid;
}

void initHuff(Huff *h, int *arr, int len) {
    for (int i = 0; i < len; i++) {
        h[i].weight = arr[i];
        h[i].lchild = h[i].rchild = h[i].parent = -1;
    }

    for (int i = len; i < 2 * len - 1; i++) {
        h[i].lchild = h[i].rchild = h[i].parent = -1;
    }
}

void createHuff(Huff *h, int len) {
    for (int i = len; i < 2 * len - 1; i++) {
        int m1 = findMin(h, i);
        h[m1].parent = i;
        int m2 = findMin(h, i);
        h[m2].parent = i;

        h[i].weight = h[m1].weight + h[m2].weight;
        h[i].lchild = m1;
        h[i].rchild = m2;
    }
}

void encoding(Huff *h, int len, int index, char *code) {
    if (h[index].lchild == -1 && h[index].rchild == -1) {
        code[len] = '\0';
        printf("Character with weight %d--code: %s\n", h[index].weight, code);
        return;
    }
    if (h[index].lchild != -1) {
        code[len] = '0';
        encoding(h, len + 1, h[index].lchild, code);
    }
    if (h[index].rchild != -1) {
        code[len] = '1';
        encoding(h, len + 1, h[index].rchild, code);
    }
}

int main() {
    int data[] = {2, 5, 7, 9, 13};
    int len = sizeof(data) / sizeof(data[0]);
    Huff *h = (Huff *)malloc(sizeof(Huff) * (2 * len - 1));
    initHuff(h, data, len);
    createHuff(h, len);
    // 验证输出
    for (int i = 0; i < 2 * len - 1; i++) {
        printf("节点 %d: weight = %d, parent = %d, lchild = %d, rchild = %d\n",
               i + 1, h[i].weight, h[i].parent, h[i].lchild, h[i].rchild);
    }

    char code[100];
    encoding(h, 0, 8, code);
    free(h);
    return 0;
}