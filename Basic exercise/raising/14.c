#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct String {
    char a[MAXSIZE];
    int length;
} String;

void next(const String substr, int* next) {
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

int KMP(String str, String substr, int next[]) {
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
