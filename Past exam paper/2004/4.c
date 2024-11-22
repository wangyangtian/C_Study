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

int josephus(int n, int k) {
    List l = (Node*)malloc(sizeof(Node));
    l->next = NULL;
    Node* current = l;

    for (int i = 1; i <= n; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        current->next = node;
        current = node;
    }
    current->next = l->next;

    current = l->next;
    Node* prev = l;

    while (n > 1) {
        // 找到第 k 个节点
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        // 删除当前节点
        prev->next = current->next;
        free(current);
        current = prev->next;
        n--;
    }

    int result = current->data;
    free(current);  // 释放最后一个节点
    free(l);        // 释放头节点
    return result;
}

int main() {
    printf("%d", josephus(10, 4));
    return 0;
}