#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct List {
    int data;
    struct List *next;
} Node, *List;

bool isSymmetry(List l, int n) {
    if (l == NULL || n <= 0) {
        return true;  // 空链表或长度为 0，认为是对称的
    }

    int stack[MAXSIZE];
    int top = -1;
    Node *p;
    p = l->next;
    for (int i = 0; i < n; i++) {
        stack[++top] = p->data;
        p = p->next;
    }

    p = l->next;
    for (int i = 0; i < n; i++) {
        if (stack[top--] != p->data)
            return false;
        p = p->next;
    }
    return true;
}

// 辅助函数：创建链表节点
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：打印链表
void printList(List l) {
    Node *p = l->next;  // 跳过头节点
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 测试函数
int main() {
    // 创建一个带头节点的链表
    List head = (List)malloc(sizeof(Node));
    if (!head) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;

    // 添加节点：1 -> 2 -> 3 -> 2 -> 1 -> NULL
    int data[] = {1, 2, 3, 2, 1};
    int n = sizeof(data) / sizeof(data[0]);
    Node *current = head;

    for (int i = 0; i < n; i++) {
        current->next = createNode(data[i]);
        current = current->next;
    }

    printf("Original List:\n");
    printList(head);

    // 检查链表是否对称
    if (isSymmetry(head, n)) {
        printf("The list is symmetric.\n");
    } else {
        printf("The list is not symmetric.\n");
    }

    return 0;
}