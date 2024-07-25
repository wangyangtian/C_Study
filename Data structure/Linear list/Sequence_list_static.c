#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXSIZE 10 // 定义最大长度

// 顺序表的实现—————静态分配

typedef struct Sequence_list_static
{
    int data[MAXSIZE]; // 使用静态数组
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

void InitList(SqList *L) // 顺序表初始化
{                        // 初始化一个顺序表
    for (size_t i = 0; i < MAXSIZE; i++)
        L->data[i] = 0; // 顺序表中数据元素默认初始值为0
    L->length = 0;      // 顺序表初始长度为0
}

bool ListInsert(SqList *L, int index, int elem) //  顺序表插入元素
{                                               // 顺序表的插入
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

int ListDelete(SqList *L, int index) // 顺序表删除元素
{
    if (index < 1 || index > L->length) // 判断删除位置是否合法
        return false;
    int temp = L->data[index - 1]; // 保存被删除位置的值，用于返回
    for (int i = index; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i]; // 被删除位置之后的元素左移一位
    }
    L->length--; // 表长-1
    return temp;
}

int GetElem(const SqList *L, int index)
{                                       // 按位查找
    if (index < 1 || index > L->length) // 判断删除位置是否合法
        return false;
    return L->data[index - 1];
}

int LocateElem(SqList *L, int elem)
{ // 按值查找
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == elem)
        {
            printf("This element is located at %d.", i + 1);
            return i + 1;
        }
    }
    printf("Can not find it.");
    return -1;
}

bool ReverseList(SqList *L)
{ // 逆置矩阵
    int front = 0;
    int rear = L->length - 1;
    if (rear <= 0)
        return false;
    while (rear - front > 1)
    {
        int Temp = 0;
        Temp = L->data[front];
        L->data[front] = L->data[rear];
        L->data[rear] = Temp;
        front++;
        rear--;
    }
    return true;
}

bool ReversePList(int *arr, int left, int right) // 指定范围逆置
{
    int Temp = 0;
    while (right - left > 0)
    {
        Temp = arr[left];
        arr[left] = arr[right];
        arr[right] = Temp;
        left++;
        right--;
    }
    return true;
}

void MoveP(int *arr, int n, int p) // 将前p个元素平移至末尾
{
    ReversePList(arr, 0, p - 1);
    ReversePList(arr, p, n - 1);
    ReversePList(arr, 0, n - 1);
}

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void SortA1A2(int *a, int m, int n)
{             // 前面为m个有序元素，后面为n个有序元素
    int i, j; // 进行排序
    int temp;
    for (i = m; i < m + n; i++)
    {
        temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

void DeleteI2J(SqList *L, int i, int j)
{ // 删除下标i~j的元素
    while (j < L->length)
    {
        L->data[i++] = L->data[j++];
    }
    L->length = L->length + i - j - 1;
}

void SortByHead(SqList *L)
{
    int i = 1, j = L->length - 1;
    int temp;
    while (j > i)
    { 
        while (i < j && L->data[i] < L->data[0])
            i++;
        while (i < j && L->data[j] > L->data[0])
            j--;
        if (i < j)
        {
            temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
            i++;
            j--;
        }
    }
    if (L->data[0] > L->data[j])
    {
        temp = L->data[0];
        L->data[0] = L->data[j];
        L->data[j] = temp;
    }
}

int main()
{
    SqList L1;
    InitList(&L1);
    int a[] = {5, 6, 7, 8, 9, 4, 3, 2, 1};
    memcpy(L1.data, a, sizeof(a));
    L1.length = 9;
    // // ListInsert(&L1, 3, 2);
    // PrintList(L1);
    // // ListDelete(&L1, 5);
    // // LocateElem(&L1,5);
    // //ReverseList(&L1);
    // //PrintList(L1);
    // MoveP(L1.data, 9, 3);
    // // ReversePList(L1.data,0,);
    // PrintList(L1);
    // ReverseList(&L1);
    // PrintList(L1);
    // SortA1A2(L1.data,3,6);
    // PrintList(L1);
    // DeleteI2J(&L1,0,3);
    // PrintList(L1);
    PrintList(L1);
    SortByHead(&L1);
    PrintList(L1);
    return 0;
}
