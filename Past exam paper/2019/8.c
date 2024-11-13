#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 13
#define NULLKEY -32768

typedef struct HashTable {
    int *elem;
    int count;
} HashTable;

bool InitTable(HashTable *t) {
    t->count = HASHSIZE;
    t->elem = (int *)malloc(sizeof(int) * HASHSIZE);

    for (int i = 0; i < HASHSIZE; i++) {
        t->elem[i] = NULLKEY;
    }
}

int Hash(int key) {
    return key % 13;
}

void Insert(HashTable *t, int key) {
    int addr = Hash(key);
    while (t->elem[addr] != NULLKEY) {
        addr = (addr + 1) % HASHSIZE;
    }
    t->elem[addr] = key;
}

int Search(HashTable *t, int key) {
    int addr = Hash(key);
    while (t->elem[addr] != key) {
        addr = (addr + 1) % HASHSIZE;

        if (t->elem[addr] == NULLKEY || addr == Hash(key))
            return 0;
    }
    return addr;
}

int main() {
    return 0;
}