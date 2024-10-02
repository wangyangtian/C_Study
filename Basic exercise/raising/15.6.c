#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 判断后缀表达式的正确性
bool isValidPostfix(char* postfix) {
    int i = 0;
    int stackCount = 0;

    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            i++;
            continue;
        }
        if (isdigit(postfix[i])) {
            stackCount++;
            i++;
        } else if (strchr("+-*/", postfix[i])) {
            if (stackCount < 2)
                return false;
            stackCount--;
            i++;
        } else
            return false;
    }
    return stackCount == 1;
}

// 将后缀表达式转换为前缀表达式
char* PostfixToPrefix(char* postfix) {
    char* stack[10];
    int top = -1;
    int i = 0;
    while (postfix[i] != '\0') {
        if (isspace(postfix[i])) {
            i++;
            continue;
        }
        if (isdigit(postfix[i])) {
            char* n = (char*)malloc(10);
            n[0] = postfix[i++];
            n[1] = '\0';
            stack[++top] = n;
        } else if (strchr("+-*/", postfix[i])) {
            char* n1 = stack[top--];
            char* n2 = stack[top--];
            char* expr = (char*)malloc(strlen(n1)+strlen(n2)+2);
            sprintf(expr, "%c%s%s", postfix[i], n2, n1);
            stack[++top] = expr;
            i++;
        }
    }
    return stack[top];
}
int main() {
    char postfix[] = "123*+4*";  // 一个有效的后缀表达式

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