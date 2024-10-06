#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXSIZE 20

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;



bool isComplete(BTree t){
    if(!t)
        return true;
    BTNode* Queue[MAXSIZE];
    int front = 0, rear = 0;
    Queue[++rear] = t;

    bool encountNull = false;
    while(rear!=front){
        front = (front++) % MAXSIZE;
        BTNode* temp = Queue[front];

        if(temp){
            if(encountNull)
                return false;
            rear = (rear++) % MAXSIZE;
            Queue[rear] = temp->lchild;
            rear = (rear++) % MAXSIZE;
            Queue[rear] = temp->rchild;
        }
        else
            encountNull = true;
    }
    return true;
}


int main() {
    
    return 0;
}