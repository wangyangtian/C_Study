#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct Sequential_stack {
    int data[MAXSIZE]; // 静态数组存放栈中元素
    int top;           // 栈顶指针
} SqStack;

void InitStack(SqStack *S) {
    S->top = -1; // 初始化栈顶指针
}

bool IsEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

void destroyStack(SqStack *S) {
    S->top = -1;
}

bool Push(SqStack *S, int elem) {
    if (S->top == MAXSIZE - 1) { // 判断栈是否已满
        return false; // 栈满，无法压栈
    }
    S->data[++(S->top)] = elem; // 栈顶指针先加1，然后将元素压入栈顶
    return true;                // 压栈成功
}

bool Pop(SqStack *S, int *elem) {
    if (S->top == -1) { // 判断栈是否为空
        return false; // 栈空，无法出栈
    }
    *elem = S->data[(S->top)--]; // 将栈顶元素赋值给elem，栈顶指针减1
    return true;                 // 出栈成功
}

// 十进制转八进制函数
void DecimalToOctal(int decimal) {
    SqStack stack;
    InitStack(&stack);
    
    while (decimal != 0) {
        int remainder = decimal % 8;
        Push(&stack, remainder);
        decimal = decimal / 8;
    }
    printf("八进制数为：");
    while (!IsEmpty(stack)) {
        int elem;
        Pop(&stack, &elem);
        printf("%d", elem);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("请输入一个十进制整数：");
    scanf("%d", &decimal);
    
    DecimalToOctal(decimal);
    
    return 0;
}
