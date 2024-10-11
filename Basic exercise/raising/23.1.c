#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct BTNode
{
    int data;
    struct BTNode *lchild, *rchild;
}BTNode,*Btree;

void preOrder(Btree t){
    if(t!=NULL){
        printf("%d ", t->data);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

int main() {
    
    return 0;
}