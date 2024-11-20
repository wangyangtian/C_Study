#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct BTNode {
    int count;
    char word[MAXSIZE];
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode, *BTree;

BTNode *createNode(char *word) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->count = 1;
    strcpy(node->word, word);
    node->lchild = node->rchild = NULL;
    return node;
}

BTNode *insert(BTree t, char *word) {
    if (t == NULL) {
        return createNode(word);
    }
    int cmp = strcmp(word, t->word);
    if (cmp == 0) {
        t->count++;
    } else if (cmp < 0) {
        t->lchild = insert(t->lchild, word);
    } else {
        t->rchild = insert(t->rchild, word);
    }
    return t;
}

int extractWord(char *filepath, BTree *t) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("ERROR");
        return -1;
    }

    char temp[MAXSIZE];
    char c;
    int total = 0;
    int index = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c) || c == '-') {
            temp[index++] = c;
        } else if (index > 0) {
            temp[index] = '\0';
            *t = insert(*t, temp);
            total++;
            index = 0;
        }
    }
    fclose(fp);
    return total;
}

void printFreq(BTree t, int total) {
    if (t == NULL)
        return;
    printFreq(t->lchild, total);
    printf("%s的频率为%.2lf\n", t->word, (double)t->count / total);
    printFreq(t->rchild, total);
}

int main() {
    char path[] = "text.txt";
    BTree t = NULL;
    int total = extractWord(path, &t);

    if (total > 0) {
        printf("单词频率统计结果：\n");
        printFreq(t, total);
    } else {
        printf("未能统计单词频率。\n");
    }

    return 0;
}