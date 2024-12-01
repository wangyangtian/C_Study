#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *MyStrncpy(char *strDes, const char *strSrc, int count) {
    char *src = strSrc;
    while (count > 0 && *src != '\0') {
        *(strDes++) = *(src++);
        count--;
    }
    while (count > 0) {
        *(strDes++) = '\0';
        count--;
    }
}

int main() {
    return 0;
}