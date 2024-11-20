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

void insert(List l, int pos, int e) {
    if (pos < 0)
        return;

    Node* p = l;
    Node* prev = p;
    while (pos > 0) {
        prev = p;
        p = p->next;
        pos--;
    }
    if (p == NULL) {
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    prev->next = newNode;
    newNode->next = p;
}

int main() {
    return 0;
}