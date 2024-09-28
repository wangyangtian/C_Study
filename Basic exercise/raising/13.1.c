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

void Premute(char* a, int start, int end) {
    if (start == end) {
         
    } else {
        for (int i = start; i <= end; i++) {
            swap(&a[i], &a[start]);
            Premute(a, start + 1, end);
            swap(&a[i], &a[start]);
        }
    }
}

int main() {
    return 0;
}