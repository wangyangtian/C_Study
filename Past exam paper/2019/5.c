#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int data;
    struct Tree *lchild, *rchild;
} TNode, *Tree;

void TraverseLeaf(Tree t, int *count) {
    if (t->lchild == NULL && t->rchild == NULL) {
        (*count)++;
    }
    if (t->lchild)
        TraverseLeaf(t->lchild, count);
    if (t->rchild)
        TraverseLeaf(t->rchild, count);
}

int TraverseLeaf2(Tree t) {
    // 如果树为空，返回 0（没有叶节点）
    if (t == NULL) {
        return 0;
    }
    // 如果节点是叶节点，返回 1
    if (t->lchild == NULL && t->rchild == NULL) {
        return 1;
    }
    // 递归计算左子树和右子树的叶节点数量
    return TraverseLeaf2(t->lchild) + TraverseLeaf2(t->rchild);
}

int main() {
    return 0;
}