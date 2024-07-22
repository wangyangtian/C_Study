#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
typedef struct Double_linked_list {
    int data;
    struct Double_linked_list *prior;
    struct Double_linked_list *next;
} DNode, *DLinkList;

// 删除节点的后继节点
bool DeleteNextDNode(DNode *p) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

// 销毁双向链表
void DestroyList(DLinkList *L)
{
    DNode *temp;
    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

int main() {
    // 创建一个简单的双向链表用于测试
    DLinkList L = (DLinkList)malloc(sizeof(DNode));
    L->data = 1;
    L->prior = NULL;
    L->next = (DLinkList)malloc(sizeof(DNode));
    L->next->data = 2;
    L->next->prior = L;
    L->next->next = (DLinkList)malloc(sizeof(DNode));
    L->next->next->data = 3;
    L->next->next->prior = L->next;
    L->next->next->next = NULL;

    // 销毁链表
    DestroyList(&L);

    // 打印链表以验证链表是否被销毁
    if (L == NULL) {
        printf("链表已成功销毁\n");
    } else {
        printf("链表销毁失败\n");
    }

    return 0;
}
