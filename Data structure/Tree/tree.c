#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct tree  // 顺序存储
{
    int value;
    bool isEmpty;
} TreeNode;

typedef struct BiTNode  // 链式存储
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 访问节点数据
void visit(BiTree T) {
    printf("%d ", T->data);
}

// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 求二叉树深度
int GetDepth(BiTree t) {
    int Ld, Rd;
    if (t == NULL)
        return 0;
    else {
        Ld = GetDepth(t->lchild);
        Rd = GetDepth(t->rchild);
        return (Ld > Rd ? Ld : Rd) + 1;
    }
}

// 在二叉树中查找指定值的节点
void search(BiTree t, BiTNode** q, int key) {  // 因为指针q要修改，所以用**q
    if (t != NULL) {                           // 当前节点不为空
        if (t->data == key) {  // 如果当前节点的数据等于要查找的值
            *q = t;            // 将当前节点的地址存储在*q中
        } else {
            search(t->lchild, q, key);  // 递归查找左子树
            search(t->rchild, q, key);  // 递归查找右子树
        }
    }
}

// 在二叉树中查找指定值的节点,剪枝
void search2(BiTree t, BiTNode** q, int key) {
    if (t != NULL) {
        if (t->data == key)
            *q = t;
        else {
            search2(t->lchild, q, key);
            if (q == NULL)
                search2(t->rchild, q, key);
        }
    }
}

int n = 0;  // 全局变量，用于记录当前访问的节点序号

// 二叉树的前序遍历，并在遍历到第k个节点时输出该节点的值
void trave(BiTree t, int k) {
    if (t != NULL) {                // 如果当前节点不为空
        n++;                        // 每访问一个节点，递增n的值
        if (n == k) {               // 如果当前是第k个访问的节点
            printf("%d", t->data);  // 输出该节点的数据值
        }
        trave(t->lchild, k);  // 递归遍历左子树
        trave(t->rchild, k);  // 递归遍历右子树
    }
}
typedef struct Linked_queue  // 队结点类型定义
{
    BiTNode* data;
    struct Linked_queue* next;
} LinkNode;

typedef struct  // 链队类型定义
{
    LinkNode *front, *rear;
} LinkQueue;

// 带头结点初始化
void InitQueue(LinkQueue* q) {
    q->front = q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    q->front->next = NULL;
}

void EnQueue(LinkQueue* q, BiTree elem) {  // 带头结点入队
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = elem;
    s->next = NULL;
    q->rear->next = s;  // 新结点插入到rear之后
    q->rear = s;        // 修改表尾指针
}

bool DeQueue(LinkQueue* q, BiTree* elem) {  // 带头结点的出队
    if (q->front == q->rear)
        return false;
    LinkNode* p = q->front->next;
    *elem = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;  // 最后一次出队，修改rear指针
    free(p);
    return true;
}

// 判断队列是否为空
bool IsQueueEmpty(LinkQueue q) {
    return q.front == q.rear;
}

void LevelOrder(BiTree t) {  // 二叉树的层序遍历
    LinkQueue q;
    InitQueue(&q);
    BiTree p;
    EnQueue(&q, t);
    while (!IsQueueEmpty(q)) {
        DeQueue(&q, &p);
        visit(p);
        if (p->lchild != NULL)
            EnQueue(&q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(&q, p->rchild);
    }
}

int GetTreeWidth(BiTree t) {
    // 如果树为空，则宽度为0
    if (t == NULL)
        return 0;

    // 初始化一个队列，用于层次遍历树节点
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q, t);  // 将根节点入队

    LinkNode* current;  // 用于遍历当前层的队列节点
    int maxWidth = 0;   // 用于记录树的最大宽度

    // 当队列不为空时，进行循环
    while (!IsQueueEmpty(q)) {
        int nodeCount = 0;  // 用于记录当前层的节点数量
        current = q.front;  // 从队列的头部开始遍历

        // 遍历当前层的所有节点，计算节点数量
        while (current != NULL) {
            nodeCount++;
            current = current->next;
        }

        // 如果当前层的节点数量大于之前记录的最大宽度，则更新最大宽度
        if (nodeCount > maxWidth)
            maxWidth = nodeCount;

        // 将当前层的所有节点出队，并将它们的子节点（即下一层节点）入队
        for (int i = 0; i < nodeCount; i++) {
            BiTNode* currentnode;
            DeQueue(&q, &currentnode);  // 当前节点出队
            if (currentnode->lchild != NULL)
                EnQueue(&q, currentnode->lchild);  // 左孩子入队
            if (currentnode->rchild != NULL)
                EnQueue(&q, currentnode->rchild);  // 右孩子入队
        }
    }

    // 返回最大宽度
    return maxWidth;
}

