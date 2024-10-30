#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _Tree {
    int data;
    struct _Tree* lchild;
    struct _Tree* rchild;
} TNode, *Tree;

void visit(TNode* n) {
    printf("%d ", n->data);
}

void levelOrder(Tree t) {
    TNode* queue[MAXSIZE];
    int front = 0, rear = 0;
    queue[++rear] = t;

    while (front != rear) {
        front = (front + 1) % MAXSIZE;
        TNode* current = queue[front];

        if (current != NULL)
            visit(current);

        if (current->lchild != NULL) {
            rear = (rear + 1) % MAXSIZE;
            queue[rear] = current->lchild;
        }

        if (current->rchild != NULL) {
            rear = (rear + 1) % MAXSIZE;
            queue[rear] = current->rchild;
        }
    }
}

int main() {
    return 0;
}