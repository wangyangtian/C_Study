#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 顺序栈

#define MAXSIZE 10 // 定义栈中元素的最大个数

typedef struct Sequential_stack
{
    int data[MAXSIZE]; // 静态数组字放栈中元素
    int top;           // 栈顶指针
} SqStack;

void InitStack(SqStack *S)
{
    (*S).top = -1; // 初始化栈顶指针
}

bool EmptyStack(SqStack S)
{
    if (S.top == -1)
    {
        printf("栈空！");
        return true;
    }
    else
    {
        printf("非空栈！");
        return false;
    }
}

// 压栈操作
bool Push(SqStack *S, int elem)
{
    if (S->top == MAXSIZE - 1)
    {                 // 判断栈是否已满
        return false; // 栈满，无法压栈
    }
    S->data[++(S->top)] = elem; // 栈顶指针先加1，然后将元素压入栈顶
    return true;                // 压栈成功
}

// 出栈操作
bool Pop(SqStack *S, int *elem)
{
    if (S->top == -1)
    {                 // 判断栈是否为空
        return false; // 栈空，无法出栈
    }
    *elem = S->data[(S->top)--]; // 将栈顶元素赋值给elem，栈顶指针减1
    return true;                 // 出栈成功
}

bool GetTop(SqStack *S, int *top)
{
    if (S->top == -1)
        return false;
    *top = S->data[S->top];
    return true;
}

bool BracketCheck(char* str){
    SqStack S;
    InitStack(&S);
    int i=0;
    while (str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            Push(&S,str[i]);
        else
        {
            if(EmptyStack(S))   return false;

            char topelem;
            Pop(&S,&topelem);
            if(topelem!='('&&str[i]==')')   return false;
            if(topelem!='['&&str[i]==']')   return false;
            if(topelem!='{'&&str[i]=='}')   return false;
        }
        i++;
    }
    
    return EmptyStack(S);
}


int main()
{
    SqStack S;
    InitStack(&S); // 初始化栈
    char str[]="{()}[]()";
    printf("%d",BracketCheck(str));
    return 0;
}