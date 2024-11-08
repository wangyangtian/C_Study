#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

double op(char a, double d1, double d2) {
    switch (a) {
        case '+':
            return d1 + d2;
            break;
        case '-':
            return d1 - d2;
            break;
        case '*':
            return d1 * d2;
            break;
        case '/':
            return d1 / d2;
    }
}

double cal(char *e) {
    double digit_stack[MAXSIZE];
    char operate_stack[MAXSIZE];
    int top_d = -1;
    int top_o = -1;
    while (*e != '\0') {
        if (isdigit(*e)) {
            digit_stack[++top_d] = (*e) - '0';
        } else {
            int d2 = digit_stack[top_d--];
            int d1 = digit_stack[top_d--];
            digit_stack[++top_d] = op(*e, d1, d2);
        }
        e++;
    }
    return digit_stack[top_d];
}

int main() {
    char a[] = "223*+4/1-";
    printf("%.2lf", cal(a));
    return 0;
}