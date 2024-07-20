#include "stdio.h"
#include <stdlib.h>

#define INITSIZE 10 // 默认最大长度

typedef struct Sequence_list_dynamic
{
    int *data;   // 动态分配数组指针
    int MaxSize; // 顺序表的最大容量
    int Length;  // 顺序表当前长度
} SqList;

void InitList(SqList *L)
{
    L->data = (int *)malloc(sizeof(int) * INITSIZE); // 申请默认长度的空间
    if (!L->data)
        exit(EXIT_FAILURE); // 判断初始化是否成功
    L->Length = 0;
    L->MaxSize = INITSIZE; // 初始表长为INITSIZE
}

void IncreaseSize(SqList *L, int AddLength)
{                                                                            // 增加动态数组长度
    L->data = (int *)realloc(L->data, sizeof(int) * (INITSIZE + AddLength)); // 将顺序表长度增加Addlength
    L->MaxSize += AddLength;                                                 // 顺序表最大长度增加Addlength
}
int main()
{
    SqList L;
    InitList(&L);
    L.data[1] = 1;
    printf("%d\n", L.data[1]);
    IncreaseSize(&L, 10);
    printf("%d\n", L.MaxSize);
    return 0;
}