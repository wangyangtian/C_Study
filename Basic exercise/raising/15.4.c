#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数：返回操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-')  // 加减法的优先级为1
        return 1;
    if (op == '*' || op == '/')  // 乘除法的优先级为2
        return 2;
    return 0;  // 其他情况优先级为0
}

// 函数：将中缀表达式转换为后缀表达式
char* InfixToPostfix(char* str) {
    int i = 0, j = 0;
    char* postfix =
        (char*)malloc(sizeof(char) * 100);  // 动态分配内存存储后缀表达式
    char stackOp[10];                       // 操作符栈
    int topOp = -1;                         // 操作符栈的栈顶指针

    // 遍历输入的中缀表达式
    while (str[i] != '\0') {
        if (isspace(str[i])) {  // 如果是空白字符，跳过
            i++;
            continue;
        }

        // 如果是数字，直接添加到后缀表达式中
        if (isdigit(str[i])) {
            postfix[j++] = str[i++];
        }
        // 如果是左括号，将其压入操作符栈
        else if (str[i] == '(') {
            stackOp[++topOp] = str[i];
            i++;
        }
        // 如果是右括号，弹出栈顶操作符，直到遇到左括号
        else if (str[i] == ')') {
            while (topOp != -1 && stackOp[topOp] != '(') {
                postfix[j++] = stackOp[topOp--];
            }
            topOp--;  // 弹出左括号
            i++;
        }
        // 如果是操作符，依次弹出优先级不小于当前操作符的栈顶操作符
        else if (strchr("+-*/", str[i])) {
            while (topOp != -1 &&
                   precedence(stackOp[topOp]) >= precedence(str[i])) {
                postfix[j++] = stackOp[topOp--];
            }
            stackOp[++topOp] = str[i];  // 将当前操作符压入栈
            i++;
        }
    }

    // 将栈中剩余的操作符依次弹出并添加到后缀表达式
    while (topOp != -1) {
        postfix[j++] = stackOp[topOp--];
    }

    postfix[j] = '\0';  // 给后缀表达式添加字符串结束符
    return postfix;     // 返回后缀表达式
}

int main() {
    char str[] = "(1+2*3)*4";       // 输入的中缀表达式
    char* p = InfixToPostfix(str);  // 将中缀表达式转换为后缀表达式
    printf("%s\n", p);              // 输出后缀表达式
    free(p);                        // 释放动态分配的内存
    return 0;
}
