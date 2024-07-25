#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

void freeList(LinkList L) {
    LNode* temp;
    while (L != NULL) {
        temp = L;
        L = L->next;
        free(temp);
    }
}

bool SplitByParity(LinkList *A,LinkList *B){
    LNode *pAL=(*A)->next;
    LNode *pAR=(*A)->next;
    LNode *pB=*B;
    if((*A)->next==NULL)    return false;
    if((*B)->next!=NULL)    freeList(*B);
    while (pAR!=NULL)
    {
        if((pAR->data%2!=0)&&(pAL==pAR))
        {
            pAR=pAR->next;
        }
        else if((pAR->data%2!=0)&&(pAL!=pAR))
        {
            pAR=pAR->next;
            pAL=pAL->next;
        }
        else
        {
            pAL->next=pAR->next;
            pAR->next=NULL;
            pB->next=pAR;
            pB=pB->next;
            pAR=pAL->next;
        }     
    } 
    return true;
}

int main() {
    // 测试代码
    LinkList A = (LinkList)malloc(sizeof(LNode));
    LinkList B = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;
    B->next = NULL;

    // 构建测试链表
    int arr[] = {1, 2, 2, 5, 5, 6,7,7,9,9};
    LNode* current = A;
    for (int i = 0; i < 10; i++) {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }

    SplitByParity(&A, &B);

    // 输出结果
    printf("链表A (奇数): ");
    current = A->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("链表B (偶数): ");
    current = B->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // 释放链表
    freeList(A);
    freeList(B);

    return 0;
}
