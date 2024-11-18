#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool SubString(char *s1, char *s2) {
    for (int i = 0; s1[i] != '\0'; i++) {
        int j = 0, start = i;
        while (s1[start] == s2[j]) {
            j++;
            start++;
        }
        if (s2[j] == '\0')
            return true;
    }
    return false;
}

int main() {
    char s1[] = "114514";
    char s2[] = "51";
    printf("%d", SubString(s1, s2));
    return 0;
}