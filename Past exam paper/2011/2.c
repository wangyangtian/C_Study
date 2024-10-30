#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[], int pos) {
    if (str[pos] != '\0')
        reverse(str, pos + 1);
    printf("%c", str[pos]);
}

int main() {
    char str[100];
    printf("输入字符串：\n");
    scanf("%s", str);
    reverse(str, 0);
    return 0;
}