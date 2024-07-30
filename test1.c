#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024  // 定义栈中元素的最大个数

typedef struct Sequential_stack {
    char data[MAXSIZE];  // 静态数组存放栈中元素
    int top;             // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack* s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(SqStack* s) {
    return s->top == -1;
}

// 判断栈是否满
int IsFull(SqStack* s) {
    return s->top == MAXSIZE - 1;
}

// 压入元素到栈
int Push(SqStack* s, char elem) {
    if (IsFull(s)) {
        printf("Stack is full.\n");
        return 0;
    }
    s->data[++s->top] = elem;
    return 1;
}

// 弹出栈顶元素
int Pop(SqStack* s, char* elem) {
    if (IsEmpty(s)) {
        printf("Stack is empty.\n");
        return 0;
    }
    *elem = s->data[s->top--];
    return 1;
}

// 清空栈
void ClearStack(SqStack* s) {
    s->top = -1;
}

// 打印栈元素
void PrintStack(SqStack* s) {
    if (IsEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%c", s->data[i]);
        }
        printf("\n");
    }
}

// 处理输入行
void process_input(char* input) {
    SqStack stack;
    InitStack(&stack);
    char elem;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == '#') {
            Pop(&stack, &elem);
        } else if (input[i] == '@') {
            ClearStack(&stack);
        } else {
            Push(&stack, input[i]);
        }
    }
    PrintStack(&stack);
}

int main() {
    char buffer[MAXSIZE];

    printf("请输入文本（按 Ctrl+Z 结束）：\n");

    while (fgets(buffer, MAXSIZE, stdin) != NULL) {
        process_input(buffer);
    }

    return 0;
}
