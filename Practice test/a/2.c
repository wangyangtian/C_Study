#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int inWord = 0;
    char c;
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    printf("%d\n", count);

    return 0;
}