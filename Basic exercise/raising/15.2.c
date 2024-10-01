#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

float Calculate(float a, float b, char op) {
    switch (op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
    }
}

int CalInfix(char* str) {
    int i = 0;
    float StackNum[MAXSIZE];
    char StackOp[MAXSIZE];
    int topNum = -1, topOp = -1;
    char op;
    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;
        }
        if (isdigit(str[i])) {
            int num = 0;
            while (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            StackNum[++topNum] = num;
        } else if (str[i] == '(') {
            StackOp[++topOp] = str[i];
            i++;
        } else if (str[i] == ')') {
            while (topOp != -1 && StackOp[topOp] != '(') {
                int n1 = StackNum[topNum--];
                int n2 = StackNum[topNum--];
                char op = StackOp[topOp--];
                StackNum[++topNum] = Calculate(n2, n1, op);
            }
            topOp--;
            i++;
        } else if (strchr("+-*/", str[i])) {
            while (topOp != -1 &&
                   precedence(StackOp[topOp]) >= precedence(str[i])) {
                int n1 = StackNum[topNum--];
                int n2 = StackNum[topNum--];
                char op = StackOp[topOp--];
                StackNum[++topNum] = Calculate(n2, n1, op);
            }
            StackOp[++topOp] = str[i];
            i++;
        }
    }
    // 处理栈中的剩余操作符
    while (topOp != -1) {
        int b = StackNum[topNum--];
        int a = StackNum[topNum--];
        char op = StackOp[topOp--];
        StackNum[++topNum] = Calculate(a, b, op);  // 计算结果压回数字栈
    }

    // 最终结果在数字栈的栈顶
    return StackNum[topNum];
}

int main() {
    char expression[MAXSIZE];

    printf("请输入中缀表达式（例如3+5*(2-1)）：");
    fgets(expression, MAXSIZE, stdin);  // 获取用户输入的表达式

    int result = CalInfix(expression);  // 计算结果
    printf("表达式的计算结果为: %d\n", result);

    return 0;
}