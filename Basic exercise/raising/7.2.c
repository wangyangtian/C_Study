#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
    int InCircle;
    struct LNode* next;
} LNode, *LinkList;

int josephus(int n, int m) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* p = L;

    for (int i = 1; i <= n; i++) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->InCircle = i;
        p->next = s;
        s->next = NULL;
        p = s;
    }
    p->next = L->next;

    int remain = n;
    LNode *current = L->next; // current 用来指向当前节点
    LNode *prev=L;
    while (remain > 1) {
        // 找到需要删除的节点
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }
        // 删除节点,即每次淘汰一人
        prev->next = current->next;
        free(current);
        current = prev->next; // 更新当前节点为删除后的下一个节点
        remain--;
    }
    return current->InCircle;
}

int main() {
    printf("%d", josephus(5, 3));
    return 0;
}