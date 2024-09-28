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

void Merge(LinkList a, LinkList b, LinkList c) {
    LNode* pa = a->next;
    LNode* pb = b->next;
    LNode* pc = c;
    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            pc->next = pa;  // 将pa当前节点插入c
            pa = pa->next;
        } else {
            pc->next = pb;  // 将pb当前节点插入c
            pb = pb->next;
        }
        pc = pc->next;  // 移动pc到下一个节点
    }
    // 处理剩余节点
    pc->next = (pa != NULL) ? pa : pb;
}

int main() {
    return 0;
}