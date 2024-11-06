#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct _String {
    char a[MAXSIZE];
    int len;
} String;

void getNext(String substr, int next[]) {
    int i = 1, j = 0;
    while (i < substr.len) {
        if (j == 0 || substr.a[i] == substr.a[j]) {
            i++ j++;
            next[i] = j;
        } else
            j = next[j];
    }
}

int KMP(String str, String substr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.len && j <= substr.len) {
        if (str.a[i] == substr.a[j]) {
            i++;
            j++;
        } else
            j = next[j];
    }
    if (i > substr.len)
        return i - substr.len;
    else
        return 0;
}

int main() {
    return 0;
}