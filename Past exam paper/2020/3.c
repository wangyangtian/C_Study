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

void insert(List l, Node* n) {
    n->next = l->next;
    l->next = n;
}

List merge(List a, List b) {
    Node* currentA = a->next;
    Node* currentB = b->next;

    Node* newHead = a;
    newHead->next = NULL;
    while (currentA != NULL && currentB != NULL) {
        if (currentA->data <= currentB->data) {
            // 如果A的当前节点值大于等于B的当前节点值，插入A节点
            Node* temp = currentA;
            currentA = currentA->next;
            insert(newHead, temp);
        } else {
            // 如果B的当前节点值大于A的当前节点值，插入B节点
            Node* temp = currentB;
            currentB = currentB->next;
            insert(newHead, temp);
        }
    }

    // 如果A链表还有剩余，插入A的剩余节点
    while (currentA != NULL) {
        Node* temp = currentA;
        currentA = currentA->next;
        insert(newHead, temp);
    }

    // 如果B链表还有剩余，插入B的剩余节点
    while (currentB != NULL) {
        Node* temp = currentB;
        currentB = currentB->next;
        insert(newHead, temp);
    }

    return newHead;
}

// 打印链表
void printList(List l) {
    Node* current = l->next;  // 从第一个元素开始打印
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // 创建链表a
    List a = (List)malloc(sizeof(Node));
    a->next = NULL;
    insert(a, createNode(7));
    insert(a, createNode(5));
    insert(a, createNode(3));
    insert(a, createNode(1));

    // 创建链表b
    List b = (List)malloc(sizeof(Node));
    b->next = NULL;
    insert(b, createNode(6));
    insert(b, createNode(4));
    insert(b, createNode(2));

    printf("List A (ascending order): ");
    printList(a);
    printf("List B (ascending order): ");
    printList(b);

    // 合并链表a和b
    List mergedList = merge(a, b);

    printf("Merged List (descending order): ");
    printList(mergedList);

    return 0;
}