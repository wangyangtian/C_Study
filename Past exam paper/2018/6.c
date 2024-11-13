#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_SIZE 100

typedef struct _Word {
    char word[MAX_LEN];
    int freq;
} Words;

typedef struct _WordSet {
    Words w[MAX_SIZE];
    int variety;
} WordSet;

void addToSet(char* word, WordSet* set) {
    for (int i = 0; i < set->variety; i++) {
        if (strcmp(word, set->w[i].word) == 0) {
            set->w[i].freq++;
            return;
        }
    }
    strcpy(set->w[set->variety].word, word);
    set->w[set->variety].freq = 1;
    set->variety++;
}

void splitStr(char* str, WordSet* set) {
    set->variety = 0;  // 初始化 variety 为 0

    char* word = strtok(str, " ");
    while (word != NULL) {
        addToSet(word, set);
        word = strtok(NULL, " ");
    }
}

int cmp(const void* a, const void* b) {
    Words* w1 = (Words*)a;
    Words* w2 = (Words*)b;
    return w2->freq - w1->freq;  // 按频率降序排序
}

int main() {
    char str[] = "abc abc abc ad ad abc gg";
    WordSet set;

    splitStr(str, &set);
    qsort(set.w, set.variety, sizeof(Words), cmp);

    for (int i = 0; i < set.variety; i++) {
        printf("freq of %s is %d\n", set.w[i].word, set.w[i].freq);
    }
    return 0;
}