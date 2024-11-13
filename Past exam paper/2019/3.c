#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* MyStrncpy(char* dest, const char* src, int n) {
    char* d = dest;

    while (n > 0 && *src != '\0') {
        *d++ = *src++;
        n--;
    }

    while (n > 0) {
        *d++ = '\0';
        n--;
    }
    return dest;
}

int main() {
    char a[] = "qwert";
    char b[] = "12345";
    MyStrncpy(a, b, 3);
    printf("%s", a);
    return 0;
    return 0;
}