#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10
typedef struct SqStack {
    int data[MAXSIZE];
    int top;
} SqStack;

typedef struct Queue {
    SqStack s1;
    SqStack s2;
} Queue;

// 压栈操作
bool Push(SqStack* S, int elem) {
    if (S->top == MAXSIZE - 1) {  // 判断栈是否已满
        return false;             // 栈满，无法压栈
    }
    S->data[++(S->top)] = elem;  // 栈顶指针先加1，然后将元素压入栈顶
    return true;                 // 压栈成功
}

// 出栈操作
bool Pop(SqStack* S, int* elem) {
    if (S->top == -1) {  // 判断栈是否为空
        return false;    // 栈空，无法出栈
    }
    *elem = S->data[(S->top)--];  // 将栈顶元素赋值给elem，栈顶指针减1
    return true;                  // 出栈成功
}

bool IsEmpty(SqStack S) {
    return S.top == -1;
}

bool IsFull(SqStack S) {
    return S.top == MAXSIZE - 1;
}

// 入队操作函数
int EnQueue(int x, Queue* q) {
    int temp;
    // 检查 s1 是否满
    if (IsFull(q->s1)) {
        // s1 满了，检查 s2 是否为空
        if (IsEmpty(q->s2)) {
            // 将 s1 中的所有元素转移到 s2
            while (!IsEmpty(q->s1)) {
                Pop(&q->s1, &temp);
                Push(&q->s2, temp);
            }
            // 将新元素压入 s1
            Push(&q->s1, x);
            return 1; // 入队成功
        } else {
            return -1; // s1 满且 s2 不为空，无法入队
        }
    } else {
        // 如果 s1 还未满，直接入队
        Push(&q->s1, x);
        return 1; // 入队成功
    }
}

// 出队操作函数
int DeQueue(Queue* q, int* x) {
    int temp;
    
    // 检查 s2 是否为空
    if (!IsEmpty(q->s2)) {
        // s2 不为空，直接从 s2 出栈（即出队）
        Pop(&q->s2, x);
        return 1; // 出队成功
    } else {
        // 如果 s2 为空，检查 s1 是否有元素
        if (!IsEmpty(q->s1)) {
            // 将 s1 中的所有元素转移到 s2
            while (!IsEmpty(q->s1)) {
                Pop(&q->s1, &temp);
                Push(&q->s2, temp);
            }
            // 从 s2 中出栈
            Pop(&q->s2, x);
            return 1; // 出队成功
        } else {
            return -1; // s1 和 s2 都为空，队列为空，无法出队
        }
    }
}

int main() {
    return 0;
}