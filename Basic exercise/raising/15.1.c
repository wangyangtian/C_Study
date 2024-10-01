#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

typedef struct SqStack {
    double num[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack* s) {
    s->top = -1;
}

bool Push(SqStack* s, double n) {
    if (s->top == (MAXSIZE - 1))
        return false;
    s->num[++s->top] = n;
    return true;
}

double Pop(SqStack* s, double* n) {
    if (s->top == -1)
        return false;
    *n = s->num[s->top--];
    return true;
}

bool IsEmpty(SqStack s) {
    return s.top == -1;
}

double operate(int n1, int n2, char op) {
    switch (op) {
        case '+':
            return n1 + n2;
            break;
        case '-':
            return n1 - n2;
            break;
        case '*':
            return n1 * n2;
            break;
        case '/':
            return n1 / n2;
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}

double CalPostfix(char* str) {
    SqStack s;
    InitStack(&s);
    while (*str != '\0') {
        if (isdigit(*str)) {
            Push(&s, atof(str));
            while (isdigit(*str))
                str++;  // 跳过数字部分
        }else if(*str==' '){
            str++;
        }
         else {
            double n1, n2;
            Pop(&s, &n2);
            Pop(&s, &n1);
            double result = operate(n1, n2, *str);
            Push(&s, result);
            str++;
        }
    }
    double result;
    Pop(&s, &result);
    if (IsEmpty(s))
        return result;
    else
        return false;
}

int main() {
    char str[] = "2 5+2*4-";
    double result = CalPostfix(str);
    printf("%.2f", result);
    return 0;
}