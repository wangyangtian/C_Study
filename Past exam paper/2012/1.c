#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _CList {
    int data;
    struct _CList* next;
} Node, *List;

bool Init(List* L) {
    (*L) = (Node*)malloc(sizeof(Node));
    if (*L == NULL)
        return false;
    (*L)->next = (*L);
    return true;
}

void reverse(List* L) {
    Node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    p1 = *L;
    p2 = p1->next;
    while (p2 != *L) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    (*L)->next = p1;
}

// 测试函数
void printList(List L) {
    if (L == NULL)
        return;
    Node* current = L->next;
    while (current != L) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List myList;
    if (!Init(&myList)) {
        printf("初始化失败\n");
        return 1;
    }

    // 示例插入
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->data = 1;
    newNode1->next = myList->next;
    myList->next = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->data = 2;
    newNode2->next = myList->next;
    myList->next = newNode2;

    Node* newNode3 = (Node*)malloc(sizeof(Node));
    newNode3->data = 3;
    newNode3->next = myList->next;
    myList->next = newNode3;

    printf("原链表：");
    printList(myList);

    reverse(&myList);
    printf("反转后的链表：");
    printList(myList);

    return 0;
}