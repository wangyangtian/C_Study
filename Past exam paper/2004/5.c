#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

bool check(char str[]) {
    char stack[MAXSIZE];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack[++top] = str[i];
        } else if (str[i] == ')') {
            char topelem = stack[top--];
            if (topelem != '(')
                return false;
        } else if (str[i] == ']') {
            char topelem = stack[top--];
            if (topelem != '[')
                return false;
        } else if (str[i] == '}') {
            char topelem = stack[top--];
            if (topelem != '{')
                return false;
        } else {
            continue;
        }
    }
    if (top != -1)
        return false;
    return true;
}

int main() {
    char str[] = "{(rwr)(ff[[])}";
    printf("%d", check(str));
    return 0;
}