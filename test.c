#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义二叉搜索树的节点结构
typedef struct BSTNode {
    int data;
    struct BSTNode* lchild;
    struct BSTNode* rchild;
} BSTNode, *BSTree;

// 插入新节点的函数，返回插入后的树
BSTree BST_Insert(BSTree t, int e) {
    // 如果当前树为空，则创建一个新节点并插入
    if (t == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        if (!newNode) { // 检查内存分配是否成功
            printf("内存分配失败！\n");
            return NULL;
        }
        newNode->data = e;
        newNode->lchild = newNode->rchild = NULL;
        return newNode; // 返回新创建的节点
    }
    // 如果找到相同的值，不插入，返回原树
    else if (t->data == e) {
        return t;
    }
    // 如果插入值大于当前节点，递归插入右子树
    else if (t->data < e) {
        t->rchild = BST_Insert(t->rchild, e);
    }
    // 如果插入值小于当前节点，递归插入左子树
    else {
        t->lchild = BST_Insert(t->lchild, e);
    }
    return t; // 返回更新后的树
}

// 中序遍历打印树（测试用）
void InOrder(BSTree t) {
    if (t != NULL) {
        InOrder(t->lchild);
        printf("%d ", t->data);
        InOrder(t->rchild);
    }
}

int main() {
    BSTree tree = NULL;
    tree = BST_Insert(tree, 50);
    tree = BST_Insert(tree, 30);
    tree = BST_Insert(tree, 70);
    tree = BST_Insert(tree, 20);
    tree = BST_Insert(tree, 40);
    tree = BST_Insert(tree, 60);
    tree = BST_Insert(tree, 80);

    printf("中序遍历结果: ");
    InOrder(tree); // 打印排序后的结果
    printf("\n");

    return 0;
}
