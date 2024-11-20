#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
    int data;
    struct List* next;
} Node, *List;

void exchange(List l, Node* p) {
    Node* t = l;
    while (t) {
        if (t->next == p) {
            Node* q = p->next;
            p->next = q->next;
            q->next = p;
            t->next = q;
            break;
        }
        t = t->next;
    }
}

int main() {
    return 0;
}