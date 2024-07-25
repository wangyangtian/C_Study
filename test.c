#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建新的链表节点
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void DeleteNode(ListNode* p)
{
    ListNode* temp=p->next;
    p->val=temp->val;
    p->next=temp->next;
    free(temp);
}
// 删除链表中值域重复的节点
void removeDuplicates(ListNode** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    ListNode* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            DeleteNode(current);
        } else {
            current = current->next;
        }
    }
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // 创建示例链表: 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4 -> 4 -> 4 -> 7 -> 7 -> 7 -> 9 -> 9 -> 9
    ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next->next->next->next->next->next = createNode(9);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next = createNode(9);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next = createNode(9);

    printf("Original list: ");
    printList(head);

    removeDuplicates(&head);

    printf("List after removing duplicates: ");
    printList(head);

    freeList(head);

    return 0;
}
