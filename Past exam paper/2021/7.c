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

Tree createTree() {
    int a;
    scanf("%d", &a);
    Tree t = NULL;
    if (a != 0) {
        t = (TNode *)malloc(sizeof(TNode));
        t->data = a;
        t->lchild = createTree();
        t->rchild = createTree();
    }
    return t;
}

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