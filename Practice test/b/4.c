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

void reverse(List l) {
    Node* current = l->next;
    l->next = NULL;

    while (current != NULL) {
        Node* temp = current->next;
        current->next = l->next;
        l->next = current;
        current = temp;
    }
}

// 辅助函数：创建链表节点
List createNode(int data) {
    List newNode = (List)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：打印链表
void printList(List l) {
    Node* temp = l->next;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建一个带头节点的链表
    List head = createNode(0);  // 头节点，不存储有效数据
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    reverse(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}