#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

// 定义一个简单的优先级函数
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// 执行运算
int Calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;  // 假设输入不会有除以0的情况
    }
    return 0;
}

// 计算中缀表达式的值
int CalInfix(char* str) {
    int i = 0;
    int StackNum[MAXSIZE];        // 数字栈
    char StackOp[MAXSIZE];        // 操作符栈
    int topNum = -1, topOp = -1;  // 栈顶指针

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            i++;
            continue;  // 跳过空格
        }

        // 如果是数字，压入数字栈
        if (isdigit(str[i])) {
            int num = 0;
            while (isdigit(str[i])) {  // 处理多位数
                num = num * 10 + (str[i] - '0');
                i++;
            }
            StackNum[++topNum] = num;  // 压入数字栈
        }

        // 如果是左括号，直接压入操作符栈
        else if (str[i] == '(') {
            StackOp[++topOp] = str[i];
            i++;
        }

        // 如果是右括号，则计算直到遇到左括号
        else if (str[i] == ')') {
            while (topOp != -1 && StackOp[topOp] != '(') {
                int b = StackNum[topNum--];
                int a = StackNum[topNum--];
                char op = StackOp[topOp--];
                StackNum[++topNum] = Calculate(a, b, op);  // 计算结果压回数字栈
            }
            topOp--;  // 弹出 '('
            i++;
        }

        // 如果是操作符
        else if (strchr("+-*/", str[i])) {
            while (topOp != -1 &&
                   precedence(StackOp[topOp]) >= precedence(str[i])) {
                int b = StackNum[topNum--];
                int a = StackNum[topNum--];
                char op = StackOp[topOp--];
                StackNum[++topNum] = Calculate(a, b, op);  // 计算结果压回数字栈
            }
            StackOp[++topOp] = str[i];  // 当前操作符压入栈
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
