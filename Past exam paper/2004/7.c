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

void inorder(Tree t) {
    if (t) {
        inorder(t->lchild);
        printf("%d", t->data);
        inorder(t->rchild);
    }
}

int main() {
    return 0;
}