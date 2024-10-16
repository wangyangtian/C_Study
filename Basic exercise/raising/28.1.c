#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Polyn {
    float coef;
    int expn;
    struct Polyn* next;
} PNode, *PList;

bool Init(PList* p) {
    *p = (PList)malloc(sizeof(PNode));
    if (*p == NULL)  // 内存不足，分配失败
    {
        printf("内存空间不足，分配空间失败\n");
        return false;
    }
    (*p)->next = NULL;  // 头结点之后暂时没有节点
    return true;
}

bool Insert(PList* p, int c, int e) {
    if (p == NULL)
        return false;
    PNode* n = (PNode*)malloc(sizeof(PNode));
    n->coef = c;
    n->expn = e;
    n->next = NULL;

    // 找到插入位置，保持链表按指数升序排列
    PNode* current = *p;
    while (current->next != NULL && current->next->expn < e)
        current = current->next;

    // 若找到相同指数的项，合并系数
    if (current->next != NULL && current->next->expn == e) {
        current->next->coef += c;
        free(n);  // 不需要新节点，释放内存
    } else {
        // 插入新节点
        n->next = current->next;
        current->next = n;
    }
    return true;
}

void printPloyn(PList p) {
    p = p->next;
    printf("%.2fx^%d", p->coef, p->expn);
    p = p->next;
    while (p != NULL) {
        if (p->coef > 0)
            printf("+%.2fx^%d", p->coef, p->expn);
        else
            printf("%.2fx^%d", p->coef, p->expn);
        p = p->next;
    }
}

PList addPloyn(PList p1, PList p2) {
    PList p3;
    Init(&p3);

    PNode* ptr1 = p1->next;
    PNode* ptr2 = p2->next;

    // 直接插入每一项到 p3 中
    while (ptr1 != NULL) {
        Insert(&p3, ptr1->coef, ptr1->expn);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        Insert(&p3, ptr2->coef, ptr2->expn);
        ptr2 = ptr2->next;
    }

    return p3;
}

PList SubPloyn(PList p1, PList p2) {
    PList p3;
    Init(&p3);

    PNode* ptr1 = p1->next;
    PNode* ptr2 = p2->next;

    // 将 p1 的每一项直接插入到 p3 中
    while (ptr1 != NULL) {
        Insert(&p3, ptr1->coef, ptr1->expn);
        ptr1 = ptr1->next;
    }

    // 将 p2 的每一项的系数取负后插入到 p3 中
    while (ptr2 != NULL) {
        Insert(&p3, -ptr2->coef, ptr2->expn);
        ptr2 = ptr2->next;
    }

    return p3;
}

PList MultPloyn(PList p1, PList p2) {
    PList p3;
    Init(&p3);
    for (PNode* ptr1 = p1->next; ptr1 != NULL; ptr1 = ptr1->next) {
        for (PNode* ptr2 = p2->next; ptr2 != NULL; ptr2 = ptr2->next) {
            float tempCoef = ptr1->coef * ptr2->coef;
            int tempExpn = ptr1->expn + ptr2->expn;
            Insert(&p3, tempCoef, tempExpn);
        }
    }
    return p3;
}

int main() {
    PList p1, p2, p3;
    Init(&p1);
    Init(&p2);
    Init(&p3);
    int n;
    float c;
    int e;
    printf("输入多项式p1项数n:\n");
    scanf("%d", &n);
    printf("输入多项式系数c和指数e:");
    for (int i = 0; i < n; i++) {
        scanf("%f,%d", &c, &e);
        Insert(&p1, c, e);
    }
    printf("输入多项式p2项数n:\n");
    scanf("%d", &n);
    printf("输入多项式系数c和指数e:");
    for (int i = 0; i < n; i++) {
        scanf("%f,%d", &c, &e);
        Insert(&p2, c, e);
    }

    int op;
    printf("多项式相加请输入1\n");
    printf("多项式相减请输入2\n");
    printf("多项式相乘请输入3\n");
    printf("退出输入0\n");

    scanf("%d", &op);
    switch (op) {
        case 1:
            p3 = addPloyn(p1, p2);
            printPloyn(p3);
            break;
        case 2:
            p3 = SubPloyn(p1, p2);
            printPloyn(p3);
            break;
        case 3:
            p3 = MultPloyn(p1, p2);
            printPloyn(p3);
            break;
        default:
            break;
    }
    free(p1);
    free(p2);
    free(p3);
    return 0;
}