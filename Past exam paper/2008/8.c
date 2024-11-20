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

typedef struct Forest {
    int data;
    struct Forest *firstChild;
    struct Forest *nextsibling;
} FNode, *Forest;

Tree *transform(Forest f) {
    TNode *t = NULL;
    if (f != NULL) {
        t = (TNode *)malloc(sizeof(TNode));
        t->data = f->data;
        t->lchild = transform(f->firstChild);
        t->rchild = transform(f->nextsibling);
    }
    return t;
}

int inorder(Tree t) {
    if (t == NULL)
        return 0;
    int ld = inorder(t->lchild);
    printf("%d ", t->data);
    int rd = inorder(t->rchild);
    return (ld > rd ? ld : rd) + 1;
}

int main() {
        return 0;
}