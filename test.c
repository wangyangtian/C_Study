#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int data;
    struct CircularQueue *next;
    struct CircularQueue *prior;
}CQNode;

typedef struct 
{
    CQNode *front;
    CQNode *rear;
}CQueue;

void InitQueue(CQueue *cq){
    cq->front=cq->rear=(CQNode*)malloc(sizeof(CQNode));
    cq->front->next=cq->front;
    cq->front->prior=cq->rear;
}

void TailDelete(CQueue *cq,int *x){
    if (cq->rear == cq->front) return;  // 队列为空
    CQNode *p=cq->rear;
    *x = p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    cq->rear=p->prior;
    free(p);
}

void HeadInsert(CQueue *cq,int x){
    CQNode * q=(CQNode*)malloc(sizeof(CQNode));
    q->data=x;
    q->next = cq->front->next;
    cq->front->next->prior = q;
    cq->front->next = q;
    q->prior = cq->front;
    if (cq->front == cq->rear) {
        cq->rear = q;  // 插入第一个元素时需要更新rear
    }    
}

int main() {
    CQueue cq;
    InitQueue(&cq);

    // 测试从队头插入操作
    printf("HeadInsert 1\n");
    HeadInsert(&cq, 1);
    printf("HeadInsert 2\n");
    HeadInsert(&cq, 2);
    printf("HeadInsert 3\n");
    HeadInsert(&cq, 3);

    // 打印队列状态
    CQNode *p = cq.front->next;
    printf("Queue elements after HeadInsert: ");
    while (p != cq.front) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // 测试从队尾删除操作
    int x;
    printf("TailDelete\n");
    TailDelete(&cq, &x);
    printf("Deleted: %d\n", x);
    printf("TailDelete\n");
    TailDelete(&cq, &x);
    printf("Deleted: %d\n", x);
    printf("TailDelete\n");
    TailDelete(&cq, &x);
    printf("Deleted: %d\n", x);

    // 检查队列是否为空
    if (cq.front == cq.rear && cq.front->next == cq.front) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    return 0;
}

