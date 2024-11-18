#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *List;

List Merge(List a, List b) {
    if (a->next == NULL || b->next == NULL)
        return NULL;
    List c = a;
    LNode* tail = c;

    a = a->next;
    b = b->next;
    c->next = NULL;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            LNode* temp = a;
            a = a->next;
            tail->next = temp;
            tail = tail->next;
            tail->next = NULL;
        } else {
            LNode* temp = b;
            b = b->next;
            tail->next = temp;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    if (a != NULL) {
        tail->next = a;
    }
    if (b != NULL) {
        tail->next = b;
    }
    return c;
}

// 辅助函数：创建链表
List CreateList(int arr[], int size) {
    List head = (List)malloc(sizeof(LNode));
    head->next = NULL;
    List tail = head;

    for (int i = 0; i < size; i++) {
        List node = (List)malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    return head;
}

// 辅助函数：打印链表
void PrintList(List head) {
    List p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 测试
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6};

    List a = CreateList(arr1, 4);
    List b = CreateList(arr2, 3);

    printf("List a: ");
    PrintList(a);

    printf("List b: ");
    PrintList(b);

    List c = Merge(a, b);

    printf("Merged List: ");
    PrintList(c);

    return 0;
}