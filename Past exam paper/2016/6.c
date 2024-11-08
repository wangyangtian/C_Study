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

void InitHuff(Huff* h, int* a, int len) {
    for (int i = 0; i < len; i++) {
        h[i].weight = a[i];
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
    for (int i = len; i < 2 * len - 1; i++) {
        h[i].weight = 0;
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
}

int findMin(Huff* h, int len) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < len; i++) {
        if (h[i].parent == -1 && h[i].weight < min) {
            min = h[i].weight;
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        h[minIndex].parent = len;
    }
    return minIndex;
}

void createHuff(Huff* h, int len) {
    for (int i = len; i < 2 * len - 1; i++) {
        int lchild = findMin(h, i);
        int rchild = findMin(h, i);

        h[i].weight = h[lchild].weight + h[rchild].weight;
        h[i].lchild = lchild;
        h[i].rchild = rchild;
    }
}

int getWPL(Huff* h, int len) {
    int wpl = 0;
    for (int i = 0; i < len; i++) {
        int depth = 0;
        int index = i;
        while (h[index].parent != -1) {
            depth++;
            index = h[index].parent;
        }
        wpl += (h[i].weight * depth);
    }
    return wpl;
}

int main() {
    int data[] = {2, 5, 7, 9, 13};
    int len = sizeof(data) / sizeof(data[0]);
    Huff* h = (Huff*)malloc(sizeof(Huff) * (len * 2 - 1));
    InitHuff(h, data, len);
    createHuff(h, len);
    // 验证输出
    for (int i = 0; i < 2 * len - 1; i++) {
        printf("节点 %d: weight = %d, parent = %d, lchild = %d, rchild = %d\n",
               i + 1, h[i].weight, h[i].parent, h[i].lchild, h[i].rchild);
    }
    // 计算并输出WPL
    int wpl = getWPL(h, len);
    printf("哈夫曼树的WPL为: %d\n", wpl);

    return 0;
}