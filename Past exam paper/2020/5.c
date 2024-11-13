#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node, *Tree;

Node* postfirst(Tree t) {
    if (t == NULL)
        return NULL;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = t;

    while (top1 >= 0) {
        Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->lchild)
            stack1[++top1] = node->lchild;
        if (node->rchild)
            stack1[++top1] = node->rchild;
    }

    return stack2[top2];
}

// 创建一个新节点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

int main() {
    // 创建一个简单的二叉树
    Node* root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);

    printf("%d", postfirst(root)->data);
    return 0;
}
