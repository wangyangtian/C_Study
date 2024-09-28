#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

void Union(LinkList a, LinkList b, LinkList c) {
    LNode* pa = a->next;
    LNode* pb = b->next;
    LNode* pc = c;

    while (pa != NULL) {
        LNode* temp = (LNode*)malloc(sizeof(LNode));
        temp->data=pa->data;
        temp->next = NULL;
        pc->next=temp;
        pc = temp;
        pa = pa->next;
    }
    
    // 遍历链表 b，将不在 c 中的节点加入到 c
    while (pb != NULL) {
        LNode* temp = c->next;  // 从链表 c 的第一个节点开始比较
        int exists = 0;  // 标志是否已经存在
        while (temp != NULL) {
            if (temp->data == pb->data) {  // 如果找到相同元素
                exists = 1;
                break;
            }
            temp = temp->next;
        }
        if(exists==0){  // 如果 pb 的元素不在 c 中
            LNode *newNode=(LNode*)malloc(sizeof(LNode));
            newNode->data=pb->data;
            newNode->next=NULL;
            pc->next=newNode;   // 插入到链表 c 尾部
            pc=newNode;
        }
        pb=pb->next;
    }
}

int main() {
    return 0;
}