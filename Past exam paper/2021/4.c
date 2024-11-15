#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maxLenWord(char str[], char maxWord[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]))
            str[i] = ' ';
    }

    int maxlen = 0;
    char temp[100];
    while (sscanf(str, "%s", temp) == 1) {
        if (maxlen < strlen(temp)) {
            maxlen = strlen(temp);
            strcpy(maxWord, temp);
        }
        str += strlen(temp);
    }
}

int main() {
    char str[] = "a 88bbc eefg ccf";
    char max[100];
    maxLenWord(str, max);
    printf("%s", max);
    return 0;
}