#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrcmp(char *s1, char *s2) {
    while ((*s1) && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main() {
    return 0;
}