#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree *lchild, *rchild;
} TNode, *Tree;

int CountNodes(Tree t) {
    if (t == NULL) {
        return 0;
    }
    int n = CountNodes(t->lchild) + CountNodes(t->rchild);
    printf("%d的子节点个数为%d\n", t->data, n);
    return n + 1;
}

// 辅助函数：创建新节点
Tree createNode(int data) {
    Tree newNode = (Tree)malloc(sizeof(TNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

int main() {
    // 构造一个简单的二叉树
    /*
          1
         / \
        2   3
       / \
      4   5
    */
    Tree root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);

    // 计算节点总数
    int nodeCount = CountNodes(root);
    printf("The total number of nodes in the tree: %d\n", nodeCount);

    return 0;
}
