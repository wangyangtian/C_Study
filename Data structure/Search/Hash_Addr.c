#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct LNode
{
    int key;
    int value;
    struct LNode *next;
}LNode;

typedef struct HashTable{
    int size;
    LNode **firstNode;   //指向哈希表数组的指针，数组放的是LNode*
}HashTable;

int Hash(int key,int size){
    return key%size;
}

bool InitHash(HashTable *h,int size){
    h->size=size;
    h->firstNode=(LNode**)malloc(size*sizeof(LNode*));
    if(h->firstNode==NULL)
        return false;
    for(int i=0;i<size;i++){
        h->firstNode[i]=NULL;
    }
    return true;
}

// 插入数据到哈希表
void InsertHash(HashTable *h, int data) {
    int key = Hash(data, h->size);
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    newNode->key = key;
    newNode->value = data;
    newNode->next = NULL;

    // 插入到哈希表链表头部
    if (h->firstNode[key] == NULL) {
        h->firstNode[key] = newNode;
    } else {
        newNode->next = h->firstNode[key];
        h->firstNode[key] = newNode;
    }
}

// 在哈希表中搜索数据
LNode* SearchHash(HashTable h, int data) {
    int key = Hash(data, h.size);
    LNode *current = h.firstNode[key];
    while (current != NULL) {
        if (current->value == data)
            return current;
        current = current->next;
    }
    return NULL;
}

// 释放哈希表内存
void FreeHash(HashTable *h) {
    for (int i = 0; i < h->size; i++) {
        LNode *current = h->firstNode[i];
        while (current != NULL) {
            LNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(h->firstNode);
}

int main() {
 HashTable h;
    if (!InitHash(&h, 13)) {
        printf("初始化哈希表失败！\n");
        return -1;
    }

    // 插入数据
    InsertHash(&h, 15);
    InsertHash(&h, 25);
    InsertHash(&h, 35);

    // 搜索数据
    LNode *result = SearchHash(h, 35);
    if (result != NULL) {
        printf("找到节点，Key: %d, Value: %d\n", result->key, result->value);
    } else {
        printf("未找到节点。\n");
    }

    // 释放内存
    FreeHash(&h);

    return 0;
}