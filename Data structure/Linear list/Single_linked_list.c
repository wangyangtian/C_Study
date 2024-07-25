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

bool Empty(LinkList L) // 判断是否为空表
{
    return (L->next == NULL);
}

// 带头结点的插入
bool ListInsert(LinkList L, int index, int elem) // 按位序插入元素
{
    if (index < 1)
        return false; // 判断index是否合法
    LNode *p;
    p = L;                     // 当前p指向第几个节点
    int j = 0;                 // L指向头结点，头结点是第0个结点(不存数据)
    while (p && j < index - 1) // p != NULL && j < i - 1
    {
        p = p->next; // 找到第i-1个节点，将p指向它
        j++;
    }
    // 后续操作等价指定结点的后插操作
    // 即return InsertNextNode(p,e);
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 生成新节点
    s->data = elem;
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头结点的插入
// bool ListInsert(LinkList L, int index, int elem)
// {
//     if (index < 1)
//         return false;
//     if (index == 1) // 插入第一个节点操作不同
//     {
//         LNode *s = (LNode *)malloc(sizeof(LNode));
//         s->next = L;
//         L = s;
//         return true;
//     }
//     LNode *p;
//     int j=1;    //没有头结点，p从第一个结点开始
//     // 后续一样
//     //...
// }

// 指定结点的后插操作
bool InsertNextNode(LNode *p, int elem)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = elem;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定结点的前插操作
// 时间复杂度为O(1)
// 虽然找不到p前面的结点，但是可以先将节点s插入p后，再交换p和s内data的内容
bool InsertPriorNode(LNode *p, int elem)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = elem;
    return true;
}

// 按位序删除
bool ListDelete(LinkList L, int index, int *elem)
{
    if (index < 1)
        return false;
    LNode *p;
    int j = 0; // 当前指向第几个节点
    p = L;
    while (p && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *q = p->next;
    *elem = q->data;
    p->next = q->next;
    free(q);
    return true;
    // *elem=p->next->data;
    // p->next=p->next->next;
    // 这种写法没有释放被删除结点的内存
}

// 指定节点的删除
// 偷天换日（类似于结点前插的实现）
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next; // 令q指向*p的后继结点
    p->data = q->data;  // 交换p和q指向节点的数据域
    p->next = q->next;  // 断开*q结点从链中断开
    free(q);            // 释放q所指空间，即删除结点的空间
    return true;
}
// ！！但是如果p是最后一个结点，会出现错误。
// 只能从表头开始依次寻找p的前驱,时间复杂度 O(n)

// 按位查找
LNode *GetElem(LinkList L, int index)
{
    if (index == 1)
        return L;
    if (index < 1)
        return NULL;
    LNode *p = L->next;
    int j = 1; // 当前指针p指向的是第j个节点
    while (p && j < index)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int elem)
{
    LNode *p = L->next;
    while (p && p->data != elem)
        p = p->next;
    return p;
}

//求表长度
int Length(LinkList L)
{
    LNode* p=L;
    int len=0;
    while (p->next)
    {
        p=p->next;
        len++;
    }
    return len;
}

//尾插法
LinkList List_TailInsert(LinkList L) {
    int x;
    int j = 1;
    LNode* r = L;
    printf("尾插法建立单链表,输入值(9999结束)\n");
    do {
        printf("输入第%d个数据:", j);
        scanf("%d", &x);
        if (x != 9999) {
            LNode* s = (LNode*)malloc(sizeof(LNode));
            if (s == NULL) {
                printf("内存分配失败\n");
                exit(1);
            }
            s->data = x;
            r->next = s;
            r = s;      // 更新尾指针
            j++;
        }
    } while (x != 9999);
    r->next=NULL;
    return L;  // 返回链表头指针
}

//头插法
LinkList List_HeadInsert(LinkList L){
    int x;
    int j = 1;
    LNode* r = L;
    printf("头插法建立单链表,输入值(9999结束)\n");
    do
    {
        printf("输入第%d个数据:", j++);
        scanf("%d", &x);
        if(x!=9999){
            LNode* s=(LNode*)malloc(sizeof(LNode));
            if (s == NULL) {
                printf("内存分配失败\n");
                exit(1);
            }
            s->data=x;
            s->next=r->next;
            r->next=s;
        } 
    } while (x!=9999);
}

// 打印链表
void PrintList(LinkList L) {
    LNode* temp = L->next;  // 跳过头节点
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表
void freeList(LinkList L) {
    LNode* temp;
    while (L != NULL) {
        temp = L;
        L = L->next;
        free(temp);
    }
}

bool DeleteDuplicates(LinkList* L){
    if((*L)->next==NULL||(*L)==NULL)    return false;   //链表为空或者只有一个元素返回false
    LNode* temp=(*L)->next;
    while (temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
            DeleteNode(temp);   //删除重复元素中的前一个
        else 
            temp=temp->next;    //如果不是重复元素，跳到下一个
    }
    return true;
}

bool DeleteMin(LinkList L){
    if(L==NULL)    return false;
    LNode* Current,*MinP;
    MinP=Current=L->next;
    while(Current!=NULL)
    {
        if(Current->data<MinP->data)
            MinP=Current;
        Current=Current->next;
    }
    DeleteNode(MinP);
    return true;
}

bool InplaceReverse(LinkList *L){
    if((*L)==NULL||(*L)->next==NULL)  return false;
    LNode *current;
    current=(*L)->next;
    (*L)->next=NULL;
    while (current!=NULL) 
    {
        LNode* temp=current->next;
        current->next=(*L)->next;
        (*L)->next=current;
        current=temp;
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
int main()
{
    LinkList L;

    // 初始化链表
    if (InitList(&L))
    {
        printf("链表初始化成功\n");
    }
    else
    {
        printf("链表初始化失败\n");
        return 0;
    }

    // // 插入元素
    // if (ListInsert(L, 1, 10))
    // {
    //     printf("元素插入成功\n");
    // }
    // else
    // {
    //     printf("元素插入失败\n");
    // }
    // ListInsert(L, 2, 9);
    // ListInsert(L, 1, 8);
    // ListInsert(L, 1, 7);
    // // 打印链表中的元素
    // LinkList p = L->next;
    // while (p != NULL)
    // {
    //     printf("%d ", p->data);
    //     p = p->next;
    // }

    // int x = GetElem(L, 2)->data;
    // printf("\n表中第二个元素为%d\n", x);

    // int length =Length(L);
    // printf("表长为%d\n",length);
    List_TailInsert(L);
    PrintList(L);
    //DeleteDuplicates(&L);
    //PrintList(L);
    //DeleteMin(L);
    //PrintList(L);
    InplaceReverse(&L);
    PrintList(L);
    freeList(L);
    return 0;
}
