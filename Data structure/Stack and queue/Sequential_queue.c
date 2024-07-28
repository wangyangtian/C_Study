#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct Sequential_queue
{
    int data[MAXSIZE]; // 用静态数组存放队列元素
    int front, rear;   // 定义队头队尾指针
} SqQueue;

void InitQueue(SqQueue *q)
{
    q->front = q->rear = 0;
}

bool QueueEmoty(SqQueue q)
{
    if (q.front == q.rear)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue *q, int elem)
{
    if ((q->rear + 1) % MAXSIZE == q->front) // 判断队列是否已满
        return false;
    q->data[q->rear] = elem;
    q->rear = (q->rear + 1) % MAXSIZE;
    // 循环队列

    return true;
}

bool DeQueue(SqQueue *q, int *elem)
{
    if (q->rear == q->front)
        return false; // 判断队列是否为空
    (*elem)=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return true;
}

bool GetElem(SqQueue q,int *elem){
    if (q.rear == q.front)
        return false; // 判断队列是否为空    
    (*elem)=q.data[q.front];
    return true;
}
int main()
{
    SqQueue Q;

    return 0;
}