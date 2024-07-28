#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    } else {
        printf("栈满\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("栈空\n");
        return -1; // 栈空时返回 -1
    }
}

int EvaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0'); // 将字符转换为整数
        } else {
            int Rnum = pop(&s);
            int Lnum = pop(&s);
            int result;
            switch (postfix[i]) {
                case '+':
                    result = Lnum + Rnum;
                    break;
                case '-':
                    result = Lnum - Rnum;
                    break;
                case '*':
                    result = Lnum * Rnum;
                    break;
                case '/':
                    result = Lnum / Rnum;
                    break;
                default:
                    printf("无效的运算符: %c\n", postfix[i]);
                    return -1; // 遇到无效运算符时返回 -1
            }
            push(&s, result);
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char postfix[] = "21+32*1-*";
    printf("结果是 %d\n", EvaluatePostfix(postfix));
    return 0;
}
