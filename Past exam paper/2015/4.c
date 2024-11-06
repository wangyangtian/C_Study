#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isSymmetric(char *str) {
    char *front = str;
    char *rear = str + strlen(str) - 1;

    while (front < rear) {
        if (*front == *rear) {
            front++;
            rear--;
        } else
            return false;
    }
    return true;
}

int main() {
    char str1[] = "ababa";
    char str2[] = "abcd";
    char str3[] = "";

    printf("Is 'abba' symmetric? %s\n", isSymmetric(str1) ? "Yes" : "No");
    printf("Is 'abcd' symmetric? %s\n", isSymmetric(str2) ? "Yes" : "No");
    printf("Is empty string symmetric? %s\n", isSymmetric(str3) ? "Yes" : "No");

    return 0;
}