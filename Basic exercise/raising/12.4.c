#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

void Intersection(LinkList a, LinkList b, LinkList c) {
    // 初始化指针
    LNode *pa = a->next;
    LNode *pb = b->next;
    LNode *pc = c;  // c为交集链表的头结点

    // 同时遍历链表 A 和 B
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            // 如果 A 当前节点的值小于 B 当前节点的值，继续向后遍历 A
            pa = pa->next;
        } else if (pa->data == pb->data) {
            // 找到交集元素，将当前 A 节点加入 C 链表
            LNode* temp = pa;  // 暂存 A 当前节点
            pa = pa->next;     // A 向后移动
            pb = pb->next;     // B 向后移动
            temp->next = NULL; // 防止形成循环链表
            pc->next = temp;   // 将交集元素加入 C 链表
            pc = pc->next;     // 移动 pc 指针到新加入的节点
        } else {
            // 如果 A 当前节点的值大于 B 当前节点的值，继续向后遍历 B
            pb = pb->next;
        }
    }

    // 最终交集链表 C 的 pc->next 应为空，避免不必要的链表延伸
    pc->next = NULL;
}


int main() {
    
    return 0;
}