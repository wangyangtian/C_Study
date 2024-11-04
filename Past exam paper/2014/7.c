#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* MyStrcat(char* a, char* b) {
    char* d = a;
    while (*d != '\0') {
        d++;
    }
    while (*b != '\0') {
        *d = *b;
        d++;
        b++;
    }
    return d;
}

int main() {
    return 0;
}