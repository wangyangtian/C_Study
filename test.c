#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100 //树中最多结点数
typedef struct{     //树的结构定义
    int data;       //数据元素
    int parent;     //双亲位置域
}PTNode;

typedef struct{             //树的类型定义
    PTNode nodes[MAXSIZE];  //双亲表示
    int n;                  //结点数
}PTree;

struct CTNode
{
    int child;          //孩子结点在数组中的位置
    struct CTNode *next;//下一个孩子结点
};

typedef struct 
{
    int data;
    struct CTNode *firstchild;//第一个孩子
}CTBox;

typedef struct 
{
    CTBox nodes[MAXSIZE];
    int n,r;    //结点总数和根的位置
}CTree;


typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode, *BiTree;

typedef struct Linked_queue //队结点类型定义
{
    BiTreeNode *data;
    struct Linked_queue *next;
}LinkNode;

typedef struct              //链队类型定义  
{
    LinkNode *front ,*rear;
}LinkQueue;

void InitQueue(LinkQueue *q){
    q->front=q->rear=(LinkNode*)malloc(sizeof(LinkNode));
    q->front->next=NULL;
}

void EnQueue(LinkQueue *q,int elem){//带头结点入队
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=elem;
    s->next=NULL;
    q->rear->next=s;    //新结点插入到rear之后
    q->rear=s;          //修改表尾指针
}

bool DeQueue(LinkQueue *q,int *elem){//带头结点的出队
    if(q->front==q->rear)   return false;
    LinkNode *p=q->front->next;
    elem=p->data;
    q->front->next=p->next;
    if(q->rear==p)  q->rear=q->front;   //最后一次出队，修改rear指针
    free(p);
    return true;
}

bool ISEmpty(LinkQueue *q){
    if(q->front==q->rear)   return true;
    else                    return false;
}
// 访问节点数据
void visit(BiTree T){
    printf("%d ", T->data);
}

// 先序遍历
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 创建一个新节点
BiTreeNode* createNode(int data) {
    BiTreeNode* newNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

void LevelOrder(BiTree T){
    LinkQueue q;
    InitQueue(&q);
    BiTree p;
    EnQueue(&q,T);
    while (!ISEmpty(T))
    {
        DeQueue(&q,p);
        visit(p);
        if(p->lchild!=NULL) 
            EnQueue(&q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(&q,p->rchild);
    }   
}

int main() {
    return 0;
}
