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
    int countL = 0, countR = 0;
    if (t == NULL)
        return 0;
    if ((t->lchild != NULL && t->rchild == NULL) ||
        (t->lchild == NULL && t->rchild != NULL)) {
        countL = count(t->lchild);
        countR = count(t->rchild);
        return countL + countR + 1;
    } else {
        countL = count(t->lchild);
        countR = count(t->rchild);
        return countL + countR;
    }
}

int main() {
    return 0;
}