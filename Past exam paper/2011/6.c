#include <stdio.h>
#include <stdlib.h>

typedef struct _LNode {
    int data;
    struct _LNode* next;
} LNode, *List;

List createList(int[], int);
void printList(List);
void merge(List, List);
void freeList(List);

void merge(List a, List b) {
    LNode* current_a = a;
    LNode* current_b = b->next;

    while (current_a->next != NULL & current_b != NULL) {
        if (current_b->data <= current_a->next->data) {
            LNode* temp = current_b->next;
            current_b->next = current_a->next;
            current_a->next = current_b;
            current_b = temp;
        } else
            current_a = current_a->next;
    }

    // 如果 b 链表还有剩余节点，直接连接到 a 的末尾
    if (current_b != NULL) {
        current_a->next = current_b;
    }
}

// 创建带头节点的链表
List createList(int arr[], int size) {
    List head = (LNode*)malloc(sizeof(LNode));
    head->next = NULL;
    LNode* tail = head;

    for (int i = 0; i < size; i++) {
        LNode* newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// 打印链表
void printList(List head) {
    LNode* current = head->next;  // 跳过头节点
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(List head) {
    LNode* current = head;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    List a = createList(arr1, 4);
    List b = createList(arr2, 4);

    printf("List a: ");
    printList(a);
    printf("List b: ");
    printList(b);

    merge(a, b);

    printf("Merged list: ");
    printList(a);

    // 释放内存
    freeList(a);
    freeList(b);

    return 0;
}