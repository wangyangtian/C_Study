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

List Intersection(List a, List b) {
    Node* currentA = a->next;
    Node* currentB = b->next;
    Node* res = (Node*)malloc(sizeof(Node));
    res->next = NULL;
    while (currentA != NULL && currentB != NULL) {
        if (currentA->data == currentB->data) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->data = currentA->data;
            node->next = res->next;
            res->next = node;
        } else if (currentA->data < currentB->data) {
            currentA = currentA->next;
        } else {
            currentB = currentB->next;
        }
    }
    return res;
}

int main() {
    return 0;
}