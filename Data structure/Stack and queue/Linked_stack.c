#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Linked_stack
{
    int data;
    struct Linked_stack *next;
}StackNode,*LinkStack;

// 初始化栈
void InitStack(LinkStack *s) {
    *s = NULL;
}

// 入栈操作
void Push(LinkStack *s, int t) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = t;
    newNode->next = *s;
    *s = newNode;
}

// 出栈操作
void Pop(LinkStack *s, int *t) {
    if (*s == NULL) return;
    StackNode *p = *s;
    *t = p->data;
    *s = p->next;
    free(p);
}

// 判断栈是否为空
int IsStackEmpty(LinkStack s) {
    return s == NULL;
}


int main() {
    
    return 0;
}