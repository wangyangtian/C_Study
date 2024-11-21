#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct List {
    int data;
    struct List *next;
} Node, *List;

// 非递归逆置链表
List reverseList(List l) {
    if (l == NULL || l->next == NULL) {
        return l;  // 空链表或只有一个节点时，直接返回
    }

    Node *current = l->next;  // 指向链表的第一个有效节点
    Node *nextNode;           // 临时存储当前节点的下一个节点
    l->next = NULL;           // 断开头节点与第一个节点的连接（链表逆置后，头节点为新链表头）

    while (current != NULL) {
        nextNode = current->next;  // 保存下一个节点
        current->next = l->next;   // 当前节点的 next 指向新链表的头节点
        l->next = current;         // 更新新链表的头节点为当前节点
        current = nextNode;        // 继续处理下一个节点
    }

    return l;
}

// 打印链表
void printList(List l) {
    Node *current = l->next;  // 从第一个有效节点开始
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 创建链表节点
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

// 测试非递归逆置链表
int main() {
    // 创建一个带头节点的链表
    List head = (List)malloc(sizeof(Node));  // 头节点
    if (!head) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;  // 初始化头节点

    // 添加节点：1 -> 2 -> 3 -> 4 -> NULL
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("Original List:\n");
    printList(head);

    // 逆置链表
    reverseList(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
