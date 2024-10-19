#include <stdio.h>
#include <stdlib.h>

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

    // 创建剩余的节点
    for (int i = 2; i <= n; i++) {
        LinkNode* newNode = (LinkNode*) malloc(sizeof(LinkNode));
        newNode->data     = i;
        current->next     = newNode;
        current           = newNode;
    }

    current->next = head; // 形成循环链表
}

void Delete(LinkNode* prev) {
    LinkNode* current = prev->next;
    prev->next        = current->next;
    free(current);
}

int josephus(LinkList* l, int n) {
    LinkNode* current = *l;

    while (current->next != current) { // 循环直到只剩一个节点
        // 每次报数到第 k 人，这里 k=2
        current = current->next; // 第一个人
        Delete(current);         // 删除第二个人
        current = current->next; // 移动到下一个人
    }

    return current->data; // 返回最后一个人的编号
}

int main() {
    int n;
    printf("请输入总人数: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("人数必须大于0。\n");
        return 1; // 输入有效性检查
    }

    LinkList l;
    Init(&l, n);
    printf("最后一人编号：%d\n", josephus(&l, n));

    // 释放链表内存
    LinkNode* temp;
    while (l) {
        temp = l;
        l    = l->next;
        free(temp);
    }

    return 0;
}
