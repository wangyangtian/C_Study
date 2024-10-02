#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 判断后缀表达式的正确性
bool isValidPostfix(char* postfix) {
    int stackCount = 0;  // 用来计数操作数栈的大小
    int i = 0;

    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {  // 跳过空白字符
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {  // 如果是操作数，栈大小+1
            stackCount++;
            while (isdigit(postfix[i]))
                i++;                              // 跳过多位数
        } else if (strchr("+-*/", postfix[i])) {  // 如果是操作符，栈大小-2+1
            if (stackCount < 2) {
                return false;  // 操作数不足，表达式无效
            }
            stackCount--;  // 两个操作数被一个结果替代
            i++;
        } else {
            return false;  // 非法字符
        }
    }

    return stackCount == 1;  // 最后栈中应剩下一个操作数
}

// 将后缀表达式转换为前缀表达式
char* PostfixToPrefix(char* postfix) {
    char* stack[100];  // 用来存储前缀表达式片段的栈
    int top = -1;      // 栈顶指针

    int i = 0;
    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {  // 跳过空白字符
            i++;
            continue;
        }

        // 如果是操作数，将其压入栈中
        if (isdigit(postfix[i])) {
            char* operand = (char*)malloc(2);  // 分配内存给操作数
            operand[0] = postfix[i++];
            operand[1] = '\0';     // 结束符
            stack[++top] = operand;  // 将操作数压入栈
        }
        // 如果是操作符
        else if (strchr("+-*/", postfix[i])) {
            // 弹出栈顶的两个操作数
            char* operand2 = stack[top--];
            char* operand1 = stack[top--];

            // 构造新的前缀表达式
            char* expr = (char*)malloc(strlen(operand1) + strlen(operand2) +
                                       2);  // 为操作符+两个操作数分配空间
            sprintf(expr, "%c%s%s", postfix[i], operand1, operand2);

            // 释放掉不再需要的操作数内存
            free(operand1);
            free(operand2);

            // 将构造好的前缀表达式压回栈中
            stack[++top] = expr;
            i++;
        }
    }

    // 栈顶元素即为转换后的前缀表达式
    return stack[top];
}

int main() {
    char postfix[] = "1 3 * 4 +";  // 一个有效的后缀表达式

    // 判断后缀表达式的正确性
    if (isValidPostfix(postfix)) {
        printf("后缀表达式有效\n");

        // 将后缀表达式转换为前缀表达式
        char* prefix = PostfixToPrefix(postfix);
        printf("前缀表达式: %s\n", prefix);

        // 释放前缀表达式的内存
        free(prefix);
    } else {
        printf("后缀表达式无效\n");
    }

    return 0;
}
