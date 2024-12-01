#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 13

typedef struct ElemList {
    int value;
    struct ElemList *next;
} Node, *List;

typedef struct Table {
    List *lists;
    int size;
} Table;

int Hash(int k, int size) {
    return k % size;
}

void InitTable(Table *t) {
    t->size = HASHSIZE;
    t->lists = (List *)malloc(sizeof(List) * t->size);
    for (int i = 0; i < t->size; i++) {
        t->lists[i] = (Node *)malloc(sizeof(Node));
        t->lists[i]->next = NULL;
    }
}

void Insert(Table *t, int elem) {
    int index = Hash(elem, HASHSIZE);
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = elem;
    node->next = t->lists[index]->next;
    t->lists[index]->next = node;
    printf("Inserted value %d at index %d\n", elem, index);
}

int Search(Table *t, int elem) {
    int index = Hash(elem, HASHSIZE);
    Node *current = t->lists[index]->next;

    while (current != NULL) {
        if (current->value == elem) {
            printf("Searched value %d at index %d\n", elem, index);
            return 1;
        }

        current = current->next;
    }
    printf("Value %d not found \n", elem);
    return 0;
}

void Delete(Table *t, int k) {
    int index = Hash(k, HASHSIZE);
    Node *current = t->lists[index]->next;
    Node *prev = t->lists[index];

    while (current != NULL) {
        if (current->value == k) {
            prev->next = current->next;
            free(current);
            printf("Delete value %d at index %d\n", k, index);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Value %d not found , nothing deleted\n", k);
}

int main() {
    Table t;
    InitTable(&t);
    int a[] = {13, 11, 24, 25};
    for (int i = 0; i < 4; i++) {
        Insert(&t, a[i]);
    }
    Search(&t, 24);
    Delete(&t, 24);
    Search(&t, 24);
    return 0;
}