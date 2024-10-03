#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

BTree PreInCreate(int* A, int* B, int Al, int Ar, int Bl, int Br) {
    // 如果子树为空（索引无效），返回NULL
    if (Al > Ar)
        return NULL;

    // 创建当前子树的根节点
    BTree root = (BTNode*)malloc(sizeof(BTNode));
    root->data = A[Al];  // 根节点数据为先序遍历数组的第一个元素

    // 在中序遍历中找到根节点的位置
    int i = Bl;
    while (B[i] != A[Al])
        i++;

    // 递归构建左右子树
    root->lchild = PreInCreate(A, B, Al + 1, Al + (i - Bl), Bl, i - 1);
    root->rchild = PreInCreate(A, B, Al + (i - Bl) + 1, Ar, i + 1, Br);

    return root;
}

int main() {
    return 0;
}