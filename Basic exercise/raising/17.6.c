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

int hight(BTree t) {
    if (t == NULL)
        return 0;
    int left = hight(t->lchild);
    int right = hight(t->rchild);
    return left > right ? left + 1 : right + 1;
}

int main() {
    return 0;
}