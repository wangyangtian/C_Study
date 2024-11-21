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

Tree creatTree(char pre[], char in[], int n) {
    TNode *root = (TNode *)malloc(sizeof(TNode));
    root->data = pre[0];
    root->lchild = root->rchild = NULL;

    int rootIndex = -1;
    for (int i = 0; i < n; i++) {
        if (in[i] == root->data) {
            rootIndex = i;
            break;
        }
    }

    root->lchild = creatTree(pre + 1, in, rootIndex);
    root->rchild = creatTree(pre + rootIndex + 1, in + rootIndex + 1, n - rootIndex - 1);
}

int main() {
    return 0;
}