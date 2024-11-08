#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree {
    char data;
    struct _Tree *lchild, *rchild;
} TNode, *Tree;

int findIndex(char e, char *in, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == e)
            return i;
    }
    return -1;
}

Tree creatTree(char prev[], char in[], int n) {
    Tree t = (TNode *)malloc(sizeof(TNode));
    t->data = prev[0];
    t->lchild = t->rchild = NULL;

    int rootIndex = findIndex(t->data, in, 0, n - 1);
    t->lchild = creatTree(prev + 1, in, rootIndex);
    t->rchild = creatTree(prev + rootIndex + 1, in + rootIndex + 1, n - 1 - rootIndex);

    return t;
}

int main() {
    return 0;
}