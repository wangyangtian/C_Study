#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree {
    int data;
    struct _Tree *lchild, *rchild;
} Node, *Tree;

int FindIndex(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

Tree createTree(int pre[], int pin[], int n) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->data = pre[0];
    root->lchild = root->rchild = NULL;

    int rootIndex = FindIndex(pin, 0, n - 1, pre[0]);

    root->lchild = createTree(pre + 1, pin, rootIndex);
    root->rchild = createTree(pre + rootIndex + 1, pin + rootIndex + 1, n - rootIndex - 1);
}

int main() {
    return 0;
}