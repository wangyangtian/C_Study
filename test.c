#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node, *List;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 初始化链表
List createList(int arr[], int size) {
    if (size == 0)
        return NULL;

    List head = createNode(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 打印链表
void printList(List head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 交换函数
void exchange(List l, Node* p) {
    Node* t = l;
    while (t) {
        if (t->next == p) {
            Node* q = p->next;
            p->next = q->next;
            q->next = p;
            t->next = q;
            break;
        }
        t = t->next;
    }
}

// 主函数测试
int main() {
    // 初始化链表
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    List head = createList(arr, size);

    printf("原始链表：\n");
    printList(head);

    // 获取要交换的节点
    Node* p = head->next;

    // 调用交换函数
    exchange(head, p);

    printf("\n交换后链表：\n");
    printList(head);

    return 0;
}
