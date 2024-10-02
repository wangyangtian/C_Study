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

BTNode* createNode(int data) {
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
    if (!newNode) {
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

BTNode* insertNode(BTree t, int data) {
    if (t == NULL) {
        return createNode(data);
    }
    if (data < t->data)
        t->lchild = insertNode(t->lchild, data);
    else
        t->rchild = insertNode(t->rchild, data);
    return t;
}

void inOrder(BTree t) {
    if (t != NULL) {
        inOrder(t->lchild);
        printf("%d ", t->data);
        inOrder(t->rchild);
    }
}

int main() {
    BTree root = NULL;

    // 插入节点，构建排序二叉树
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        root = insertNode(root, data[i]);
    }

    // 输出排序二叉树的中序遍历结果
    printf("二叉树的中序遍历: ");
    inOrder(root);
    printf("\n");

    return 0;
}