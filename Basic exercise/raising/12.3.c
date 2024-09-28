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

// 求集合 A-B，并将结果保存在链表 A 中
void difference(LinkList a, LinkList b) {
    // 初始化指针，pa 指向链表 A 的第一个实际节点，pb 指向链表 B 的第一个实际节点
    LNode* pa = a->next;
    LNode* pb = b->next;

    // 当链表 A 和链表 B 都没有遍历完时，进行比较
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            // 如果 A 的当前节点值小于 B 的当前节点值，则保留 A 中的节点
            // 移动 pa 指针到下一个节点
            pa = pa->next;
        } 
        else if (pa->data == pb->data) {
            // 如果 A 和 B 当前节点值相同，说明 A 中该节点应删除
            // 保存当前 A 节点，准备删除
            LNode* temp = pa;
            // 将 A 链表中 pa 指针跳过当前节点，直接指向下一个节点
            pa = pa->next;
            // 释放被删除节点的内存
            free(temp);
            // 移动 B 的指针到下一个节点
            pb = pb->next;
        } 
        else {
            // 如果 A 的当前节点值大于 B 的当前节点值，说明 B 当前元素在 A 中不存在
            // 移动 B 的指针到下一个节点，继续比较
            pb = pb->next;
        }
    }
}


int main() {
    
    return 0;
}