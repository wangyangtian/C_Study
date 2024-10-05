#include <stdio.h>
#include <stdlib.h>

// 树节点结构定义
typedef struct CSNode {
    int data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;

// 求树高函数
int Hight(CSTree t) {
    if (t == NULL)
        return 0;

    int CHight = Hight(t->firstChild) + 1;  // 计算孩子节点的高度
    int SHight = Hight(t->nextSibling);   // 计算兄弟节点的高度

    return CHight > SHight ? CHight : SHight;
}

// 创建一个新节点
CSTree createNode(int data) {
    CSTree newNode = (CSTree)malloc(sizeof(CSNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// 测试函数
void testTreeHeight() {
    // 构建测试树
    CSTree root = createNode(1);
    root->firstChild = createNode(2);
    root->firstChild->nextSibling = createNode(3);

    root->firstChild->firstChild = createNode(4);
    root->firstChild->firstChild->nextSibling = createNode(5);

    root->firstChild->nextSibling->firstChild = createNode(6);
    root->firstChild->nextSibling->firstChild->nextSibling = createNode(7);

    // 测试高度
    printf("树的高度是: %d\n", Hight(root));  // 应该输出 3
}

int main() {
    testTreeHeight();
    return 0;
}
