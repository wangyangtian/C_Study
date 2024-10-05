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

BTree insertNode(BTree t, int data) {
    if (t == NULL)
        return createNode(data);
    if (data == t->data)
        return t;
    else if (data < t->data)
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
    BTree t = NULL;
    int a[] = {1, 4, 6, 3, 6, 2};
    int i = 0;
    for (i = 0; i < 6; i++) {
        t = insertNode(t, a[i]);
    }

    // 输出排序二叉树的中序遍历结果
    printf("二叉树的中序遍历: ");
    inOrder(t);
    printf("\n");
    return 0;
}