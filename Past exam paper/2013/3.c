#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree {
    int data;
    struct _Tree *lchild, *rchild;
} TNode, *Tree;

void PreOrder(Tree t) {
    if (t != NULL) {
        printf("%d ", t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

void InOrder(Tree t) {
    if (t != NULL) {
        PreOrder(t->lchild);
        printf("%d ", t->data);
        PreOrder(t->rchild);
    }
}

int main() {
    return 0;
}