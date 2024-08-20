#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的结点结构
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 定义链栈结构
typedef struct StackNode {
    BiTNode* data;
    struct StackNode *next;
} StackNode, *LinkStack;

// 定义链队列的结点结构
typedef struct Linked_queue {
    BiTNode* data;
    struct Linked_queue *next;
} LinkNode;

// 定义链队列结构
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue *q) {
    q->front = q->rear = (LinkNode*)malloc(sizeof(LinkNode));
    q->front->next = NULL;
}

// 队列判空
int IsEmptyQueue(LinkQueue q) {
    return q.front == q.rear;
}

// 入队
void EnQueue(LinkQueue *q, BiTNode* e) {
    LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

// 出队
int DeQueue(LinkQueue *q, BiTNode **e) {
    if (IsEmptyQueue(*q))
        return 0;
    LinkNode *p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;
    free(p);
    return 1;
}

// 初始化栈
void InitStack(LinkStack *s) {
    *s = NULL;
}

// 入栈
void Push(LinkStack *s, BiTNode* e) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    node->data = e;
    node->next = *s;
    *s = node;
}

// 出栈
int Pop(LinkStack *s, BiTNode **e) {
    if (*s == NULL)
        return 0;
    StackNode *p = *s;
    *e = p->data;
    *s = p->next;
    free(p);
    return 1;
}

// 二叉树的自下而上、从右到左的层次遍历
void LevelOrderTraversal(BiTree root) {
    if (!root) return;
    
    LinkQueue q;
    InitQueue(&q);
    LinkStack s;
    InitStack(&s);
    EnQueue(&q, root);

    while (!IsEmptyQueue(q)) {
        BiTNode *node;
        DeQueue(&q, &node);
        Push(&s, node);
        
        // 先将左子树入队，保证从右到左遍历
        if (node->lchild)
            EnQueue(&q, node->lchild);
        if (node->rchild)
            EnQueue(&q, node->rchild);
    }

    // 输出栈中的结点，实现自下而上、从右到左的层次遍历
    while (Pop(&s, &root)) {
        printf("%d ", root->data);
    }
}

int main() {
    // 构造一个测试用例
    BiTNode n1 = {1, NULL, NULL};
    BiTNode n2 = {2, NULL, NULL};
    BiTNode n3 = {3, NULL, NULL};
    BiTNode n4 = {4, NULL, NULL};
    BiTNode n5 = {5, NULL, NULL};
    BiTNode n6 = {6, NULL, NULL};
    BiTNode n7 = {7, NULL, NULL};

    n1.lchild = &n2;
    n1.rchild = &n3;
    n2.lchild = &n4;
    n2.rchild = &n5;
    n3.lchild = &n6;
    n3.rchild = &n7;

    LevelOrderTraversal(&n1);

    return 0;
}
