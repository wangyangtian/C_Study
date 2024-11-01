#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _List {
    int data;
    struct _List* next;
} Node, *List;

void deleteElem(List l, int maxk, int mink) {
    Node* prev = l;
    Node* current = l->next;

    while (current != NULL) {
        if (current->data < maxk && current->data > mink) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        }

        prev = prev->next;
        current = current->next;
    }
}

int main() {
    return 0;
}