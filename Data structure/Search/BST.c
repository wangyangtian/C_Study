//二叉排序树
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTNode* BST_Search(BSTree t, int target) {
    while (t != NULL) {
        if (t->data == target)
            return t;  // 找到目标节点，返回
        t=(target>t->data)?t->rchild:t->lchild;
    }
    return NULL;  // 未找到目标值，返回NULL
}

//二叉排序树递归搜索
BSTNode* BST_Search_R(BSTree t, int target){
    if(t==NULL)
        return NULL;
    if(t->data==target)
        return t;
    else if(t->data>target)
        return BST_Search_R(t->lchild,target);
    else
        return BST_Search_R(t->rchild,target);
}

//二叉树结点的创建
BSTree *CreatNode(int data){
    BSTNode *p=(BSTNode*)malloc(sizeof(BSTNode));
    p->data=data;
    p->lchild=p->rchild=NULL;
    return p;
}
//二叉排序树插入
BSTree BST_Insert_R(BSTree t,int e){
    if(t==NULL){
        t=CreatNode(e);
        return t;
    }
    if(e<t->data)
        t->lchild=BST_Insert_R(t,e);
    if(e>t->data)
        t->rchild=BST_Insert_R(t,e);
    return t;
}
//自己写的
// bool BST_Insert_R(BSTree *t,int e){
//     if((*t)==NULL){
//         (*t)=(BSTree)malloc(sizeof(BSTNode));//(*t)=CreatNode(e);
//         (*t)->data=e;
//         (*t)->lchild=(*t)->rchild=NULL;
//         return true;
//     }
//     else if((*t)->data==e)
//         return false;
//     else if((*t)->data<e)
//         return BST_Insert_R(&(*t)->rchild,e);
//     else
//         return BST_Insert_R(&(*t)->lchild,e);
// }

// 插入一个元素到二叉搜索树中，并返回树的根节点
BSTree BST_Insert(BSTree t, int e) {
    BSTNode *parent = NULL;     // 指向当前节点的父节点
    BSTNode *current = t;       // 用于遍历树的指针，初始指向根节点
    
    // 如果当前树为空（根节点为NULL），则创建一个新节点作为根节点
    if (t == NULL) { 
        t = CreatNode(e);       // 创建包含数据e的新节点
        return t;               // 返回新创建的树（根节点）
    }

    // 遍历树，找到插入的位置
    while (current != NULL) {
        parent = current;       // 保存当前节点为父节点
        if (e < current->data)  // 如果插入的值小于当前节点的值
            current = current->lchild;  // 移动到左子树
        else                    // 如果插入的值大于或等于当前节点的值
            current = current->rchild;  // 移动到右子树
    }

    // 创建新节点并连接到父节点的合适位置
    if (e < parent->data)       // 如果插入的值小于父节点的值
        parent->lchild = CreatNode(e);  // 插入到父节点的左子树
    else                        // 如果插入的值大于或等于父节点的值
        parent->rchild = CreatNode(e);  // 插入到父节点的右子树

    return t;  // 返回插入后的树
}

// 构造二叉排序树
BSTree ConstructBST(int arr[], int size) {
    BSTree tree = NULL;         // 初始化空树
    for (int i = 0; i < size; i++) {
        tree = BST_Insert(tree, arr[i]);  // 依次插入数组中的元素
    }
    return tree;                // 返回构造好的树
}


int main() {
    
    return 0;
}