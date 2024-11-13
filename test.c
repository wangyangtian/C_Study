#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建一个新节点
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 非递归后序遍历
void postOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    TreeNode* stack1[100];  // 第一个栈
    TreeNode* stack2[100];  // 第二个栈
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;  // 将根节点压入第一个栈

    while (top1 >= 0) {
        TreeNode* node = stack1[top1--];  // 弹出节点
        stack2[++top2] = node;            // 将弹出的节点压入第二个栈

        // 将左子节点压入第一个栈
        if (node->left)
            stack1[++top1] = node->left;
        // 将右子节点压入第一个栈
        if (node->right)
            stack1[++top1] = node->right;
    }
    int temp = top2;
    // 从第二个栈中弹出节点，打印值
    while (top2 >= 0) {
        TreeNode* node = stack2[top2--];
        printf("%d ", node->val);  // 后序遍历顺序
    }
    printf("\n%d", stack2[temp]->val);
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("后序遍历结果: ");
    postOrderTraversal(root);
    printf("\n");

    // 释放内存（这里省略了内存释放的代码）
    return 0;
}
