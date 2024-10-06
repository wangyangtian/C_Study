#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

int prev = INT_MIN;  // 初始化为最小整数值

bool isBST(BTree t) {
    if (t == NULL)
        return true;  // 空树是BST

    // 检查左子树，检查当前节点
    if (!isBST(t->lchild)||t->data <= prev)
        return false;
    prev = t->data;  // 更新prev

    // 检查右子树
    return isBST(t->rchild);
}

int main() {
    return 0;
}