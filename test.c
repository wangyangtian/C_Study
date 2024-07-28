#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack* S) {
    S->top = -1;
}

bool EmptyStack(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack* S, char e) {
    if (S->top == MAXSIZE - 1) return false; // 栈满
    S->data[++(S->top)] = e;
    return true;
}

bool Pop(SqStack* S, char* e) {
    if (EmptyStack(*S)) return false; // 栈空
    *e = S->data[(S->top)--];
    return true;
}

bool BracketCheck(char* str) {
    SqStack S;
    InitStack(&S);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(&S, str[i]);
        } else {
            if (EmptyStack(S)) return false;

            char topelem;
            Pop(&S, &topelem);
            if (topelem == '(' && str[i] != ')') return false;
            if (topelem == '[' && str[i] != ']') return false;
            if (topelem == '{' && str[i] != '}') return false;
        }
        i++;
    }
    return EmptyStack(S);
}

int main() {
    char* test1 = "{[()]}";
    char* test2 = "{[(])}";
    char* test3 = "{[}";
    char* test4 = "";
    char* test5 = "({[()]})";

    printf("Test 1: %s - %s\n", test1, BracketCheck(test1) ? "Valid" : "Invalid");
    printf("Test 2: %s - %s\n", test2, BracketCheck(test2) ? "Valid" : "Invalid");
    printf("Test 3: %s - %s\n", test3, BracketCheck(test3) ? "Valid" : "Invalid");
    printf("Test 4: %s - %s\n", test4, BracketCheck(test4) ? "Valid" : "Invalid");
    printf("Test 5: %s - %s\n", test5, BracketCheck(test5) ? "Valid" : "Invalid");

    return 0;
}
