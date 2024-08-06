#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

typedef struct tree //顺序存储
{
    int value;
    bool isEmpty;
}TreeNode;

typedef struct BiTNode  //链式存储
{
    int  data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 访问节点数据
void visit(BiTree T){
    printf("%d ", T->data);
}

// 先序遍历
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}


int main() {
    BiTree root=NULL;
    root=(BiTree)malloc(sizeof(BiTNode));
    root->data=0;
    root->lchild=NULL;
    root->rchild=NULL;
    return 0;
}