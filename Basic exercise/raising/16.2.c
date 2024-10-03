#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
}BTNode,*BTree;

BTNode *creatNode(int data){
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
    if(!newNode){
        printf("内存分配失败！\n");
        return NULL;
    }
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

BTree bulidCompleteBTree(int a[],int n,int index){
    if(index>n){
        return NULL;
    }
    BTree root = creatNode(a[index]);
    root->lchild = bulidCompleteBTree(a, n, index * 2);
    root->rchild = bulidCompleteBTree(a, n, index * 2 + 1);
    return root;
}

// 中序遍历二叉树
void inorderTraversal(BTree root) {
    if (root != NULL) {
        inorderTraversal(root->lchild);  // 遍历左子树
        printf("%d ", root->data);       // 打印当前节点
        inorderTraversal(root->rchild);  // 遍历右子树
    }
}

int main() {
    // 假设数组以顺序存储了完全二叉树的节点数据，下标从1开始
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7};  // A[0]不使用，实际数据从A[1]开始
    int n = sizeof(A) / sizeof(A[0]) - 1;

    // 构造完全二叉树
    BTree root = bulidCompleteBTree(A, n, 1);

    // 中序遍历验证结果
    printf("二叉树的中序遍历: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}