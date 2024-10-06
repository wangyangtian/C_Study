#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 30

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
    for (int i = 0; i < len; i++) {                    // 遍历所有节点
        if (h[i].weight < min && h[i].parent == -1) {  // 未被选中
            min = h[i].weight;
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        h[minIndex].parent = len;  // 标记已被选择，并设置父节点
    }
    return minIndex;  // 返回最小值下标
}

void createHuff(Huff* h, int len) {
    for (int i = len; i < 2 * len - 1; i++) {
        int lchild = flagMin(h, i);  // 找到最小节点
        int rchild = flagMin(h, i);  // 找到次小节点
        h[i].lchild = lchild;
        h[i].rchild = rchild;
        h[i].weight = h[lchild].weight + h[rchild].weight;
    }
}

// 计算哈夫曼树的WPL
int getWPL(Huff* h, int len) {
    int wpl = 0;
    for (int i = 0; i < len; i++) {  // 只遍历叶子节点
        int depth = 1;
        int index = i;
        // 向上找到根节点，并计算深度
        while (h[index].parent != -1) {
            index = h[index].parent;
            depth++;
        }
        // 累加每个叶子节点的 weight * depth
        wpl += (h[i].weight * depth);
    }
    return wpl;
}

void HuffmanCode(Huff* h, int len,int index, char *code) {
    if(h[index].lchild==-1&&h[index].rchild==-1){
        code[len] = '\0';
        printf("Character with weight %d: %s\n", h[index].weight, code);
        return;
    }
    //左子树
    if(h[index].lchild!=-1){
        code[len] = '0';
        HuffmanCode(h, len + 1, h[index].lchild, code);
    }
    //右子树
    if(h[index].rchild!=-1){
        code[len] = '1';
        HuffmanCode(h, len + 1, h[index].rchild, code);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int len = sizeof(data) / sizeof(data[0]);
    Huff* h = (Huff*)malloc(sizeof(Huff) * (2 * len - 1));
    Init(h, data, len);
    createHuff(h, len);
    // 验证输出
    for (int i = 0; i < 2 * len - 1; i++) {
        printf("节点 %d: weight = %d, parent = %d, lchild = %d, rchild = %d\n",
               i+1, h[i].weight, h[i].parent, h[i].lchild, h[i].rchild);
    }

    // 计算并输出WPL
    int wpl = getWPL(h, len);
    printf("哈夫曼树的WPL为: %d\n", wpl);
    free(h);
    return 0;
}