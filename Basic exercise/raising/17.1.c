#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

int count(BTree t){
    if(t==NULL)
        return 0;
    int countL = count(t->lchild);
    int countR = count(t->rchild);
    return countL + countR + 1;
}

int main() {

    return 0;
}