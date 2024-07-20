#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAXSIZE 10 // 定义最大长度

// 顺序表的实现—————静态分配

typedef struct Sequence_list_static
{
    int data[MAXSIZE]; // 使用静态数组
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

void InitList(SqList *L)    //顺序表初始化
{ // 初始化一个顺序表
    for (size_t i = 0; i < MAXSIZE; i++)
        L->data[i] = 0; // 顺序表中数据元素默认初始值为0
    L->length = 0;      // 顺序表初始长度为0
}

bool ListInsert(SqList *L, int index, int elem) //  顺序表插入元素
{ // 顺序表的插入
    if (index > L->length || index < 1)
    {
        printf("插入位置超出表格！"); // 判断插入位置的合法性
        return false;
    }
    if (L->length >= MAXSIZE)
    {
        printf("表满，无法插入！");
        return false;
    }

    for (int i = L->length; i >= index; i--)
    {
        L->data[i] = L->data[i - 1]; // 插入位置及以后的元素右移一位
    }
    L->data[index - 1] = elem; // 插入elem
    L->length++;               //  表长+1
    return true;
}

int ListDelete(SqList *L, int index)        //顺序表删除元素
{
    if (index < 1 || index > L->length)     //判断删除位置是否合法
        return false;
    int temp = L->data[index - 1];          //保存被删除位置的值，用于返回
    for (int i = index; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];        //被删除位置之后的元素左移一位
    }
    L->length--;                            //表长-1
    return temp;
}

int GetElem(const SqList* L,int index){   //按位查找
    if (index < 1 || index > L->length)     //判断删除位置是否合法
        return false;
    return L->data[index-1];
}

int LocateElem(SqList* L,int elem){
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==elem)
        {
            printf("This element is located at %d.",i+1);
            return i+1;
        }
    }
    printf("Can not find it.");
        return -1;    
}

int main()
{
    SqList L1;
    InitList(&L1);
    L1.data[0] = 1;
    L1.data[1] = 5;
    L1.data[2] = 2;
    L1.data[3] = 7;
    L1.length = 4;
    ListInsert(&L1, 3, 2);
    for (int i = 0; i < L1.length; i++)
    {
        printf("%d ", L1.data[i]);
    }
    ListDelete(&L1, 5);
    printf("\n");
    for (int i = 0; i < L1.length; i++)
    {
        printf("%d ", L1.data[i]);
    }
    printf("\n");
    LocateElem(&L1,5);
    return 0;
}