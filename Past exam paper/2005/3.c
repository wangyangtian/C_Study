#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maxSubString(char *s1, char *s2) {
    int maxlength = 0;
    int pos1 = -1;
    int pos2 = -1;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i < len1; i++) {
        for (int j = i + 1; j < len1; j++) {
            int currentlength = j - i + 1;

            if (currentlength < maxlength)
                continue;

            char substr[currentlength];
            strncpy(substr, s1 + i, currentlength);
            substr[currentlength] = '\0';

            if (strstr(s2, substr) != NULL) {
                maxlength = currentlength;
                pos1 = i;
                pos2 = strstr(s2, substr) - s2;
            }
        }
    }

    printf("最长公共子串长度为%d\n", maxlength);
    printf("最长子串在s1中的起始位置为%d\n", pos1);
    printf("最长子串在s2中的起始位置为%d\n", pos2);
}

int main() {
    char *s1 = "abcdefg";
    char *s2 = "xyzabcm";

    maxSubString(s1, s2);

    return 0;
}
