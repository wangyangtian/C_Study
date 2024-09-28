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

// 将两个递增有序的带头结点单链表 A、B 合并为一个递减有序的链表 C
void MergeDecline(LinkList a, LinkList b, LinkList c) {
    // pa 指向链表 A 的第一个实际节点，pb 指向链表 B 的第一个实际节点
    LNode* pa = a->next;
    LNode* pb = b->next;
    // pc 指向链表 C 的头结点
    LNode* pc = c;

    // 当链表 A 和 B 都没有遍历完时，进行比较并将较大元素插入 C 链表的头部
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            // 如果 A 的当前节点数据小于 B 的当前节点数据
            // 将 A 当前节点插入到 C 链表的头部
            LNode* temp = pa;  // 暂存 A 当前节点
            pa = pa->next;     // A 的指针向前移动
            temp->next = pc->next;  // 将 temp 节点插入 C 链表头部
            pc->next = temp;
        } else {
            // 如果 B 的当前节点数据小于或等于 A 的当前节点数据
            // 将 B 当前节点插入到 C 链表的头部
            LNode* temp = pb;  // 暂存 B 当前节点
            pb = pb->next;     // B 的指针向前移动
            temp->next = pc->next;  // 将 temp 节点插入 C 链表头部
            pc->next = temp;
        }
    }

    // 如果 A 链表还有剩余节点，将这些节点插入 C 链表的头部
    while (pa != NULL) {
        LNode* temp = pa;  // 暂存 A 当前节点
        pa = pa->next;     // A 的指针向前移动
        temp->next = pc->next;  // 将 temp 节点插入 C 链表头部
        pc->next = temp;
    }

    // 如果 B 链表还有剩余节点，将这些节点插入 C 链表的头部
    while (pb != NULL) {
        LNode* temp = pb;  // 暂存 B 当前节点
        pb = pb->next;     // B 的指针向前移动
        temp->next = pc->next;  // 将 temp 节点插入 C 链表头部
        pc->next = temp;
    }
}


int main() {
    return 0;
}