typedef struct StackNode {
    BiTNode* data;
    struct StackNode* next;
} StackNode, *LinkStack;

void InitStack(LinkStack* s) {
    *s = NULL;
}

void Push(LinkStack* s, BiTNode* t) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = t;
    newNode->next = *s;
    *s = newNode;
}

void Pop(LinkStack* s, BiTNode** t) {
    if (*s == NULL)
        return;
    StackNode* p = *s;
    *t = p->data;
    *s = p->next;
    free(p);
}

bool IsStackEmpty(LinkStack s) {
    return s == NULL;
}

void LevelOrderRtoL(BiTree t) {  // 二叉树的自下而上、从右到左的层次遍历
    // 初始化一个队列，用于层次遍历树节点
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q, t);  // 将根节点入队

    LinkStack s;
    InitStack(&s);

    LinkNode* current;  // 用于遍历当前层的队列节点
    // 当队列不为空时，进行循环
    while (!IsQueueEmpty(q)) {
        int nodeCount = 0;  // 用于记录当前层的节点数量
        current = q.front;  // 从队列的头部开始遍历

        // 遍历当前层的所有节点，计算节点数量
        while (current != NULL) {
            nodeCount++;
            current = current->next;
        }

        // 将当前层的所有节点出队，并将它们的子节点（即下一层节点）入队
        for (int i = 0; i < nodeCount; i++) {
            BiTNode* currentnode;
            DeQueue(&q, &currentnode);  // 当前节点出队
            Push(&s, currentnode);
            if (currentnode->lchild != NULL)
                EnQueue(&q, currentnode->lchild);  // 左孩子入队
            if (currentnode->rchild != NULL)
                EnQueue(&q, currentnode->rchild);  // 右孩子入队
        }
    }
}

int BtDepth(BiTree t) {  // 非递归求二叉树深度
    if (t == NULL)
        return 0;
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q, t);
    LinkNode* current;
    int levelCnt = 0;

    while (!IsQueueEmpty(q)) {
        int levelNodeCnt = 0;
        current = q.front;
        while (current != NULL) {
            levelNodeCnt++;
            current = current->next;
        }
        for (int i = 0; i < levelNodeCnt; i++) {
            BiTNode* p;
            DeQueue(&q, &p);
            if (p->lchild != NULL)
                EnQueue(&q, p->lchild);
            if (p->rchild != NULL)
                EnQueue(&q, p->rchild);
        }
        levelCnt++;
    }
    return levelCnt;
}

int BtDepth2(BiTree T) {
    if (T = NULL)
        return 0;
    int ld = BtDepth2(T->lchild);
    int rd = BtDepth2(T->rchild);
    return (ld > rd ? ld : rd) + 1;
}
void PreOrderNonRecursion(BiTree T) {
    LinkStack S;
    InitStack(&S);  // 初始化栈

    BiTNode* p = T;  // 初始化指针 p 为树的根节点

    while (p || !IsStackEmpty(S))  // 当 p 不为空或栈不为空时循环
    {
        if (p) {
            printf("%d ", p->data);  // 访问当前节点，假设 data 为 int
            Push(&S, p);             // 将当前节点压入栈中
            p = p->lchild;           // 遍历左子树
        } else {
            Pop(&S, &p);    // 栈顶节点出栈
            p = p->rchild;  // 遍历右子树
        }
    }
}

void PreOrderNonRecursion2(BiTree t) {
    LinkStack s;
    InitStack(&s);
    BiTNode* node;
    Push(&s, t);
    while (node || !IsStackEmpty(s)) {
        Pop(&s, &node);
        visit(node);
        if (node->rchild != NULL)
            Push(&s, node->rchild);
        if (node->lchild != NULL)
            Push(&s, node->lchild);
    }
}

// 中序遍历二叉树
void InOrderNonRecursion(BiTree T) {
    LinkStack s;
    InitStack(&s);
    BiTNode* p;
    p = T;
    while (p || IsStackEmpty(s)) {
        while (p != NULL) {
            Push(&s, p);
            p = p->lchild;
        }
        if (!IsStackEmpty(s)) {
            Pop(&s, &p);
            visit(p);
            p = p->rchild;
        }
    }
}

