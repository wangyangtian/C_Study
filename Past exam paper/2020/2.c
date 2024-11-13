#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strstr(char* haystack, char* neddle) {
    if (*neddle == '\0')
        return haystack;

    while (*haystack) {
        char* h = haystack;
        char* n = neddle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0')
            return haystack;

        haystack++;
    }
    return NULL;
}

int main() {
    return 0;
}