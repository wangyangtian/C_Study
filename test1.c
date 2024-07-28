#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, char c)
{
    if (isFull(s))
    {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top];
}

bool IsOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
}

int precedence(char op){
    if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/')
        return 2;
    else if(op=='^')
        return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix){
    Stack s;
    initStack(&s);
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        if(isdigit(infix[i])||isalpha(infix[i]))
            postfix[j++]=infix[i];
        else if (infix[i]=='(')
        {
            push(&s,infix[i]);
        }
        else if (infix[i]==')')
        {
            while (!isEmpty(&s)&&peek(&s)!='(')
            {
                postfix[j++]=pop(&s);
            }
            pop(&s);//删除'('
        }
        else if(IsOperator(infix[i])){
            while (!isEmpty(&s)&&precedence(peek(&s))>=precedence(infix[i]))
            {
                postfix[j++]=pop(&s);
            }
            push(&s,infix[i]);
        }
        i++; 
    }
    while (!isEmpty(&s))
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
}

int EvaluatePostfix(char *postfix){
    Stack s;
    initStack(&s);
    int i=0;
    while (postfix[i]!='\0')
    {
        if(isdigit(postfix[i])){
            push(&s,postfix[i]='0');
        }
        else
        {
            char Rnum=pop(&s);
            char Lnum=pop(&s);
            double result;
            switch (postfix[i])
            {
            case '+':
                result=Lnum+Rnum;
                break;
            case '-':
                result=Lnum-Rnum;
                break;
            case '*':
                result=Lnum*Rnum;
                break;
            case '/':
                result=Lnum/Rnum;
                break;                
            default:
                break;
            }
            push(&s, result);            
        }
        i++;
    }
    return pop(&s); 
}

int main() {
    char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX];

    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    char test[]="21+32*1-*";
    printf("%d\n",EvaluatePostfix(test));
    return 0;
}
