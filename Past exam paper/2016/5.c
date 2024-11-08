#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20

bool check(char *str) {
    char stack[MAXSIZE];
    int top = -1;
    while (*str != '\0') {
        if (*str == '(' || *str == '[' || *str == '{') {
            stack[++top] = *str;

        } else if (*str == ')') {
            if (stack[top--] != '(') {
                return false;
            }

        } else if (*str == ']') {
            if (stack[top--] != '[') {
                return false;
            }

        } else if (*str == '}') {
            if (stack[top--] != '{') {
                return false;
            }
        }
        str++;
    }
    return top == -1;
}

int main() {
    char *str = "12+{[(2+1)*{1-2}]}";
    printf("%d", check(str));
    return 0;
}