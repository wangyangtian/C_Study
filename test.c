#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Huff {
    int parent;
    int lchild, rchild;
    int weight;
} Huff;

// 初始化哈夫曼树节点
void Init(Huff* h, int* data, int len) {
    for (int i = 0; i < len; i++) {
        h[i].weight = data[i];
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
    for (int i = len; i < 2 * len - 1; i++) {
        h[i].weight = 0;
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
}

// 查找权值最小且未被选中的节点
int flagMin(Huff* h, int len) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < len; i++) {
        if (h[i].weight < min && h[i].parent == -1) {
            min = h[i].weight;
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        h[minIndex].parent = len;  // 标记已被选择，并设置父节点
    }
    return minIndex;  // 返回最小值下标
}

// 创建哈夫曼树
void createHuff(Huff* h, int len) {
    for (int i = len; i < 2 * len - 1; i++) {
        int lchild = flagMin(h, i);  // 找到最小节点
        int rchild = flagMin(h, i);  // 找到次小节点
        h[i].lchild = lchild;
        h[i].rchild = rchild;
        h[i].weight = h[lchild].weight + h[rchild].weight;
    }
}

// 递归生成哈夫曼编码
void generateHuffmanCode(Huff* h, int index, char* code, int length) {
    if (h[index].lchild == -1 && h[index].rchild == -1) {
        // 叶节点，打印编码
        code[length] = '\0';  // 结束字符串
        printf("Character with weight %d: %s\n", h[index].weight, code);
        return;
    }

    // 左子树
    if (h[index].lchild != -1) {
        code[length] = '0';
        generateHuffmanCode(h, h[index].lchild, code, length + 1);
    }

    // 右子树
    if (h[index].rchild != -1) {
        code[length] = '1';
        generateHuffmanCode(h, h[index].rchild, code, length + 1);
    }
}

int main() {
    int data[] = {5, 9, 12, 13, 16, 45};  // 示例权重
    int len = sizeof(data) / sizeof(data[0]);
    Huff* h = (Huff*)malloc(sizeof(Huff) * (2 * len - 1));

    Init(h, data, len);
    createHuff(h, len);

    char code[100];                                // 存储编码
    generateHuffmanCode(h, 2 * len - 2, code, 0);  // 从根节点开始生成编码

    free(h);
    return 0;
}