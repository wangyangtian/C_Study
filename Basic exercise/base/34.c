#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int encode(int n) {
    char a[5];
    itoa(n, a, 10);
    for (int i = 0; i < 4; i++) {
        a[i] = (a[i] - '0' + 5) % 10 + '0';
    }
    swap(&a[0], &a[3]);
    swap(&a[1], &a[2]);
    return atoi(a);
}

int main() {
    int n = 1234;
    printf("%d", encode(n));
    return 0;
}