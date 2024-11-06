#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _List {
    int data;
    struct _List* next;
} Node, *List;

int findMax(List l, int max) {
    if (l->next == NULL)
        return max;
    max = max > l->next->data ? max : l->next->data;
    findMax(l->next, max);
}

int main() {
    Node n3 = {3, NULL};
    Node n2 = {7, &n3};
    Node n1 = {5, &n2};
    List head = &n1;

    int max = findMax(head, head->data);
    printf("Max value: %d\n", max);
    return 0;
}