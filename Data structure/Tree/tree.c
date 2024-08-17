#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

typedef struct tree //顺序存储
{
    int value;
    bool isEmpty;
}TreeNode;

typedef struct BiTNode  //链式存储
{
    int  data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

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

//求二叉树深度
int GetDepth(BiTree t){
    int Ld,Rd;
    if(t==NULL)
        return 0;
    else{
        Ld=GetDepth(t->lchild);
        Rd=GetDepth(t->rchild);
        return (Ld>Rd?Ld:Rd)+1;
    }
}

// 在二叉树中查找指定值的节点
void search(BiTree t, BiTNode **q, int key) {//因为指针q要修改，所以用**q
    if (t != NULL) {  // 当前节点不为空
        if (t->data == key) {  // 如果当前节点的数据等于要查找的值
            *q = t;  // 将当前节点的地址存储在*q中
        } else {
            search(t->lchild, q, key);  // 递归查找左子树
            search(t->rchild, q, key);  // 递归查找右子树
        }
    }
}

// 在二叉树中查找指定值的节点,剪枝
void search2(BiTree t,BiTNode **q,int key){
    if(t!=NULL){
        if(t->data==key)
            *q=t;
        else{
            search2(t->lchild,q,key);
            if(q==NULL)
                search2(t->rchild,q,key);
        }
    }
}

int n = 0;  // 全局变量，用于记录当前访问的节点序号

// 二叉树的前序遍历，并在遍历到第k个节点时输出该节点的值
void trave(BiTree t, int k) {
    if (t != NULL) {  // 如果当前节点不为空
        n++;  // 每访问一个节点，递增n的值
        if (n == k) {  // 如果当前是第k个访问的节点
            printf("%d", t->data);  // 输出该节点的数据值
        }
        trave(t->lchild, k);  // 递归遍历左子树
        trave(t->rchild, k);  // 递归遍历右子树
    }
}
typedef struct Linked_queue //队结点类型定义
{
    BiTree data;
    struct Linked_queue *next;
}LinkNode;

typedef struct              //链队类型定义  
{
    LinkNode *front ,*rear;
}LinkQueue;

//带头结点初始化
void InitQueue(LinkQueue *q){
    q->front=q->rear=(LinkNode*)malloc(sizeof(LinkNode));
    q->front->next=NULL;
}

void EnQueue(LinkQueue *q,BiTree elem){//带头结点入队
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=elem;
    s->next=NULL;
    q->rear->next=s;    //新结点插入到rear之后
    q->rear=s;          //修改表尾指针
}

bool DeQueue(LinkQueue *q,BiTree *elem){//带头结点的出队
    if(q->front==q->rear)   return false;
    LinkNode *p=q->front->next;
    *elem=p->data;
    q->front->next=p->next;
    if(q->rear==p)  q->rear=q->front;   //最后一次出队，修改rear指针
    free(p);
    return true;
}

// 判断队列是否为空
bool IsEmpty(LinkQueue q) {
    return q.front == q.rear;
}

void LevelOrder(BiTree t){  //二叉树的层序遍历
    LinkQueue q;
    InitQueue(&q);
    BiTree p;
    EnQueue(&q,t);
    while(!IsEmpty(q)){
        DeQueue(&q,&p);
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(&q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(&q,p->rchild);
    }
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