#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestWord(char *s) {
    int len = 0, pos = -1;
    int maxlen = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            len++;
        } else {
            if (len > maxlen) {
                maxlen = len;
                pos = i - len;
            }
            len = 0;
        }
    }

    return pos;
}

int main() {
    char a[] = "In his art he broke the laws of scientific linear perspective.";
    printf("%d ", longestWord(a));
    return 0;
}