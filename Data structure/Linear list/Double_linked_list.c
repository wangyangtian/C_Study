#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
typedef struct Double_linked_list
{
    int data;
    struct Double_linked_list *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList *L)
{
    *L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return true;
}

bool Empty(DLinkList L)
{
    if (L->next == NULL)
        return false;
    else
        return true;
}

bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    s->prior = p;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode *p)//删除p结点的后继结点q
{
    if (p == NULL)
        return false;
    DNode* q=p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinkList *L)
{
    while ((*L)->next!=NULL)
        DeleteNextDNode((*L));
    free(*L);
    *L=NULL;    
}


int main()
{
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
    DNode * p=L;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
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