#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct BTNode {
    int data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode, *BTree;

int Width(BTree t) {
    if (t == NULL)
        return 0;
    
    int maxWidth = 0;
    BTNode *queue[MAXSIZE];
    int rear = 0, front = 0;
    queue[++rear] = t;
    while(rear!=front){
        int currentWidth = rear - front;
        maxWidth = maxWidth > currentWidth ? maxWidth : currentWidth;
        while (currentWidth>0)
        {
            BTNode* temp = queue[++front];
            currentWidth--;
            if(temp->lchild)
                queue[++rear] = temp->lchild;
            if(temp->rchild)
                queue[++rear]=temp->rchild;
        }
    }
    return Width;
}

int main() {
    return 0;
}