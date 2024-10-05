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

int count(BTNode* node) {
    int left, right;
    if (node == NULL)
        return 0;
    if (node->lchild)
        left = count(node->lchild) + 1;
    if (node->rchild)
        right = count(node->rchild) + 1;
    return left + right;
}

int printCount(BTree t) {
    if (t == NULL)
        return 0;
    printf("%d节点的子孙数为：%d ", t->data, count(t));
    printCount(t->lchild);
    printCount(t->rchild);
}

int main() {
    return 0;
}