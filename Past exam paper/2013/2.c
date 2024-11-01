#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyAtoi(char* nptr) {
    int result = 0;
    int flag = 0;
    if (*nptr == '-') {
        flag = -1;
        nptr++;
    } else
        flag = 1;
    while (*nptr != '\0') {
        int digit = *nptr - 48;
        result = result * 10 + digit;
        nptr++;
    }
    return result * flag;
}

int main() {
    char a[] = "-1234";
    printf("%d", MyAtoi(a));
    return 0;
}