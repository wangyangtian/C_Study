#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Mystrcmp(const char *s, const char *t) {
    while (*s && *t) {
        if (*s != *t)
            return *s - *t;
        s++;
        t++;
    }
    return *s - *t;
}

int main() {
    const char s1[] = "qwer1";
    const char s2[] = "qwer";
    printf("%d", Mystrcmp(s1, s2));
    return 0;
}