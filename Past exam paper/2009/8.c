#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BTree;

int preFlag, postFlag;

void check(BTree p, int n1, int n2) {
    if (p != NULL) {
        if (p->data == n1)
            preFlag = 1;
        if (p->data == n2)
            preFlag = 2;

        check(p->lchild, n1, n2);
        check(p->rchild, n1, n2);
        if (p->data == n2)
            postFlag = 1;
        if (p->data == n1)
            postFlag = 2;
    }
}

int main() {
    if (preFlag == 1 && postFlag == 1) {
        printf("n1是n2的祖先\n");
    } else {
        printf("n2是n1的祖先\n");
    }

    return 0;
}