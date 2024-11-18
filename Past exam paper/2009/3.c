#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxIndex(char str[]) {
    int maxindex = -1, maxlen = 0, len = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (isalpha(str[i])) {
            len++;
        } else {
            if (len > maxlen) {
                maxlen = len;
                maxindex = i - len;
            }
            len = 0;
        }
    }
    return maxindex;
}

int main() {
    char str[] = "aa bbc dc dddd";
    printf("%d", maxIndex(str));
    return 0;
}