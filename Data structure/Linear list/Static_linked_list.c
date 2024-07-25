#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

#define MAXSIZE 10

typedef struct Static_linked_list {
    int data;
    int cursor;
} SLinkList[MAXSIZE];

// 初始化链表
bool InitList(SLinkList L) {
    L[0].cursor = -1;  // 头结点cursor初始化为-1，表示链表结束
    for (int i = 1; i < MAXSIZE - 1; i++) {
        L[i].cursor = i + 1;  // 将所有空闲结点链接起来
    }
    L[MAXSIZE - 1].cursor = -1;  // 最后一个结点指向链表结束
    return true;
}

// 寻找第一个空闲结点
int Malloc_SL(SLinkList L) {
    int i = L[1].cursor; // 1号位是空闲链表的头结点
    if (i != -1) {
        L[1].cursor = L[i].cursor;  // 更新头结点的cursor指向下一个空闲结点
    }
    return i;
}

// 释放结点
void Free_SL(SLinkList L, int i) {
    L[i].cursor = L[1].cursor;
    L[1].cursor = i;
}

// 插入元素
bool ListInsert(SLinkList L, int index, int data) {
    if (index < 1 || index > MAXSIZE - 1) return false;  // 插入位置不合法

    int i = Malloc_SL(L);  // 分配新的结点
    if (i != -1) {
        L[i].data = data;

        int j = 0;  // 头结点
        for (int k = 1; k < index; k++) {
            j = L[j].cursor;
            if (j == -1) return false;  // 如果到了链表尾部还没到达index，说明index不合法
        }
        L[i].cursor = L[j].cursor;
        L[j].cursor = i;
        return true;
    }
    return false;  // 空间已满，无法插入
}

// 删除元素
bool ListDelete(SLinkList L, int index) {
    if (index < 1 || index > MAXSIZE - 1) return false;  // 删除位置不合法

    int j = 0;  // 头结点
    for (int k = 1; k < index; k++) {
        j = L[j].cursor;
        if (j == -1) return false;  // 如果到了链表尾部还没到达index，说明index不合法
    }
    int i = L[j].cursor;
    if (i != -1) {
        L[j].cursor = L[i].cursor;
        Free_SL(L, i);
        return true;
    }
    return false;  // 删除位置不合法
}

// 打印链表
void PrintList(SLinkList L) {
    int i = L[0].cursor;
    while (i != -1) {
        printf("%d ", L[i].data);
        i = L[i].cursor;
    }
    printf("\n");
}

int main() {
    SLinkList L;
    InitList(L);

    ListInsert(L, 1, 10);  // 在第1个位置插入数据10
    ListInsert(L, 2, 20);  // 在第2个位置插入数据20
    ListInsert(L, 3, 30);  // 在第3个位置插入数据30
    PrintList(L);          // 打印链表

    ListDelete(L, 2);      // 删除第2个位置的元素
    PrintList(L);          // 打印链表

    ListInsert(L, 2, 40);  // 在第2个位置插入数据40
    PrintList(L);          // 打印链表

    return 0;
}
