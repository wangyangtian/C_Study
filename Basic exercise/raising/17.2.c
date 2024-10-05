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

int count(BTree t) {
    if (t == NULL)
        return 0;
    if (t->lchild == NULL && t->rchild == NULL)
        return 1;
    int countL = count(t->lchild);
    int countR = count(t->rchild);
    return countL + countR;
}

int main() {
    return 0;
}