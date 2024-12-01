#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int data;
    struct Tree *lchild, *rchild;
} TNode, *Tree;

#define MAXSIZE 100

int getHeight(Tree t) {
    if (t == NULL)
        return 0;                    // 空树高度为0
    int lh = getHeight(t->lchild);   // 左子树高度
    int rh = getHeight(t->rchild);   // 右子树高度
    return 1 + (lh > rh ? lh : rh);  // 返回较大的子树高度 + 1
}

int getWidth(Tree t) {
    if (t == NULL)
        return 0;
    int maxWidth = 0;
    TNode* queue[MAXSIZE];
    int rear = 0, front = 0;

    queue[++rear] = t;
    while (rear != front) {
        int currentWidth = (rear - front + MAXSIZE) % MAXSIZE;
        maxWidth = currentWidth > maxWidth ? currentWidth : maxWidth;

        for (int i = 0; i < currentWidth; i++) {
            front = (front++) % MAXSIZE;
            TNode* temp = queue[front];

            if (temp->lchild) {
                rear = (rear++) % MAXSIZE;
                queue[rear] = temp->lchild;
            }
            if (temp->rchild) {
                rear = (rear++) % MAXSIZE;
                queue[rear] = temp->rchild;
            }
        }
    }
    return maxWidth;
}

int lush(Tree t) {
    int height = getHeight(t);
    int width = getWidth(t);
    return height * width;
}

int main() {
    return 0;
}