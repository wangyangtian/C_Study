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

bool IsEmpty(SqStack S)
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

void destroyStack(SqStack *s) {
    s->top = -1;
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

// 清空栈
void ClearStack(SqStack *s) {
    s->top = -1;
}

// 销毁栈（重置栈）
void DestroyStack(SqStack *s) {
    s->top = -1;
}

bool GetTop(SqStack *S, int *top)
{
    if (S->top == -1)
        return false;
    *top = S->data[S->top];
    return true;
}

// 打印栈元素
void PrintStack(SqStack *s) {
    if (IsEmpty(*s)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%c", s->data[i]);
        }
        printf("\n");
    }
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
            if(IsEmpty(S))   return false;

            char topelem;
            Pop(&S,&topelem);
            if(topelem!='('&&str[i]==')')   return false;
            if(topelem!='['&&str[i]==']')   return false;
            if(topelem!='{'&&str[i]=='}')   return false;
        }
        i++;
    }
    
    return IsEmpty(S);
}


void LineEdit() {
    SqStack s;
    InitStack(&s);
    char ch;

    printf("Enter text (use '#' to delete last character, '@' to clear the stack, and EOF to end):\n");
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            PrintStack(&s);  // 打印栈的内容作为测试
            ClearStack(&s);
        } else if (ch == '#') {
            char temp;
            Pop(&s, &temp);
        } else if (ch == '@') {
            ClearStack(&s);
        } else {
            Push(&s, ch);
        }
    }
}

void DecimalToOctal(int decimal) {
    SqStack stack;
    InitStack(&stack);
    
    while (decimal != 0) {
        int remainder = decimal % 8;
        Push(&stack, remainder);
        decimal = decimal / 8;
    }
    
    printf("八进制数为：");
    while (!IsEmpty(stack)) {
        int elem;
        Pop(&stack, &elem);
        printf("%d", elem);
    }
    printf("\n");
}

int main()
{
    SqStack S;
    InitStack(&S); // 初始化栈
    char str[]="{()}[]()";
    printf("%d",BracketCheck(str));
    return 0;
}