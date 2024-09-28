#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

typedef struct SStack {
    int data[MAXSIZE];
    int topl;
    int topr;
} SStack;

// 出栈
int pop(SStack* s, int flag) {
    if (flag == 1) {
        if (s->topl == -1)
            return -1;
        else
            return s->data[s->topl--];
    } else if (flag == 2) {
        if (s->topr == MAXSIZE)
            return -1;
        else
            return s->data[s->topr++];
    }
    return -1;
}

int push(SStack* s, int elem, int flag) {
    if (flag == 1) {
        if (s->topl + 1 == s->topr)
            return -1;
        else
            s->data[++s->topl]=elem;
    }
    else if(flag==2){
        if (s->topl + 1 == s->topr)
            return -1;
        else
            s->data[--s->topr]=elem;
    }
    return -1;
}

int main() {
    return 0;
}