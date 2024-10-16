#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int precedent(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

float calculate(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// 弹出两个数字和一个操作符进行运算
void performOperation(float StackNum[], int *topNum, char StackOp[], int *topOp) {
    float n1 = StackNum[(*topNum)--];
    float n2 = StackNum[(*topNum)--];
    char op = StackOp[(*topOp)--];
    StackNum[++(*topNum)] = calculate(n2, n1, op);
}

float CalInfix(char* e) {
    float StackNum[MAXSIZE];
    char StackOp[MAXSIZE];
    int topNum = -1;
    int topOp = -1;
    int i = 0;

    while (e[i] != '\0') {
        if (isspace(e[i])) {
            i++;
            continue;
        }
        
        if (isdigit(e[i])) {
            float num;
            int offset;
            sscanf(e + i, "%f%n", &num, &offset);
            StackNum[++topNum] = num;
            i += offset;
        }
        
        else if (e[i] == '(') {
            StackOp[++topOp] = e[i];
            i++;
        }
        
        else if (e[i] == ')') {
            while (topOp != -1 && StackOp[topOp] != '(') {
                performOperation(StackNum, &topNum, StackOp, &topOp);
            }
            topOp--; // 弹出左括号
            i++;
        }
        
        else if (strchr("+-*/", e[i])) {
            while (topOp != -1 && precedent(StackOp[topOp]) >= precedent(e[i])) {
                performOperation(StackNum, &topNum, StackOp, &topOp);
            }
            StackOp[++topOp] = e[i];
            i++;
        }
    }

    while (topOp != -1) {
        performOperation(StackNum, &topNum, StackOp, &topOp);
    }
    return StackNum[topNum];
}

int main() {
    char expression[] = "15 + 5.2 * (2 - 1)";
    printf("结果: %f\n", CalInfix(expression));
    return 0;
}
