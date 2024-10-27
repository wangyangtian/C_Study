#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct _DLinkNode{
    int data;
    struct _DLinkNode* prior;
    struct _DLinkNode* next;
} DNode, *DList;

bool Init(DList* L){
    *L = (DNode*) malloc(sizeof(DNode));
    if(*L==NULL)
        return false;
    (*L)->next = (*L)->prior = (*L);
    return true;
}

DNode* Location(DList L,int x){
    DNode* current = L->next;
    while(current!=L){
        if(x==current->data)
            return current;
        current = current->next;
    }
    return NULL;
}

//头插法
bool Insert(DList *L,int x){
    DNode* newNode = (DNode*) malloc(sizeof(DNode));
    if(newNode==NULL)
        return false;
    newNode->data  = x;
    newNode->next  = (*L)->next;
    newNode->prior = (*L);
    (*L)->next->prior = newNode;
    (*L)->next        = newNode;
    return true;
}

bool Delete(DList*L,int elem){
    DNode* current = (*L)->next;
    while(current!=*L){
        if(current->data==elem){
            current->prior->next = current->next;
            current->next->prior = current->prior;
            free(current);
            return true;
        }
        current = current->next;
    }
    return false;
}


int main() {
    
    return 0;
}