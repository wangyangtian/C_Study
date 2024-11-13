#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DList {
    int data;
    struct DList* prior;
    struct DList* next;
} DNode, *DList;

DList* merge(DList a, DList b) {
    DNode* currentA;
    DNode* currentB = b->next;

    while (currentB != NULL) {
        DNode* currentA = a->next;
        int found = 0;

        // 查找 currentB 的数据是否已存在于 a 中
        while (currentA != NULL) {
            if (currentA->data == currentB->data) {
                found = 1;
                break;
            }
            currentA = currentA->next;
        }

        if (!found) {
            DNode* new = (DNode*)malloc(sizeof(DNode));
            new->data = currentB->data;
            new->next = NULL;

            // 找到 a 的最后一个节点
            DNode* tail = a;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = new;
            new->prior = tail;
        }
        currentB = currentB->next;
    }
    return a;
}

int main() {
    return 0;
}