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

int hight(BTree t){
    if(t==NULL)
        return 0;
    int hl = hight(t->lchild);
    int hr = hight(t->rchild);
    return hl > hr ? hl + 1 : hr + 1;
}

int isBalance(BTree t){
    if(t==NULL)
        return true;
    int hl = hight(t->lchild);
    int hr = hight(t->rchild);
    if(abs(hl-hr)>1)
        return false;
    return isBalance(t->lchild) && isBalance(t->rchild);
}

int main() {
    
    return 0;
}