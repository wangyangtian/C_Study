#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link {
    int          data;
    struct Link* next;
} LinkNode, *LinkList;

void Init(LinkList* l, int n) {
    // 创建头结点
    LinkNode* head = (LinkNode*) malloc(sizeof(LinkNode));
    head->data     = 1;
    *l             = head; // 初始化链表头指针

    LinkNode* current = head; // 用于遍历链表

    for (int i = 2; i <= n; i++) {
        LinkNode* newNode = (LinkNode*) malloc(sizeof(LinkNode));
        newNode->data     = i;
        current->next     = newNode;
        current           = current->next;
    }
    current->next = head;
}

void Delete(LinkNode* prev) {
    LinkNode* current = prev->next;
    prev->next        = current->next;
    free(current);
}

int josephus(LinkList* l) {
    LinkNode* current = *l;

    while (current->next != current) {
        current = current->next;
        Delete(current);
        current = current->next;
    }
    return current->data;
}

int main() {
    int n;
    scanf("%d", &n);
    LinkList l = (LinkList) malloc(sizeof(LinkNode) * n);
    Init(&l, n);
    printf("最后一人编号：%d", josephus(&l));
    return 0;
}