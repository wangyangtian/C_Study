#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct Str {
    char a[MAXSIZE];
    int length;
} Str;

void getNext(const Str substr, int* next) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < substr.length) {
        if (j == 0 || substr.a[i] == substr.a[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMP(Str str, Str substr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length) {
        if (j == 0 || str.a[i] == substr.a[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (j > substr.length)
        return i - substr.length;
    else
        return 0;
}

int main() {
    Str str = {"ababcabcabababd", 15};
    Str substr = {"ababd", 5};
    int next[MAXSIZE];

    getNext(substr, next);

    int result = KMP(str, substr, next);
    if (result != 0) {
        printf("Pattern found at position %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}