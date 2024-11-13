#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 13
#define NULLKEY -32768

typedef struct HashTable {
    int *elem;  // 数据元素存储基址，动态分配数组
    int count;  // 当前数据元素个数
} HashTable;

// 初始化散列表
bool InitHashTable(HashTable *h) {
    h->count = HASHSIZE;
    h->elem = (int *)malloc(HASHSIZE * (sizeof(int)));
    for (int i = 0; i < HASHSIZE; i++) {
        h->elem[i] = NULLKEY;
    }
    return true;
}

// 散列函数
int Hash(int key) {
    return key % 13;
}

void InsertHash(HashTable *h, int key) {
    int addr = Hash(key);
    while (h->elem[addr] != NULLKEY) {
        addr = (addr + 1) % HASHSIZE;
    }
    h->elem[addr] = key;
}

bool SearchHash(HashTable h, int key) {
    int addr = Hash(key);
    while (h.elem[addr] != key) {
        addr = (addr + 1) % HASHSIZE;
        // if(addr==Hash(key))
        //     break;
        // if(h.elem[addr]==key){
        //     return true;
        // }
        if (h.elem[addr] == NULLKEY || addr == Hash(key))
            return false;
    }
    return true;
}

int main() {
    return 0;
}