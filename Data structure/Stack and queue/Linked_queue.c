#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Linked_queue //队结点类型定义
{
    int data;
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

//不带头结点初始化
// void InitQueue(LinkQueue *q){
//     q->front=NULL;
//     q->rear=NULL;
// }

bool ISEmpty(LinkQueue *q){
    if(q->front==q->rear)   return true;
    else                    return false;
}

// bool IsEmpty(LinkQueue *q){
//     if(q->front==NULL)  return true;
//     else                return false;
// }

void EnQueue(LinkQueue *q,int elem){//带头结点入队
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=elem;
    s->next=NULL;
    q->rear->next=s;    //新结点插入到rear之后
    q->rear=s;          //修改表尾指针
}

void EnQueue(LinkQueue *q,int elem){//不带头结点入队
    LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=elem;
    s->next=NULL;
    if(q->front=NULL)
    {
        q->front=s;
        q->rear=s;
    }
    else{
        q->rear->next=s;
    q->rear=s;
    } 
}

bool DeQueue(LinkQueue *q,int *elem){//带头结点的出队
    if(q->front==q->rear)   return false;
    LinkNode *p=q->front->next;
    *elem=p->data;
    q->front->next=p->next;
    if(q->rear==p)  q->rear=q->front;   //最后一次出队，修改rear指针
    free(p);
    return true;
}

bool DeQueue(LinkQueue *q,int *elem){//不带头结点的出队
    if(q->front==q->rear)   return false;
    LinkNode *p=q->front;
    elem=p->data;
    q->front=p->next;
    if(q->rear==p)  q->rear=q->front;
    free(p);
    return true;
}

int main() {
    
    return 0;
}