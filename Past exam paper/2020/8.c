#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    char data;
    struct Tree *lchild, *rchild;
} TNode, *Tree;

int findIndex() {
}

Tree creatTree(char pre[], char in[], int n) {
    Tree t = (TNode *)malloc(sizeof(TNode));
    t->data = pre[0];
    t->lchild = t->rchild = NULL;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (in[i] == t->data) {
            index = i;
            break;
        }
    }
    t->lchild = creatTree(pre + 1, in, index);
    t->rchild = creatTree(pre + 1 + index, in + 1 + index, n - index - 1);
}

int main() {
    return 0;
}