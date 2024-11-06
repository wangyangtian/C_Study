#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(const char *pw) {
    if (strlen(pw) <= 8)
        return false;
    int digit = 0;
    int low = 0;
    int high = 0;
    while (*pw != '\0') {
        if (isdigit(*pw)) {
            digit = 1;
            pw++;
        }

        if (isalpha(*pw)) {
            if (*pw >= 'A' && *pw <= 'Z') {
                high = 1;
                pw++;
            } else {
                low = 1;
                pw++;
            }
        }
    }
    if ((digit + low + high) < 2)
        return false;
    return true;
}

void reverse(char *str, int left, int right) {
    char temp;
    for (int i = left, j = right; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void encode(char *pw) {
    int len = strlen(pw);
    int n = len / 2 - 1;
    reverse(pw, n, len - n - 1);
    reverse(pw, 0, len - 1);
}

int main() {
    char str[] = "12345ABCD";
    encode(str);
    printf("%s", str);
    return 0;
}