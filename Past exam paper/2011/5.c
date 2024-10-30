#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} LNode;

typedef struct
{
    LNode* rear;
} Queue;

bool initQueue(Queue* q) {
    q->rear = (LNode*)malloc(sizeof(LNode));
    q->rear->next = q->rear;
}

bool enQueue(Queue* q, int x) {
    LNode* new = (LNode*)malloc(sizeof(LNode));
    if (new == NULL)
        return false;
    new->data = x;
    new->next = q->rear->next;
    q->rear->next = new;
    q->rear = new;
    return true;
}

int deQueue(Queue* q) {
    LNode* head = q->rear->next;

    if (head == q->rear)
        return;

    LNode* deleteNode = head->next;
    int deleteElem = deleteNode->data;
    head->next = deleteNode->next;

    if (head->next == head)
        q->rear = head;

    free(deleteNode);
    return deleteElem;
}

int main() {
    return 0;
}