#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

typedef struct Circular_Double_Linked_List
{
    int data;
    struct Circular_Double_Linked_List *next;
    struct Circular_Double_Linked_List *prior;
}DLNode,*DLinkList;

bool InitList(DLinkList*L){
    (*L)=(DLNode*)malloc(sizeof(DLNode));
    if ((*L)==NULL)
        return false;
    (*L)->next=(*L);
    (*L)->prior=(*L);
    return true;
}

bool Empty(DLinkList L){
    if(L->next==L)
        return true;
    else
        return false;
}

bool IsTail(DLinkList L,DLNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}
int main(){
    return 0;
}