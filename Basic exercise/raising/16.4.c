#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct BTNode  // 链式存储
{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BTree;

BTree PostInCreate(int* Post, int* In, int PostL, int PostR, int InL, int InR) {
    if(PostL>PostR)
        return NULL;
    BTree root = (BTNode*)malloc(sizeof(BTNode));
    root->data = Post[PostL];

    int i = InL;
    while(Post[PostL]!=In[i])
        i++;

    root->lchild =
        PostInCreate(Post, In, PostL + 1, PostL + (i - InL), InL, i - 1);
    root->rchild =
        PostInCreate(Post, In, PostL + (i - InL) + 1, PostR, i + 1, InR);
    return root;
}

int main() {
    
    return 0;
}