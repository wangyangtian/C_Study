#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;                      // 节点数据
    struct TreeNode* firstChild;   // 指向第一个孩子节点
    struct TreeNode* nextSibling;  // 指向下一个兄弟节点
} TreeNode, *Tree;

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

BTree treeToBinary(Tree t) {
    if(t==NULL)
        return NULL;
        
    BTree bt = (BTNode*)malloc(sizeof(BTNode));
    bt->data = t->data;
    bt->lchild = treeToBinary(t->firstChild);
    bt->rchild = treeToBinary(t->nextSibling);
    return bt;
}

int main() {
    
    return 0;
}