void PostOrderRecursion(BiTree T) {
    if (T = NULL)
        return;
    LinkStack s1, s2;
    InitStack(&s1);
    InitStack(&s2);
    BiTNode* p;
    Push(&s1, T);
    while (!IsStackEmpty(s1)) {
        Pop(&s1, p);
        Push(&s2, p);
        if (p->rchild != NULL)
            Push(&s1, p->rchild);
        if (p->lchild != NULL)
            Push(&s1, p->lchild);
    }
    while (!IsStackEmpty(s2)) {
        Pop(&s2, p);
        visit(p);
    }
}

// 判断二叉树是否是完全二叉树
bool IsCompleteBiTree(BiTree t) {
    // 如果树为空，则是完全二叉树
    if (!t)
        return true;

    LinkQueue q;
    InitQueue(&q);   // 初始化队列
    EnQueue(&q, t);  // 将根节点入队

    bool HaveNull = false;  // 标记是否遇到空子节点

    while (!IsQueueEmpty(q)) {
        BiTNode* node;
        DeQueue(&q, &node);  // 取出当前节点

        // 检查左子节点
        if (node->lchild) {
            // 如果之前遇到过空子节点，且现在又有非空左子节点，则树不是完全二叉树
            if (HaveNull == true)
                return false;
            else
                EnQueue(&q, node->lchild);  // 左子节点入队
        } else {
            HaveNull = true;  // 遇到空子节点，标记为true
        }

        // 检查右子节点
        if (node->rchild) {
            // 如果之前遇到过空子节点，且现在又有非空右子节点，则树不是完全二叉树
            if (HaveNull == true)
                return false;
            else
                EnQueue(&q, node->rchild);  // 右子节点入队
        } else {
            HaveNull = true;  // 遇到空子节点，标记为true
        }
    }

    // 如果遍历完整个树后没有违反完全二叉树的条件，返回true
    return true;
}

// 根据先序遍历数组A和中序遍历数组B，构建二叉树
BiTree PreInCreate(int* A, int* B, int Al, int Ar, int Bl, int Br) {
    // A 为先序遍历数组，B 为中序遍历数组
    // Al 和 Ar 为先序遍历数组中当前子树的起始和结束索引
    // Bl 和 Br 为中序遍历数组中当前子树的起始和结束索引

    BiTree root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = A[Al];  // 先序遍历的第一个元素即为根节点

    // 在中序遍历中找到根节点的位置
    int i;
    for (i = Bl; i <= Br; i++) {
        if (B[i] == root->data) {
            break;
        }
    }

    // 计算左右子树的长度
    int Llen = i - Bl;
    int Rlen = Br - i;

    // 递归构建左右子树
    if (Llen > 0) {
        root->lchild = PreInCreate(A, B, Al + 1, Al + Llen, Bl, Bl + Llen - 1);
    } else {
        root->lchild = NULL;  // 如果左子树长度为0，则该节点没有左孩子
    }
    if (Rlen > 0) {
        root->rchild = PreInCreate(A, B, Ar - Rlen + 1, Ar, Br - Rlen + 1, Br);
    } else {
        root->rchild = NULL;  // 如果右子树长度为0，则该节点没有右孩子
    }

    // 返回构建好的根节点
    return root;
}

// 根据后序遍历数组A和中序遍历数组B，构建二叉树
BiTree PostInCreate(int* A, int* B, int Al, int Ar, int Bl, int Br) {
    // A 为后序遍历数组，B 为中序遍历数组
    // Al 和 Ar 为后序遍历数组中当前子树的起始和结束索引
    // Bl 和 Br 为中序遍历数组中当前子树的起始和结束索引
    BiTree root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = A[Ar];
    int i;
    for (i = Bl; i <= Br; i++) {
        if (B[i] == root->data)
            break;
    }
    int Llen = i - Bl;
    int Rlen = Br - i;
    if (Llen)
        root->lchild = PostInCreate(A, B, Al, Al + Llen - 1, Bl, Bl + Llen - 1);
    else
        root->lchild = NULL;
    if (Rlen)
        root->rchild = PostInCreate(A, B, Ar - Rlen, Ar - 1, Br - Rlen + 1, Br);
    else
        root->rchild = NULL;
    return root;
}



int main() {
    // 创建一个简单的二叉树进行测试
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchild = (BiTree)malloc(sizeof(BiTNode));
    root->rchild = (BiTree)malloc(sizeof(BiTNode));
    root->lchild->data = 2;
    root->rchild->data = 3;
    root->lchild->lchild = root->lchild->rchild = NULL;
    root->rchild->lchild = root->rchild->rchild = NULL;

    LevelOrder(root);  // 输出：1 2 3

    return 0;
}