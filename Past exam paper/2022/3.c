#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringcat(char* s1, char* s2, char* s3) {
    int slen1 = strlen(s1);
    int slen2 = strlen(s2);
    char* s = s3;
    if (slen1 < slen2) {
        while (*s1 != '\0') {
            *s3++ = *s1++;
        }
        while (*s2 != '\0') {
            *s3++ = *s2++;
        }
    } else {
        while (*s2 != '\0') {
            *s3++ = *s2++;
        }
        while (*s1 != '\0') {
            *s3++ = *s1++;
        }
    }
    *s3 = '\0';
    return s;
}

int main() {
    char s1[] = "1234";
    char s2[] = "abc";
    char s3[100];
    stringcat(s1, s2, s3);
    printf("%s", s3);
    return 0;
}