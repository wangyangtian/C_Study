#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

typedef struct Circular_Singly_Linked_List
{
    int data;
    struct Circular_Singly_Linked_List *next;
}LNode,*LinkList;

bool InitList(LinkList*L){
    (*L)=(LNode*)malloc(sizeof(LNode));
    if ((*L)==NULL)
        return false;
    (*L)->next=(*L);
    return true;
}

bool Empty(LinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}

bool IsTail(LinkList L,LNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}
int main(){
    return 0;
}