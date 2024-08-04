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


int main() {
    BiTree root=NULL;
    root=(BiTree)malloc(sizeof(BiTNode));
    root->data=0;
    root->lchild=NULL;
    root->rchild=NULL;
    return 0;
}