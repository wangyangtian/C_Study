#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
typedef struct Single_linked_list // 定义单链表结点类型
{
    int data;                        // 每个节点存放一个数据元素
    struct Single_linked_list *next; // 指针指向下一个节点
} LNode, *LinkList;

// 强调这是一个单链表————使用 LinkList
// 强调这是一个结点————使用LNode*

// 等价写法
//  struct Single_linked_list
//  {
//      int data;
//      struct Single_linked_list* next;
//  };
//  typedef struct Single_linked_list LNode;
//  typedef struct Single_linked_list* LinkList;

// 不带头结点的初始化
//  bool InitList(LinkList *L)  //初始化一个空链表
//                              //注意！！传入的是L的地址，因为要将L指向的空间修改为NULL
//  {
//      L = NULL;
//      return true;
//  }

// 带头结点的初始化
bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
    if (*L == NULL)                      // 内存不足，分配失败
    {
        printf("内存空间不足，分配空间失败\n");
        return false;
    }
    (*L)->next = NULL; // 头结点之后暂时没有节点
    return true;
}

bool Empty(LinkList *L) // 判断是否为空表
{
    return (*L == NULL);
}

bool ListInsert(LinkList L, int index, int elem)    //按位序插入元素
{
    if (index < 1)
        return false;   //判断index是否合法
    LNode *p;
    p = L;              //当前p指向第几个节点
    int j = 0;          //L指向头结点，头结点是第0个结点(不存数据)
    while (p && j < index - 1)  // p != NULL && j < i - 1
    {   
        p = p->next;            //找到第i-1个节点，将p指向它
        j++;
    }
    if(p==NULL)  
        return false;
    LNode* s=(LNode*)malloc(sizeof(LNode)); //生成新节点
    s->data=elem;
    s->next=p->next;
    p->next=s;
    return true;
}

int main() {
    LinkList L;
    
    // 初始化链表
    if (InitList(&L)) {
        printf("链表初始化成功\n");
    } else {
        printf("链表初始化失败\n");
        return 0;
    }

    // 插入元素
    if (ListInsert(L, 1, 10)) {
        printf("元素插入成功\n");
    } else {
        printf("元素插入失败\n");
    }

    // 打印链表中的元素
    LinkList p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    // 释放链表内存
    while (L != NULL) {
        p = L;
        L = L->next;
        free(p);
    }

    return 0;
}
