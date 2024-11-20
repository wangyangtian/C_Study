#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int data;
    int top;
} Stack;

typedef struct Queue {
    Stack s1;
    Stack s2;
} Queue;

void push(Stack *s, int x) {
}

void pop(Stack *s, int *x) {
}

bool isEmpty(Stack s) {
}

void enQueue(Queue *q, int x) {
    push(&(q->s1), x);
}

void deQueue(Queue *q, int *x) {
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            int temp;
            pop(&(q->s1), &temp);
            push(&(q->s2), temp);
        }
    }
    if (!isEmpty(q->s2)) {
        pop(&(q->s2), x);
    } else {
        printf("queue is empty");
    }
}

int main() {
    return 0;
}